<?php
	include "install.php";

	session_start();

	if ($_POST["category"] and $_POST["name"] and $_POST["price"] and $_POST["desc"] and $_POST["img"] and file_exists("resourses/".$_POST["img"])) {
		$tab = ft_get_data();
		$new['name'] = $_POST["name"];
		$new['price'] = $_POST["price"];
		$new['desc'] = $_POST["desc"];
		$new['img'] = $_POST["img"];
		$new['category'] = $_POST["category"];
		$tab[] = $new;
		ft_put_data($tab);
		$_SESSION['er_ad'] = NULL;
		header('location: index.php');
	}
	else {
		$_SESSION['er_ad'] ="inc_data";
		header('location: add_product_page.php');
	}
?>