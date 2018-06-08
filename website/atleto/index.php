<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">

<?php 
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/footer.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/chart_view.php";
	
	$numLastRuns = 30;
	$currentRunId = -1;
	if( isset( $_GET[ 'currentRunId']))
	{
		$currentRunId = $_GET[ 'currentRunId'];
		$run = new Run( $currentRunId);
	}
		
?>

<html>
<head>	
	<title>Atleto - Home</title>
	<meta name="Copyright" content="All Images, CSS, & HTML is/are Copyright ©2012 Parallel Pixels">
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	
	<link href="/css/atleto.css" type="text/css" rel="stylesheet">
	
	<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
	<script type="text/javascript" src="/js/atleto.js"></script>
	<script type="text/javascript">
	
		<?php 
			if( $currentRunId > 0)
				$run->hs_chart();
		?>	
	
	</script>
</head>

<body>
	<script src="/js/highcharts.js"></script>
	<script src="/js/themes/grid.js"></script>

	<?php include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/header.php"; ?>
	<h1>Welcome to Atleto Reports!</h1>
	<table id="runs">
		<tbody>
			<tr class="alt">
				<td>Number of runs:</td>
				<td><b><?php echo numRuns(); ?></b></td>
			</tr>
			<tr>
				<td>Total distance:</td>
				<td><b><?php echo round( totals( 'dist') * 0.001) . " km"; ?></b></td>
			</tr>
			<tr class="alt">
				<td>Total time spent running:</td>
				<td><b><?php echo totalTime( totals( 't')); ?></b></td>
			</tr>
			<tr>
				<td>Average pace:</td>
				<td><b><?php echo totalPace(); ?></b></td>
			</tr>
			<tr class="alt">
				<td>Average distance per run:</td>
				<td><b><?php echo round( totals( 'dist') * 0.001 / numRuns(), 1) . " km"; ?></b></td>
			</tr>
			<tr>
				<td>Average time per run:</td>
				<td><b><?php echo totalTime( totals( 't')/ numRuns()); ?></b></td>
			</tr>
		</tbody>
	</table>
	<h2>Last <?php echo $numLastRuns; ?> runs</h2>
	<table id="runs" >
		<tbody>
			<?php lastRuns( $numLastRuns); ?>
		</tbody>
	</table>
	<h2>Type of runs - Legend</h2>
	<table id="runs">
		<tbody>
			<tr class="orange1">
				<td>recovery</td><td>as easy as possible, ideally without running watch, slow jog</td>
			</tr>
			<tr class="orange1">
				<td>easy</td><td>heartrate <= 140 bpm</td>
			</tr>
			<tr class="orange2">
				<td>medium</td><td>bread and butter runs, regular pace without pushing hard</td>
			</tr>
			<tr class="orange3">
				<td>hills</td><td>significant uphill running at hard pace</td>
			</tr>			
			<tr class="orange3">
				<td>marathon pace</td><td>run at marathon pace, typically between 5km and 20km</td>
			</tr>
			<tr class="orange3">
				<td>threshold</td><td>run at lactate threshold pace, typically between 3km and 8km</td>
			</tr>
			<tr class="orange3">
				<td>interval</td><td>repeats on track or road, usually 3x - 12x between 400m and 3km</td>
			</tr>
			<tr class="orange3">
				<td>long run</td><td>runs longer than 90min or 15km, preparation for longer races</td>
			</tr>
			<tr class="orange4">
				<td>race</td><td>all out, attempt to run as hard as possible, should be followed by recovery/easy runs</td>
			</tr>
		</tbody>
	</table>
	

	<?php
		if( $currentRunId > 0)
			$run->runInfo();
	?>

	<hr>
	<h4><?php footer(); ?></h4>

</body>
</html>