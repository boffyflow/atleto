<!DOCTYPE HTML>

<?php
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/daily.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/chart_view.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/footer.php";
?>

<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<title>Atleto - Daily</title>

		<!-- begin CSS -->
		<link href="/css/atleto.css" type="text/css" rel="stylesheet">
	
		<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<script type="text/javascript" src="/js/atleto.js"></script>
		<script type="text/javascript">
		
		<?php
			$results = getFirstAndLast();
			$firstDay = $results[0];
			$lastDay = $results[1];
		?>
	
		$(function () {
			var dist_chart;
			$(document).ready(function() {
				dist_chart = new Highcharts.Chart({
					chart: {
						renderTo: 'distance_chart',
						type: 'column'
					},
					title: {
						text: 'Daily Distance and Pace'
					},
					xAxis: {
						categories: <?php echo json_encode( days( $firstDay, $lastDay)); ?>
					},
					yAxis: [{
						min: 0,
						title: {
							text: 'Distance'
						},
						labels: {
							formatter: function() {
								return this.value + ' km';
							}
						}
					},{
						min: <?php echo minpace( $firstDay, $lastDay); ?>,
						title: {
							text: 'Pace'
						},
						labels: {
							formatter: function() {
								return minuteString( this.value) + ' min/km';
							}
						},
						opposite: true
					}],
					<?php legend(); ?>
					tooltip: {
						formatter: function() {
							if( this.series.name == 'Distance')                
                                return ''+ this.y +' km';
                            else
                            {
                                var     val = minuteString( this.y);
                                return '' + val + ' min/km';
                            }
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
									if( this.series.name == 'Distance')                
										return ''+ this.y;
									else
									{
										var     val = minuteString( this.y);
										return '' + val;
									}	
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
						type: 'column',
						name: 'Distance',
						yAxis: 0,
						data: <?php echo json_encode( distances( $firstDay, $lastDay)); ?>
					},{
						type: 'line',
						name: 'Pace',
						yAxis: 1,
						data: <?php echo json_encode( paces( $firstDay, $lastDay)); ?>
					}]
				});
			});
		});		

		$(function () {
			var weight_chart;
			$(document).ready(function() {
				weight_chart = new Highcharts.Chart({
					chart: {
						renderTo: 'weight_chart',
						type: 'column'
					},
					title: {
						text: 'Daily Weight'
					},
					xAxis: {
						categories: <?php echo json_encode( days( $firstDay, $lastDay)); ?>
					},
					yAxis: {
						min: <?php echo minweight( $firstDay, $lastDay); ?>,
						title: {
							text: 'Weekly Weight'
						},
						labels: {
							formatter: function() {
								return this.value + ' kg';
							}
						}
					},
					<?php legend(); ?>
					tooltip: {
						formatter: function() {
							return ''+ this.y +' kg';
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
								borderRadius: 5,
								backgroundColor: 'rgba(252, 255, 197, 0.7)',
								borderWidth: 1,
								borderColor: '#AAA',
								y: -6
							}
						}
					},
					series: [{
						type: 'area',
						color: '#AA4643',
						name: 'Weight',
						data: <?php echo json_encode( weights( $firstDay, $lastDay)); ?>
					}]
				});
			});
		});
	
		function enableInputs( selectedInput) {
			if( selectedInput == 1) {
				document.getElementById( 'numRange').disabled = false;
				document.getElementById( 'whichRange').disabled = false;
				document.getElementById( 'fixedRange').disabled = true;
				document.getElementById( 'customFirst').disabled = true;
				document.getElementById( 'customLast').disabled = true;
			}
			if( selectedInput == 2) {
				document.getElementById( 'numRange').disabled = true;
				document.getElementById( 'whichRange').disabled = true;
				document.getElementById( 'fixedRange').disabled = false;
				document.getElementById( 'customFirst').disabled = true;
				document.getElementById( 'customLast').disabled = true;
			}
			if( selectedInput == 3) {
				document.getElementById( 'numRange').disabled = true;
				document.getElementById( 'whichRange').disabled = true;
				document.getElementById( 'fixedRange').disabled = true;
				document.getElementById( 'customFirst').disabled = false;
				document.getElementById( 'customLast').disabled = false;
			}
		}
	
		</script>
	</head>

	<body>
		<script src="/js/highcharts.js"></script>
		<script src="/js/themes/grid.js"></script>

		<?php include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/header.php"; ?>

        <form method="post" action="daily_report.php" id="mainform">
			<p>
				<input type="radio" id="radio_range" name="range_select" value="1" <?php isChecked( 1); ?> onchange="enableInputs( 1);this.form.submit()" />
					Last
					<input type="number" id="numRange" min="1" max="50" value="<?php if( isset( $_POST[ "numRange"])) echo $_POST[ "numRange"]; else echo "30"; ?>" name="numRange" onchange="this.form.submit()" />
					<select id="whichRange" name="whichRange" onchange="this.form.submit()">
						<option value="days" <?php isItemSelected( "whichRange", "days"); ?> >Days</option>
						<option value="weeks" <?php isItemSelected( "whichRange", "weeks"); ?> >Weeks</option>
						<option value="months" <?php isItemSelected( "whichRange", "months"); ?> >Months</option>
					</select><br>
				<input type="radio" id="radio_fixedrange" name="range_select" value="2" <?php isChecked( 2); ?> onchange="enableInputs( 2);this.form.submit()" />
					<select id="fixedRange" name="fixedRange" onchange="this.form.submit()">
						<option value="this_week" <?php isItemSelected( "fixedRange", "this_week"); ?> >This Week</option>
						<option value="this_month" <?php isItemSelected( "fixedRange", "this_month"); ?> >This Month</option>
						<option value="this_year" <?php isItemSelected( "fixedRange", "this_year"); ?> >This Year</option>
						<option value="last_week" <?php isItemSelected( "fixedRange", "last_week"); ?> >Last Week</option>
						<option value="last_month" <?php isItemSelected( "fixedRange", "last_month"); ?> >Last Month</option>
						<option value="last_year" <?php isItemSelected( "fixedRange", "last_year"); ?> >Last Year</option>
					</select><br>
				<input type="radio" id="radio_customrange" name="range_select" value="3" <?php isChecked( 3); ?> onchange="enableInputs( 3);this.form.submit()" />
					From
					<input type="date" id="customFirst" value="<?php customDate( "first"); ?>" name="customFirst" onchange="this.form.submit()" />
					Through
					<input type="date" id="customLast" value="<?php customDate( "last"); ?>" name="customLast" onchange="this.form.submit()" />
			</p>
		</form>
		
		<?php echo "<script>enableInputs(" . radioState() . ");</script>"; ?>

		<div id="distance_chart" style="min-width: 400px; height: 400px; margin: 0 auto"></div><br>
		<div id="weight_chart" style="min-width: 400px; height: 400px; margin: 0 auto"></div>
		
		<hr>
		
		<h4><?php footer(); ?></h4>
	</body>
</html>
