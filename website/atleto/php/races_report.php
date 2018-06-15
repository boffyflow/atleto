<!DOCTYPE HTML>

<?php 
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/yearly.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/races.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/footer.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/chart_view.php";
?>

<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<title>Atleto - Races</title>

		<!-- begin CSS -->
		<link href="/css/atleto.css" type="text/css" rel="stylesheet">
		<link href="/css/menu.css" type="text/css" rel="stylesheet">
	
		<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<script type="text/javascript" src="/js/atleto.js"></script>
		<script type="text/javascript">
		
		<?php
			$raceYear = 'All';
			$currentRunId = 0;
			if( isset( $_GET[ 'currentRunId']))
			{
				$currentRunId = $_GET[ 'currentRunId'];
			}
			if( isset( $_GET[ 'raceYear']))
			{
				$raceYear = $_GET[ 'raceYear'];
			}
			if( $currentRunId > 0)
			{
				$run = new Run( $currentRunId);
				$run->hs_chart();
			}
		?>	
		</script>
	</head>

	<body>
		<script src="/js/highcharts.js"></script>
		<script src="/js/themes/grid.js"></script>
	
		<?php include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/header.php"; ?>
		<hr>
		
		<form method="get" action="races_report.php">
			<p>
				Year:
				<select id="year" name="raceYear" onchange="this.form.submit()">
					<?php
						$years = years( 1900, 2100);
						echo "<option value=\"All\" " . isItemSelected( 'raceYear', 'All') . ">All</option>";
						foreach ( array_reverse( $years) as $value) 
						{
							echo "<option value=\"$value\" ";
							isItemSelected( 'raceYear', $value);
							echo ">$value</option>";
						}
					?>
				</select>
			</p>
		</form>
		
		<h2>Races</h2>
		<table id="runs" >
			<tbody>
				<?php $numRaces = races( $raceYear); ?>
			</tbody>
		</table>

		<h3>Number of races: <?php echo $numRaces; ?></h3>
		
		<?php
			if( $currentRunId > 0)
				$run->runInfo();
		?>
		
		<hr>
		<h4><?php footer(); ?></h4>
	</body>
</html>
