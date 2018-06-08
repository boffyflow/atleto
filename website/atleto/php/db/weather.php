<?php

	require $_SERVER[ 'DOCUMENT_ROOT'] . "/php/global_inc.php";
	
	class Weather
	{
		private		$id = -1;
		private		$jd = 0;
		private		$sky = 0;
		private		$temperature = 20;
		private 	$notes;
		
		public function __construct()
		{
		}
		
		public function loadByDay( $day)
		{
			global $dbfilename;
		
			$db = new SQLite3( $dbfilename);
					
			$day_id = cal_to_jd( CAL_GREGORIAN, $day->format('n'), $day->format('j'), $day->format('Y'));
						
			$result = $db->querySingle( "select id,day,temperature,sky,notes from weathers where day=" . $day_id, true);
						
			if( count( $result) > 0)
			{			
				$this->id = $result['id'];
				$this->jd = $result['day'];
				$this->sky = $result['sky'];
				$this->temperature = $result['temperature'];
				$this->notes = $result['notes'];
			}
		}
		
		public function format()
		{
			if( $this->id >= 0)
				echo "<img src=\"/images/weather_" . $this->sky . ".png\" /> " . $this->temperature . "&deg; " . $this->notes;				
		}
	}

?>