<!DOCTYPE HTML>

<?php
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/monthly.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/chart_view.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/footer.php";
?>

<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<title>Atleto - Monthly</title>

		<!-- begin CSS -->
		<link href="/css/atleto.css" type="text/css" rel="stylesheet">
		<link href="/css/menu.css" type="text/css" rel="stylesheet">
	
		<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<script type="text/javascript" src="/js/atleto.js"></script>
		<script type="text/javascript">
		
		<?php
			$numMonths = 12;
			if( isset( $_POST["numberMonths"]))
			{
				$numMonths = $_POST["numberMonths"];
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
						text: 'Monthly Distance and Pace'
					},
					xAxis: {
						categories: <?php echo json_encode( months( $numMonths)); ?>
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
						min: <?php echo minpace( $numMonths); ?>,
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
						data: <?php echo json_encode( distances( $numMonths)); ?>
					},{
						type: 'line',
						name: 'Pace',
						yAxis: 1,
						data: <?php echo json_encode( paces( $numMonths)); ?>
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
						text: 'Monthly Weight'
					},
					xAxis: {
						categories: <?php echo json_encode( months( $numMonths)); ?>
					},
					yAxis: {
						min: <?php echo minweight( $numMonths); ?>,
						title: {
							text: 'Weight'
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
						data: <?php echo json_encode( monthly_weights( $numMonths, "max")); ?>
					},{
						type: 'area',
						color: '#4572A7',
						name: 'Average',
						data: <?php echo json_encode( monthly_weights( $numMonths, "avg")); ?>
					},{
						type: 'area',
						color: '#89A54E',
						name: 'Minimum',
						data: <?php echo json_encode( monthly_weights( $numMonths, "min")); ?>
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

        <form method="post" action="monthly_report.php">
			<p>
			Last
				<input type="number" min="1" max="50" name="numberMonths" value="<?php echo $numMonths ?>" onchange="this.form.submit()">
			months
			</p>
		</form>
		<div id="distance_chart" style="min-width: 400px; height: 400px; margin: 0 auto"></div><br>
		<div id="weight_chart" style="min-width: 400px; height: 400px; margin: 0 auto"></div>
		<h4><?php footer(); ?></h4>
	</body>
</html>
