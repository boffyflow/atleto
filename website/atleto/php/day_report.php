<!DOCTYPE HTML>

<?php
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/daily.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/day.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/db/weather.php";
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
			global $timezone;
		
			if( isset( $_GET[ 'currentDay']))
				$currentDay = DateTime::createFromFormat( 'Y-m-d', $_GET[ 'currentDay']);
			else
				$currentDay = new DateTime( 'now', $timezone);
		?>
	
		</script>
	</head>

	<body>
		<script src="/js/highcharts.js"></script>
		<script src="/js/modules/exporting.js"></script>
		<script src="/js/themes/grid.js"></script>
		
		<?php include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/header.php"; ?>
		
		<hr>
		
		<form action="day_report.php" method="get" >
			Day: <input type="date" name="currentDay" onchange="this.form.submit()" value="<?php echo $currentDay->format( 'Y-m-d'); ?>" />
		</form>
		<div class="day">
			<div class="weather">
			<?php
				$w = new Weather();
				$w->loadByDay( $currentDay);
				$w->format();
			?>
			</div>
			<div class="trun">
			<?php
				$distances = distances( $currentDay, $currentDay);
				if( $distances[0] != 0)
					echo "Total distance: " . $distances[0] . " km";
			?>
			</div>
			<div class="physical">Physcial</div>
			<div class="journal">Journal</div>
		</div>
	
	
		<br>
		<hr>
		<h2>Test area:</h2>
		<?php
			$n = new DateTime( 'now', $timezone);
			echo 'current day: ' . $currentDay->format( 'D - Y-M-d');
			echo '<br>right now: ' . $n->format( 'Y-M-d, G:i:s');
			$n->setTimeZone( new DateTimeZone( 'America/Vancouver'));
			echo '<br>with time zone: ' . $n->format( 'Y-M-d, G:i:s');
		?>
		
		<hr>
		
		<h4><?php footer(); ?></h4>
	</body>
</html>
