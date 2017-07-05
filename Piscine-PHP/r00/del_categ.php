<?php
	include "install.php";
	
	session_start();

	$tab = ft_get_data();
	$i = 0;
	$un = ft_list_categories($tab);
	
	if (count($un) != 1) {
		foreach ($tab as $pr) {
			if ($_POST['submit'] == ("DELETE " . $pr["category"]))
				unset($tab[$i]);
			$i++;
		}
		ft_put_data($tab);
	}
	header('location: category_page.php');
?>