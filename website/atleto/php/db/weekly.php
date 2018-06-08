<?php

	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/global_inc.php";
	
	function weekToDate( $week)
	{
		global $timezone;
	
		$day = new DateTime( 'now', $timezone);
		
		$weekNumber = substr( $week, -2);
		$year = substr( $week, 0, 4);
		
		$day->setISODate( (int) $year, (int) $weekNumber);
		
		return $day;
	}
	
	function firstWeek( $numWeeks)
	{
		global $timezone;

		$day = new DateTime( 'now', $timezone);
		
		$day->modify( '-' . $numWeeks . ' weeks');
		
		$day->modify( '+' . 6 . ' days');
		
		return $day->format( 'Y') . '-W' . $day->format ('W'); 
	}
	
	function lastWeek()
	{
		global $timezone;

		$day = new DateTime( 'now', $timezone);
			
		return $day->format( 'Y') . '-W' . $day->format ('W'); 
	}
	
	function weeks( $firstWeek, $lastWeek)
	{
		$weeks = array();
		$lastDay = weekToDate( $lastWeek);
		$lastDay->modify( '+6 days');
		
		$firstDay = weekToDate( $firstWeek);
		
		while( $firstDay < $lastDay)
		{
			array_push( $weeks, $firstDay->format( 'M d') . ' - ' . $firstDay->modify( '+6 days')->format( 'M d'));
			$firstDay->modify( '+1 day');
		}
		
        return $weeks;
	}
	
	function distances( $firstWeek, $lastWeek)
	{
		$dist = array();
		
		$lastDay = weekToDate( $lastWeek);
		$lastDay->modify( '+6 days');
		
		$firstDay = weekToDate( $firstWeek);
		
		while( $firstDay < $lastDay)
		{
			$ld = clone $firstDay;
			$ld->modify( '+6 days');			
			
			$d = round( total( $firstDay->format('Y-M-d'), $ld->format('Y-M-d'), 'dist') * 0.001, 1);
			if( $d < 0.2)
				$d = NULL;
			
			array_push( $dist, $d);
			
			$firstDay->modify( '+7 days');
		}
		
		return $dist;
	}
	
	function paces( $firstWeek, $lastWeek)
	{
		$paces = array();
		
		$lastDay = weekToDate( $lastWeek);
		$lastDay->modify( '+6 days');
		
		$firstDay = weekToDate( $firstWeek);
		
		while( $firstDay < $lastDay)
		{
			$ld = clone $firstDay;
			$ld->modify( '+6 days');			
			
			$distance = total( $firstDay->format('Y-M-d'), $ld->format('Y-M-d'), "dist") * 0.001;
            if( $distance < 0.01)
            {
                $pace = NULL;
			}
			else
			{
                $pace = round( total( $firstDay->format('Y-M-d'), $ld->format('Y-M-d'), "t") / $distance);
			}
						
			array_push( $paces, $pace);
			
			$firstDay->modify( '+7 days');
		}
		
		return $paces;
	}
	
	function minpace( $firstWeek, $lastWeek)
	{
		$paces = paces( $firstWeek, $lastWeek);
		
		$minvalue = 10000.0;
		for( $i = 0; $i < count($paces); $i++)
		{
			if( $paces[$i] < $minvalue && $paces[$i] > 1.0)
				$minvalue = $paces[$i];
		}
		
		return round( floor( $minvalue * 0.1) * 10.0);
	}

	function weights( $firstWeek, $lastWeek, $property)
	{
        $ave_w = array();

		$lastDay = weekToDate( $lastWeek);
		$lastDay->modify( '+6 days');
		
		$firstDay = weekToDate( $firstWeek);
		
		while( $firstDay < $lastDay)
		{
			$ld = clone $firstDay;
			$ld->modify( '+6 days');			
			
			$w = round( weight( $firstDay->format('Y-M-d'), $ld->format('Y-M-d'), $property) * 0.001, 1);
						
			array_push( $ave_w, $w);
			
			$firstDay->modify( '+7 days');
		}

		return $ave_w;
	}
	
	function minweight( $firstWeek, $lastWeek)
	{
		$weights = weights( $firstWeek, $lastWeek, 'min');
		
		$minvalue = 1000.0;
		for( $i = 0; $i < count($weights); $i++)
		{
			if( $weights[$i] < $minvalue && $weights[$i] > 0.001)
				$minvalue = $weights[$i];
		}
		
		return round( floor( $minvalue * 0.1) * 10.0);
	}	
	
?>    