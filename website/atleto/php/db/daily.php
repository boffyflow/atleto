<?php

	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/global_inc.php";
	
	function getFirstAndLast()
	{
		global $timezone;
	
		$fandl = array();
		
		$lastDay = new DateTime( 'now', $timezone);
		$firstDay = clone $lastDay;
		$firstDay->modify( "-30 days");
		
		$range_select = 1;
		$numRange = 30;
		$whichRange = "Days";
		$fixedRange = "this_month";
		$customFirst = $firstDay;
		$customLast = $lastDay;
				
		if( isset( $_POST[ "range_select"]))
			$range_select = $_POST[ "range_select"];
		if( isset( $_POST[ "numRange"]))
			$numRange = $_POST[ "numRange"];
		if( isset( $_POST[ "whichRange"]))
			$whichRange = $_POST[ "whichRange"];
		if( isset( $_POST[ "fixedRange"]))
			$fixedRange = $_POST[ "fixedRange"];
		if( isset( $_POST[ "customFirst"]))
			$customFirst = $_POST[ "customFirst"];
		if( isset( $_POST[ "customLast"]))
			$customLast = $_POST[ "customLast"];
		
		if( $range_select == 1)
		{	
			$firstDay = new DateTime( 'now', $timezone);
			$firstDay->modify( "-" . $numRange . " " . $whichRange);
		}			
		if( $range_select == 2)
		{
			$firstDay = new DateTime( 'now', $timezone);
		
			if( $fixedRange == "this_week")
			{
				$firstDay->modify( "Monday this week");
				$lastDay->modify( "Sunday this week");
			}
			else if( $fixedRange == "this_month")
			{
				$firstDay->modify( "first day of this month");
				$lastDay->modify( "last day of this month");
			}
			else if( $fixedRange == "this_year")
			{
				$firstDay->modify( "first day of January");
				$lastDay->modify( "last day of December");
			}
			else if( $fixedRange == "last_week")
			{
				$firstDay->modify( "Monday last week");
				$lastDay->modify( "Sunday last week");
			}
			else if( $fixedRange == "last_month")
			{
				$firstDay->modify( "first day of last month");
				$lastDay->modify( "last day of last month");
			}
			else if( $fixedRange == "last_year")
			{
				$y = (int) $firstDay->format( 'Y') - 1;
				$firstDay->setDate( $y, 1, 1);
				$lastDay->setDate( $y, 12, 31);
			}
		}
		if( $range_select == 3)
		{
			$firstDay = DateTime::createFromFormat( 'Y-m-d', $customFirst);
			$lastDay = DateTime::createFromFormat( 'Y-m-d', $customLast);
		}

//		echo "first day: " . $firstDay->format( 'Y-m-d') . "<br>";
//		echo "last day:  " . $lastDay->format( 'Y-m-d');
		
		array_push( $fandl, $firstDay);
		array_push( $fandl, $lastDay);
		
		return $fandl;
	}
		
	function isItemSelected( $combo, $item)
	{
		if( $combo == "whichRange")
		{
			if( isset( $_POST[ "whichRange"]))
			{
				if( $item == $_POST[ "whichRange"])
				{
					echo "selected=\"selected\"";
				}
			}
			else
			{
				if( $item == "days")
				{
					echo "selected=\"selected\"";
				}
			}
		}
		if( $combo == "fixedRange")
		{
			if( isset( $_POST[ "fixedRange"]))
			{
				if( $item == $_POST[ "fixedRange"])
				{
					echo "selected=\"selected\"";
				}
			}
			else
			{
				if( $item == "this_month")
				{
					echo "selected=\"selected\"";
				}
			}
		}
	}

	function customDate( $forl)
	{
		global $timezone;
	
		$d = new DateTime( 'now', $timezone);
	
		if( $forl == "first")
		{
			if( isset( $_POST[ "customFirst"]))
			{
				echo $_POST[ "customFirst"];
			}
			else
			{
				echo $d->modify( "-30 days")->format( 'Y-m-d');
			}
		}
		else if( $forl == "last")
		{
			if( isset( $_POST[ "customLast"]))
			{
				echo $_POST[ "customLast"];
			}
			else
			{
				echo $d->format( 'Y-m-d');
			}
		}
	}

	function radioState()
	{
		if( isset( $_POST[ "range_select"]))
			return $_POST[ "range_select"];
		else
			return 1;
	}	
	
	function isChecked( $radioButton)
	{
		if( isset( $_POST[ "range_select"]))
		{
			if( $radioButton == $_POST[ "range_select"])
			{
				echo "checked=\"checked\"";
			}
		}
		else
		{
			if( $radioButton == 1)
				echo "checked=\"checked\"";
		}
	}
	
	function days( $firstDay, $lastDay)
	{
		$days = array();
		$counter = clone $firstDay;
		
		while( $counter <= $lastDay)
		{
			array_push( $days, $counter->format( 'D M d'));
			$counter->modify( '+1 day');
		}
		
        return $days;
	}
	
	function distances( $firstDay, $lastDay)
	{
		$dist = array();
		
		$counter = clone $firstDay;
		
		while( $counter <= $lastDay)
		{
			$d = round( total( $counter->format('Y-M-d'), $counter->format('Y-M-d'), 'dist') * 0.001, 1);
			if( $d < 0.2)
				$d = NULL;
		
			array_push( $dist, $d);			
			$counter->modify( '+1 days');
		}
		
		return $dist;
	}
	
	function paces( $firstDay, $lastDay)
	{
		$paces = array();
		
		$counter = clone $firstDay;
		
		while( $counter <= $lastDay)
		{		
			$distance = total( $counter->format('Y-M-d'), $counter->format('Y-M-d'), "dist") * 0.001;
            if( $distance < 0.01)
            {
                $pace = NULL;
			}
			else
			{
                $pace = round( total( $counter->format('Y-M-d'), $counter->format('Y-M-d'), "t") / $distance);
			}
						
			array_push( $paces, $pace);
			
			$counter->modify( '+1 days');
		}
		
		return $paces;
	}
	
	function minpace( $firstDay, $lastDay)
	{
		$paces = paces( $firstDay, $lastDay);
		
		$minvalue = 10000.0;
		for( $i = 0; $i < count($paces); $i++)
		{
			if( $paces[$i] < $minvalue && $paces[$i] != NULL)
				$minvalue = $paces[$i];
		}
		
		return round( floor( $minvalue * 0.1) * 10.0);
	}
	
	function weights( $firstDay, $lastDay)
	{
        $ave_w = array();

		$counter = clone $firstDay;

		while( $counter <= $lastDay)
		{			
			$w = round( weight( $counter->format('Y-M-d'), $counter->format('Y-M-d'), 'avg') * 0.001, 1);
			if( $w < 1.0)
				$w = NULL;
			
			array_push( $ave_w, $w);
			
			$counter->modify( '+1 days');
		}

		return $ave_w;
	}
	
	function minweight( $firstDay, $lastDay)
	{
		$weights = weights( $firstDay, $lastDay, 'avg');
		
		$minvalue = 1000.0;
		for( $i = 0; $i < count($weights); $i++)
		{
			if( $weights[$i] < $minvalue && $weights[$i] > 0.001)
				$minvalue = $weights[$i];
		}
		
		// return round( floor( $minvalue * 0.1) * 10.0);
		return floor( $minvalue);
	}	
	
	function sma( $firstDay, $lastDay, $length)
	{
		$numberDays = count( days( $firstDay, $lastDay));
		
		$firstDay->modify( "-" . $length - 1 . " days");
		
		$weights = weights( $firstDay, $lastDay);
		
		$trend = array();
		
		for( $i = 0; $i < $numberDays; $i++)
		{
			$tmp = array_slice( $weights, $i, 3);
			$t = array_sum( $tmp) / count( $tmp); 
			
			array_push( $trend, round( $t, 1));
		}
		
		return $trend;
	}
	
?>    