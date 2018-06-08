<?php

	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/global_inc.php";
	
	function years( $firstYear, $lastYear)
    {
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);

        $results = $db->query( "select day from runs");
       
        $years = array();
        while( $row = $results->fetchArray())
        {
            $day = cal_from_jd($row[0], CAL_GREGORIAN);
            $y = $day['year'];
			if( $y >= $firstYear && $y <= $lastYear)
			{
				if( !in_array( $y, $years))
				{
					array_push( $years, $y);
				}
			}
        }
        
        return $years;
    }
	
	function distances( $firstYear, $lastYear)
	{
		$y = years( $firstYear, $lastYear);
		$dist = array();
		
		foreach ( $y as $value)
		{
			$fd = strval($value).'-01-01';
			$ld = strval($value).'-12-31';
				
			array_push( $dist, round( total( $fd, $ld, 'dist') * 0.001));
		}
		
		return $dist;
	}
	
	function paces( $firstYear, $lastYear)
    {   
        $y = years( $firstYear, $lastYear);
        $p = array();
        
		foreach( $y as $value)
		{
			$fd = strval($value).'-01-01';
			$ld = strval($value).'-12-31';
		
			$distance = total( $fd, $ld, "dist") * 0.001;
            if( $distance < 0.01)
            {
                $pace = 0.0;
			}
			else
			{
                $pace = round( total( $fd, $ld, "t") / $distance);
			}
			array_push( $p, $pace);
		}
		
		return $p;
    }
	
	function yearly_weights( $firstYear, $lastYear, $property)
	{
		$y = years( $firstYear, $lastYear);
        $ave_w = array();
        
		foreach( $y as $value)
		{
			$fd = strval($value).'-01-01';
			$ld = strval($value).'-12-31';
		
            $w = round( weight( $fd, $ld, $property) * 0.001, 1);
			
			array_push( $ave_w, $w);
		}
		
		return $ave_w;
	}
	
	function minweight( $firstYear, $lastYear)
	{
		$weights = yearly_weights( $firstYear, $lastYear, 'min');
		
		$minvalue = 1000.0;
		for( $i = 0; $i < count($weights); $i++)
		{
			if( $weights[$i] < $minvalue && $weights[$i] > 0.001)
				$minvalue = $weights[$i];
		}
		
		return round( floor( $minvalue * 0.1) * 10.0);
	}
	
	function minpace( $firstYear, $lastYear)
	{
		$paces = paces( $firstYear, $lastYear);
		
		$minvalue = 10000.0;
		for( $i = 0; $i < count($paces); $i++)
		{
			if( $paces[$i] < $minvalue)
				$minvalue = $paces[$i];
		}
		
		return round( floor( $minvalue * 0.1) * 10.0);
	}
			
	
?>    