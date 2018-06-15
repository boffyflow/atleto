<?php

	require $_SERVER[ 'DOCUMENT_ROOT'] . "/php/global_inc.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/run.php";
	
	date_default_timezone_set('America/Los_Angeles');
	
	function number_pad( $number, $n)
	{
		return str_pad( ( int) $number, $n, "0", STR_PAD_LEFT);
	}
	
	function numRuns()
	{
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);

        return $db->querySingle( "select count(day) from runs");
	}

	function totalTime( $time, $abbrev = false)
	{
		$values = secondsToTime( $time);
		
		if( $abbrev == true)
		{
			if( ( $values['d'] == 0) && ( $values['h'] > 0))
				return $values['h'] . ":" . number_pad( $values['m'], 2)  . ":" . number_pad( $values['s'], 2);
			else if( ( $values['d'] == 0) && ( $values['h'] == 0))
				return $values['m'] . ":" . number_pad( $values['s'], 2);
		}
		else
		{
			if( $values['d'] == 0)
				return $values['h'] . " hours " . $values['m'] . " minutes " . $values['s'] . " seconds";
			
			return $values['d'] . " days " . $values['h'] . " hours " . $values['m'] . " minutes " . $values['s'] . " seconds";
		}
	}

	function totalPace()
	{
		$dist = totals( 'dist') * 0.001;
		$t = totals( 't');
		
		$values = secondsToTime( $t / $dist);
		if( $values['s'] < 10)
			return $values['m'] . ":0" . $values['s'] . " min/km";
		else
			return $values['m'] . ":" . $values['s'] . " min/km";	
	}
	
	function totals( $property)
	{
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);
			
		$result = $db->querySingle( "select sum(" . $property . ") from run_splits");
								
		return $result;
	}
	
	function total( $fd, $ld, $property)
	{
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);

		$firstDay = new DateTime( $fd);
		$lastDay = new DateTime( $ld);
		
		$jd1 = gregoriantojd( $firstDay->format('n'), $firstDay->format('j'), $firstDay->format('Y'));
		$jd2 = gregoriantojd( $lastDay->format('n'), $lastDay->format('j'), $lastDay->format('Y'));
		
		$result = $db->query( "select sum(" . $property . ") from run_splits where run_id in (select id from runs where day >=" . $jd1 .
								" and day <=" . $jd2 . ")");
								
		$row = $result->fetchArray();
		$db->close();

		return $row[0];
	}

	/* Average heartrate weighted by time */
	function heartrate( $fd, $ld)
	{
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);

		$firstDay = new DateTime( $fd);
		$lastDay = new DateTime( $ld);
		
		$jd1 = gregoriantojd( $firstDay->format('n'), $firstDay->format('j'), $firstDay->format('Y'));
		$jd2 = gregoriantojd( $lastDay->format('n'), $lastDay->format('j'), $lastDay->format('Y'));
		
		$result = $db->query( "select hr,t from run_splits where run_id in (select id from runs where day >=" . $jd1 .
								" and day <=" . $jd2 . ")");
								
		$avehr = 0.0;
		$totalt = 0;
		if( $result->numColumns() > 0)
		{			
			while( $row = $result->fetchArray())
			{
				$avehr = $avehr + ( $row['hr'] * $row['t']);
				$totalt = $totalt + $row['t'];
			}
			if( $totalt > 0)
				$avehr = $avehr / $totalt;
		}
		$db->close();

		return $avehr;
	}

	function weight( $fd, $ld, $property)
	{
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);

		$firstDay = new DateTime( $fd);
		$lastDay = new DateTime( $ld);
		
		$jd1 = gregoriantojd( $firstDay->format('n'), $firstDay->format('j'), $firstDay->format('Y'));
		$jd2 = gregoriantojd( $lastDay->format('n'), $lastDay->format('j'), $lastDay->format('Y'));
		
		$result = $db->querySingle( "select " . $property . "(weight) from physicals where day >=" . $jd1 . " and day <=" . $jd2 . " and weight > 0.0");

		$db->close();

		return $result;
	}
	
	function secondsToTime( $inputSeconds)
	{
		$secondsInAMinute = 60;
		$secondsInAnHour  = 60 * $secondsInAMinute;
		$secondsInADay    = 24 * $secondsInAnHour;

		// extract days
		$days = floor($inputSeconds / $secondsInADay);

		// extract hours
		$hourSeconds = $inputSeconds % $secondsInADay;
		$hours = floor($hourSeconds / $secondsInAnHour);

		// extract minutes
		$minuteSeconds = $hourSeconds % $secondsInAnHour;
		$minutes = floor($minuteSeconds / $secondsInAMinute);

		// extract the remaining seconds
		$remainingSeconds = $minuteSeconds % $secondsInAMinute;
		$seconds = ceil($remainingSeconds);

		// return the final array
		$obj = array(
			'd' => (int) $days,
			'h' => (int) $hours,
			'm' => (int) $minutes,
			's' => (int) $seconds,
		);
		
		return $obj;
	}	
	
	function searchRuns( $location, $limit)
	{
		if( $location != "")
		{
			global $dbfilename;
			
			$db = new SQLite3( $dbfilename);

			$results = $db->query( "select id from runs where location_id in (select id from locations where name like '%" . 
				$location . "%') order by day desc limit " . $limit);
			
			$alt = true;
			
			echo "<tr><th>Date</th><th>Location</th><th>Distance</th><th>Time</th><th>Pace</th></tr>";
			
			while( $row = $results->fetchArray())
			{
				$run = new Run( $row[0]);
				if( $alt == false)
					echo "<tr><td><a href=\"/php/day_report.php?currentDay=" . $run->day()->format( 'Y-m-d') . "\">";
				else
					echo "<tr class=\"alt\"><td><a href=\"/php/day_report.php?currentDay=" . $run->day()->format( 'Y-m-d') . "\">";
				$alt = !$alt;
				echo $run->day()->format( 'D, M d, Y');
				echo "</a></td><td><a id=\"" . $row[0] . "\" href=\"search_results.php?searchLocation=" . $location . "&currentRunId=" . $row[0] . "#RunInfo\">";
				echo $run->location();
				echo "</a></td><td>";
				echo $run->distance_string();
				echo "</td><td>";
				echo $run->time_string();
				echo "</td><td>";
				echo $run->pace_string();
				echo "</td></tr>\n";
			}			
		}
	}
	
	function lastRuns( $numRuns)
	{
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);

		$results = $db->query( "select id from runs order by day desc limit " . $numRuns);
		$alt = true;
		
		echo "<tr><th>Date</th><th>Location</th><th>Distance</th><th>Time</th><th>Pace</th><th>Type of Run</th><th>Time of Day</th></tr>";
		
		while( $row = $results->fetchArray())
        	{
			$run = new Run( $row[0]);
			
			switch( $run->runtype())
			{
				case "easy":
				case "recovery":
					$tcolor = "orange1";
					break;
				case "hills":
				case "long run":
				case "interval":
				case "threshold":
				case "tempo":
				case "marathon pace":
					$tcolor = "orange3";
					break;
				case "race":
					$tcolor = "orange4";
					break;
				default:
					$tcolor = "orange2";
					break;
			}

			echo "<tr class=\"" . $tcolor . "\"><td><a href=\"/php/day_report.php?currentDay=" . $run->day()->format( 'Y-m-d') . "\">";			
			echo $run->day()->format( 'D, M d');
			echo "</a></td><td><a id=\"" . $row[0] . "\" href=\"/index.php?currentRunId=" . $row[0] . "#RunInfo\">";
			echo $run->location();
			echo "</a></td><td>";
			echo $run->distance_string();
			echo "</td><td>";
			echo $run->time_string();
			echo "</td><td>";
			echo $run->pace_string();
			echo "</td><td>";
			echo $run->runtype();
			echo "</td><td>";
			echo $run->run_tod();
			echo "</td></tr>\n";
       		}		
	}
	
?>