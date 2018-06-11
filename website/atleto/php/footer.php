<?php

	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/global_inc.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/general.php";
	
  function footer()
  {
		global $dbfilename;
		
		$db = new SQLite3( $dbfilename);

		$r = cal_from_jd( $db->querySingle( "select max(day) from runs"), CAL_GREGORIAN);
		
		echo "Number of runs: ". numRuns() . ", Last run on: " . $r['dayname'] . ", " . $r['abbrevmonth'] . " " . $r['day'] . " " . $r['year'];
		echo "<br>&copy; 2013-2018 Robert Uebbing";
  }
?>    