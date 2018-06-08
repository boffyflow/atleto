<!DOCTYPE HTML>

<?php
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/yearly.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/chart_view.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/footer.php";
?>

<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<title>Atleto - Yearly</title>
		
		<link href="/css/atleto.css" type="text/css" rel="stylesheet">
		
		<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<script type="text/javascript" src="/js/atleto.js"></script>
		<script src="/js/modernizr-2.0.6.min.js" type="text/javascript"></script>
		<script type="text/javascript">
		
		<?php
			$fy = 1900;
			$ly = 2100;
			if( isset( $_POST["firstYear"], $_POST["lastYear"]))
			{
				$fy = $_POST["firstYear"];
				$ly = $_POST["lastYear"];
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
						text: 'Yearly Distance and Pace'
					},
					xAxis: {
						categories: <?php echo json_encode( years( $fy, $ly)); ?>
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
					}, {
						min: <?php echo minpace( $fy, $ly); ?>,
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
						data: <?php echo json_encode( distances( $fy, $ly)); ?>
					}, {
						type: 'line',
						name: 'Pace',
						yAxis: 1,
						data: <?php echo json_encode( paces( $fy, $ly)); ?>
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
						text: 'Yearly Weight'
					},
					xAxis: {
						categories: <?php echo json_encode( years( $fy, $ly)); ?>
					},
					yAxis: {
						min: <?php echo minweight( $fy, $ly); ?>,
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
						data: <?php echo json_encode( yearly_weights( $fy, $ly, "max")); ?>
					},{
						type: 'area',
						color: '#4572A7',
						name: 'Average',
						data: <?php echo json_encode( yearly_weights( $fy, $ly, "avg")); ?>
					},{
						type: 'area',
						color: '#89A54E',
						name: 'Minimum',
						data: <?php echo json_encode( yearly_weights( $fy, $ly, "min")); ?>
					}]
				});
			});
		});
		
		</script>
	</head>

	<body>
		<script src="//atleto.uebbing.com/js/highcharts.js"></script>
		<script src="//atleto.uebbing.com/js/themes/grid.js"></script>
		
		<?php include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/header.php"; ?>

        <form method="post">
			<p>
			From year:
				<select id="firstYear" name="firstYear" onchange="this.form.submit()">
					<?php
						$years = years( 1900, 2100);
						foreach ( $years as $value) 
						{
							if( $value <= $ly)
							{
								if( $value == $fy || $value == $years[0])
								{
									echo "<option selected=\"selected\" value=\"$value\">$value</option>";
								}
								else
								{
									echo "<option value=\"$value\">$value</option>";
								}
							}
						}
					?>
				</select>
			to:
				<select id="lastYear" name="lastYear" onchange="this.form.submit()">
					<?php
						$years = years( 1900, 2100);
						$numyears_minusone = count($years) - 1;
						foreach ( $years as $value)
						{
							if( $value >= $fy)
							{
								if( $value == $ly)
								{
									echo "<option selected=\"selected\" value=\"$value\">$value</option>";
								}
								else if( $ly == 2100 && $value == $years[$numyears_minusone])
								{
									echo "<option selected=\"selected\" value=\"$value\">$value</option>";
								}
								else
								{
									echo "<option value=\"$value\">$value</option>";
								}
							}
						}
					?>
				</select>
			</p>
		</form>
		<div id="distance_chart" style="min-width: 400px; height: 400px; margin: 0 auto"></div>
		<br>
		<div id="weight_chart" style="min-width: 400px; height: 400px; margin: 0 auto"></div>
		<h4><?php footer(); ?></h4>
	</body>
</html>
