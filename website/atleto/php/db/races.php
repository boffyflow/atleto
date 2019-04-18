<?php

	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/global_inc.php";
	
	function isItemSelected( $combo, $item)
	{
		if( $combo == "raceYear")
		{
			if( isset( $_GET[ "raceYear"]))
			{
				if( $item == $_GET[ "raceYear"])
				{
					echo "selected=\"selected\"";
				}
			}
			else
			{
				if( $item == "All")
				{
					echo "selected=\"selected\"";
				}
			}
		}
	}
	
	function race_ids( $year)
	{
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);

		$ids = array();
		
		$y1 = $year;
		$y2 = $year;
		if( $year == 'All')
		{
			$y1 = 1900;
			$y2 = 2100;
		}
		
		$fd = cal_to_jd( CAL_GREGORIAN, 1, 1, $y1);
		$ld = cal_to_jd( CAL_GREGORIAN, 12, 31, $y2);
		
		$result = $db->query( "select id from runs where day <=" . $ld . " and day >= " . $fd .
							  " and id in (select run_id from run_races) order by day desc");
		
		while( $row = $result->fetchArray())
		{
			array_push( $ids, $row[0]);
		}
		
		return $ids;
	}
	
	function races( $year)
	{
		global $dbfilename;
		$db = new SQLite3( $dbfilename);
	
		$race_ids = race_ids( $year);
		$alt = true;
		
		echo "<tr><th>Date</th><th>Race</th><th>Distance</th><th>Gun Time</th><th>Pace</th><th>Chip Time</th><th>Overall</th><th>Age Group</th><th>Percentile</th></tr>";
		
		foreach( $race_ids as $value)
        {
			$result = $db->querySingle( "select name,chiptime,pl_overall,num_overall,pl_division,num_division from run_races where run_id=" . $value, true);
		
			$run = new Run( $value);
			if( $alt == false)
				echo "<tr><td>";
			else
				echo "<tr class=\"alt\"><td>";
			$alt = !$alt;
			echo $run->day()->format( 'M d, Y');
			echo "</td><td><a id=\"" . $value . "\" href=\"/php/races_report.php?raceYear=" . $year . "&currentRunId=" . $value . "#RunInfo\">";
			echo $result['name'];
			echo "</a></td><td>";
			echo $run->distance_string();
			echo "</td><td>";
			echo $run->time_string();
			echo "</td><td>";
			echo $run->pace_string();
			echo "</td><td>";
			echo totalTime( $result['chiptime'], true);
			echo "</td><td>";
			echo $result['pl_overall'] . "/" . $result['num_overall'];
			echo "</td><td>";
			echo $result['pl_division'] . "/" . $result['num_division'];
			echo "</td><td>";
			$agp = (float) $result['pl_division'];
			$agn = (float) $result['num_division'];
			echo round( 100.0 * $agp / $agn, 1) . " %";
			echo "</td></tr>\n";
        }

		return count( $race_ids);
	}
	
?>    