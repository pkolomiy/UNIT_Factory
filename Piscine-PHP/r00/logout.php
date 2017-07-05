<?php
	session_start();
	
	if ($_SESSION['user']['login']) {
		session_destroy();
		header('location: index.php');
		exit;
	}
	header('location: login_page.php');
?>