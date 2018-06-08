<?php

	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/global_inc.php";
	
	function months( $numMonths)
    {
		global $timezone;

        $months = array();

		$day = new DateTime( 'now', $timezone);
		
		array_push( $months, $day->format( 'M Y'));
		
		for( $i = 0; $i < $numMonths - 1; $i++)
		{
			$day->modify( 'first day of previous month');
			array_unshift( $months, $day->format( 'M Y'));
		}
        
        return $months;
    }	
	
	function distances( $numMonths)
	{
		$m = months( $numMonths);
		$dist = array();
		
		foreach ( $m as $value)
		{
			$fd = DateTime::createFromFormat( 'd M Y', strval(1).$value);
			$ld = clone $fd;
			$ld->modify( 'last day of this month');
			
			$d = round( total( $fd->format('Y-M-d'), $ld->format('Y-M-d'), 'dist') * 0.001);
			if( $d < 2.0)
				$d = NULL;
			
			array_push( $dist, $d);
		}
		
		return $dist;
	}
	
	function paces( $numMonths)
    {   
		$m = months( $numMonths);
        $p = array();
        
		foreach( $m as $value)
		{
			$fd = DateTime::createFromFormat( 'd M Y', strval(1).$value);
			$ld = clone $fd;
			$ld->modify( 'last day of this month');
		
			$distance = total( $fd->format('Y-M-d'), $ld->format('Y-M-d'), "dist") * 0.001;
            if( $distance < 0.01)
            {
                $pace = NULL;
			}
			else
			{
                $pace = round( total( $fd->format('Y-M-d'), $ld->format('Y-M-d'), "t") / $distance);
			}
			array_push( $p, $pace);
		}
		
		return $p;
    }
	
	function monthly_weights( $numMonths, $property)
	{
		$m = months( $numMonths);
        $ave_w = array();
        
		foreach( $m as $value)
		{
			$fd = DateTime::createFromFormat( 'd M Y', strval(1).$value);
			$ld = clone $fd;
			$ld->modify( 'last day of this month');
		
            $w = round( weight( $fd->format('Y-M-d'), $ld->format('Y-M-d'), $property) * 0.001, 1);
			
			array_push( $ave_w, $w);
		}
		
		return $ave_w;
	}
	
	function minweight( $numMonths)
	{
		$weights = monthly_weights( $numMonths, 'min');
		
		$minvalue = 1000.0;
		for( $i = 0; $i < count($weights); $i++)
		{
			if( $weights[$i] < $minvalue && $weights[$i] > 0.001)
				$minvalue = $weights[$i];
		}
		
		return round( floor( $minvalue * 0.1) * 10.0);
	}
	
	function minpace( $numMonths)
	{
		$paces = paces( $numMonths);
		
		$minvalue = 10000.0;
		for( $i = 0; $i < count($paces); $i++)
		{
			if( $paces[$i] < $minvalue && $paces[$i] > 1.0)
				$minvalue = $paces[$i];
		}
		
		return round( floor( $minvalue * 0.1) * 10.0);
	}	
	
?>    