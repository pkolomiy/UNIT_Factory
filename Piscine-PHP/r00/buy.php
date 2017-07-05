<?php
	session_start();

	foreach ($_SESSION['basket'] as $pr){
		$ch = $ch . $pr["name"] . " price = ". $pr["price"]."\n";
	}
	file_put_contents("resourses/sum.txt", ($ch."\nSUMM = ".$_SESSION['price']));
	header('location: index.php');
	exit;
?>