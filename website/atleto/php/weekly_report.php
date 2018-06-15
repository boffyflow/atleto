<!DOCTYPE HTML>

<?php
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/weekly.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/chart_view.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/footer.php";
?>

<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<title>Atleto - Weekly</title>

		<!-- begin CSS -->
		<link href="/css/atleto.css" type="text/css" rel="stylesheet">
		<link href="/css/menu.css" type="text/css" rel="stylesheet">
	
		<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<script type="text/javascript" src="/js/atleto.js"></script>
		<script type="text/javascript">
		
		<?php
			$firstWeek = firstWeek( 12);
			$lastWeek = lastWeek();
			if( isset( $_POST["firstWeek"], $_POST["lastWeek"]))
			{
				$firstWeek = $_POST["firstWeek"];
				$lastWeek = $_POST["lastWeek"];				
			}
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
						text: 'Weekly Distance and Pace'
					},
					xAxis: {
						categories: <?php echo json_encode( weeks( $firstWeek, $lastWeek)); ?>
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
						min: <?php echo minpace( $firstWeek, $lastWeek); ?>,
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
						data: <?php echo json_encode( distances( $firstWeek, $lastWeek)); ?>
					},{
						type: 'line',
						name: 'Pace',
						yAxis: 1,
						data: <?php echo json_encode( paces( $firstWeek, $lastWeek)); ?>
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
						text: 'Weekly Weight'
					},
					xAxis: {
						categories: <?php echo json_encode( weeks( $firstWeek, $lastWeek)); ?>
					},
					yAxis: {
						min: <?php echo minweight( $firstWeek, $lastWeek); ?>,
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
						name: 'Maximum',
						data: <?php echo json_encode( weights( $firstWeek, $lastWeek, "max")); ?>
					},{
						type: 'area',
						color: '#4572A7',
						name: 'Average',
						data: <?php echo json_encode( weights( $firstWeek, $lastWeek, "avg")); ?>
					},{
						type: 'area',
						color: '#89A54E',
						name: 'Minimum',
						data: <?php echo json_encode( weights( $firstWeek, $lastWeek, "min")); ?>
					}]
				});
			});
		});
		
		</script>
	</head>

	<body>
		<script src="/js/highcharts.js"></script>
		<script src="/js/themes/grid.js"></script>
		
		<?php include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/header.php"; ?>

        <form method="post" action="weekly_report.php">
			<p>
				Display data between
				<input id="week1" type="week" value="<?php echo $firstWeek; ?>" name="firstWeek" onchange="this.form.submit()" />
				and
				<input id="week2" type="week" value="<?php echo $lastWeek; ?>" name="lastWeek" onchange="this.form.submit()" />. The date range is between
				<?php echo weekToDate( $firstWeek)->format( 'd-M-Y'); ?> and <?php $lw = weekToDate( $lastWeek); $lw->modify( '+6 days'); echo $lw->format( 'd-M-Y'); ?>.
			</p>
		</form>
		
		<div id="distance_chart" style="min-width: 400px; height: 400px; margin: 0 auto"></div><br>
		<div id="weight_chart" style="min-width: 400px; height: 400px; margin: 0 auto"></div><br>

		<hr>
		<h2>Test area:</h2>
		<?php echo "first week: ". $firstWeek; ?><br>
		<?php echo "last week: " . $lastWeek; ?>
		<hr>
		
		<h4><?php footer(); ?></h4>
	</body>
</html>
