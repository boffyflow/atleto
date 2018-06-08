<?php

	require $_SERVER[ 'DOCUMENT_ROOT'] . "/php/global_inc.php";
	
	class Run
	{
		private		$id;
		private		$location;
		private		$day;
		private		$splits = array();
		private		$times = array();
		private		$distances = array();
		private		$paces = array();
		private     $hrs = array();
		private 	$total_time;
		private		$total_distance;
		private		$comments;
		private		$runtype;
		private		$run_tod;
		
		public function __construct( $id = -1)
		{
			$this->load( $id);
		}
		
		public function load( $id)
		{
			global $dbfilename;
			global $timezone;
		
			$db = new SQLite3( $dbfilename);
			
			$result = $db->querySingle( "select day,location_id,notes,runtype_id,starttime from runs where id=" . $id, true);
			
			$r = cal_from_jd( $result['day'], CAL_GREGORIAN);
			
			$this->day = new DateTime( 'now', $timezone);
			$this->day->setDate( $r['year'], $r['month'], $r['day']);
			$this->comments = $result['notes'];
			
			$this->run_tod = new DateTime( $result['starttime']);
			
			$this->location = $db->querySingle( "select name from locations where id=" . $result['location_id']);
			$this->runtype = $db->querySingle( "select name from run_types where id=" . $result['runtype_id']);
			
			$result = $db->query( "select dist,t,hr from run_splits where run_id=" . $id);
			
			while( $row = $result->fetchArray())
			{
				array_push( $this->splits, $row[0]);
				array_push( $this->times, $row[1]);
				array_push( $this->hrs, $row[2]);
				array_push( $this->paces, round( $row[1] / ( $row[0] * 0.001)));
				if( $row[0] < 1000.0)
					array_push( $this->distances, strval( round( $row[0])) . "m");
				else
					array_push( $this->distances, strval( round( $row[0] * 0.001, 1)) . "km");
			}
			
			$this->total_time = array_sum( $this->times);
			$this->total_distance = array_sum( $this->splits);
		}
		
		public function time_string()
		{
			return totalTime( $this->total_time, true);
		}
		
		public function pace_string()
		{
			return totalTime( round( $this->total_time / ( $this->total_distance * 0.001)), true) . " min/km";
		}
		
		public function avehr_string()
		{
		    $thr = array_sum( $this->hrs);
		    $numhrs = count( $this->hrs);
		    
		    if( $numhrs > 0)
    		    return round( $thr / count( $this->hrs));
    		else
    		    return "";
		}
		
		public function distance_string()
		{
			return round( $this->total_distance * 0.01) * 0.1 . " km";
		}
		
		public function location()
		{
			return $this->location;
		}
		
		public function runtype()
		{
			return $this->runtype;
		}
		
		public function day()
		{
			return $this->day;
		}
		
		public function run_tod()
		{
			return $this->run_tod->format( "H:i");
		}
		
		function minpace()
		{			
			$minvalue = 10000.0;
			for( $i = 0; $i < count( $this->paces); $i++)
			{		
				if( $this->paces[$i] < $minvalue && $this->paces[$i] > 1.0)
					$minvalue = $this->paces[$i];
			}
			
			return round( floor( $minvalue * 0.1) * 10.0);
		}
		
		public function runInfo()
		{
			echo
				"<div id=\"RunInfo\" class=\"modalDialog\">
					<div>
						<a href=\"#close\" id=\"close\" title=\"Close\" class=\"close\" style=\"float:left\"><img src=\"/images/close_button_black.png\" width=\"32\" height=\"32\" /></a>";
			echo "<table id=\"runs\">";
			echo "<tr class=\"alt\"><td>Location</td><td>" . $this->location . "</td></tr>";
			echo "<tr><td>Distance</td><td>" . $this->distance_string() . "</td></tr>";
			echo "<tr class=\"alt\"><td>Time</td><td>" . $this->time_string() . "</td></tr>";
			echo "<tr><td>Average pace</td><td>" . $this->pace_string() . "</td></tr>";
			echo "<tr class=\"alt\"><td>Average heart rate</td><td>" . $this->avehr_string() . "</td></tr>";
			echo "</table><br>";
			echo "<div id=\"splits_chart\" style=\"min-width: 300px; height: 360px; margin: 0 auto\"></div>";
			echo "</div></div>";
		}
		
		public function hs_chart()
		{
			echo
				"$(function () {
					var splits_chart;
					$(document).ready(function() {
						splits_chart = new Highcharts.Chart({
							chart: {
								renderTo: 'splits_chart',
								type: 'column'
							},
							title: {
								text: 'Run Splits'
							},
							xAxis: {
								categories:"; 
			echo json_encode( $this->distances);
			echo		"},
						yAxis: [{
							min:"; 
			echo $this->minpace();				
			echo		",
							title: {
								text: 'Pace'
							},
							labels: {
								formatter: function() {
									return minuteString( this.value) + ' min/km';
								}
							}
						}],";
			legend();
			echo
						"tooltip: {
							formatter: function() {
								return '' + minuteString( this.y) + ' min/km';
							}
						},
						plotOptions: {
							column: {
								pointPadding: 0.2,
								borderWidth: 0
							},
							series: {
								dataLabels: {
									enabled: true,
									formatter: function() {
										return '' + minuteString( this.y);
									},
									borderRadius: 5,
									backgroundColor: 'rgba(252, 255, 197, 0.7)',
									borderWidth: 1,
									borderColor: '#AAA',
									y: -6
								}
							}
						},
						series: [{
							type: 'line',
							name: 'Pace',
							data:";
			echo json_encode( $this->paces);
			echo		"}]
					});
				});
			});";	
		}
	}

?>