<!DOCTYPE HTML>

<?php 
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/shoes.php";
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
		
		?>
	
		$(function () {
			var shoe_chart;
			$(document).ready(function() {
			
				Highcharts.getOptions().colors = Highcharts.map(Highcharts.getOptions().colors, function(color) {
					return {
						radialGradient: { cx: 0.5, cy: 0.3, r: 0.7 },
						stops: [
							[0, color],
							[1, Highcharts.Color(color).brighten(-0.3).get('rgb')] // darken
						]
					};
				});
			
				shoe_chart = new Highcharts.Chart({
					chart: {
						renderTo: 'shoe_chart',
						plotBackgroundColor: null,
						plotBorderWidth: null,
						plotShadow: false				
					},
					title: {
						text: 'Shoes'
					},
					tooltip: {
						formatter: function() {
							return '' + this.point.name + ': ' + this.y +' km';
						}
					},
					plotOptions: {
						pie: {
							allowPointSelect: true,
							cursor: 'pointer',
							dataLabels: {
								enabled: true,
								color: '#000000',
								connectorColor: '#000000',
								formatter: function() {
									if( this.y > 800)
										return '<b>'+ this.point.name +'</b>:  <style="fontWeight:bold;color:red">' + this.y + ' km</style>';
									else
										return '<b>'+ this.point.name +'</b>: '+ this.y +' km';
								}
							}
						}
					},
					series: [{
						type: 'pie',
						name: 'Distance',
						data: <?php shoeList(); ?>
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
		<hr>
		<div id="shoe_chart" style="width: 650px; height: 400px; margin-left: auto; margin-right: auto"></div><br>
		
		<hr>
		
		<h4><?php footer(); ?></h4>
	</body>
</html>
