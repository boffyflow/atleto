<?php

	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/global_inc.php";
	
	function shoeMileage( $id)
	{
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);
		
		$result = $db->querySingle( "select sum(dist) from run_splits where run_id in (select id from runs where shoe_id=" . $id . ")");
		$dist = round( $result * 0.001);
		
		return $dist;
	}
	
	function shoeList()
	{
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);
		
		$result = $db->query( "select id,name from shoes where inuse=\"true\"");
		
		echo "[";
		while( $row = $result->fetchArray())
		{
			$dist = shoeMileage( $row[0]);
			echo "[ '". $row[1] . "'," . $dist . "],";
		}
		echo "]";
	}
?>    