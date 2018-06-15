<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">

<?php 
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/footer.php";
	include $_SERVER[ 'DOCUMENT_ROOT'] . "/php/chart_view.php";
	
	$searchLocation = "";
	$numLimit = 1000;
	$currentRunId = -1;
	if( isset( $_GET[ 'searchLocation']))
	{
		$searchLocation = $_GET[ 'searchLocation'];
	}
	if( isset( $_GET[ 'currentRunId']))
	{
		$currentRunId = $_GET[ 'currentRunId'];
		$run = new Run( $currentRunId);
	}
		
?>

<html>
<head>	
	<title>Atleto - Search Results</title>
	<meta name="Copyright" content="All Images, CSS, & HTML is/are Copyright ©2012 Parallel Pixels">
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	
	<link href="/css/atleto.css" type="text/css" rel="stylesheet">
	<link href="/css/menu.css" type="text/css" rel="stylesheet">
	
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
	<h1>Search Diary...</h1>

    <form method="get" action="search_results.php">
		<p>
				Find in locations:
				<input id="location" type="text" name="searchLocation" value="<?php echo $searchLocation; ?>" />
				<input type="submit" value="Search" />
		</p>
	</form> 
	
	<table id="runs" >
		<tbody>
			<?php searchRuns( $searchLocation, $numLimit); ?>
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