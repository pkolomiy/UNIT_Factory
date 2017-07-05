<?php
	session_start();
	
	$_SESSION['category'] = $_POST["cat"];
	echo ($_POST["cat"]);
	header('location: index.php');
	exit;
?>