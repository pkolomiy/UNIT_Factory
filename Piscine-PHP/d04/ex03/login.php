<?php
include("auth.php");
session_start();
echo (($_SESSION['loggued_on_user'] = auth($_GET['login'], $_GET['passwd']) ?
	$_GET['login'] : "") !== "" ? "OK\n" : "ERROR\n");
?>