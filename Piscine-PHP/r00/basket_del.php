<?php
	include "install.php";
	
	session_start();
	
	if ($_SESSION['user']['login'] == 'admin'){
		$tab = ft_get_data();
		if (count($tab) != 1) {
			$i = 0;
			foreach ($tab as $pr) {
				if ($_POST['product'] == ("DELETE " . $pr["name"]))
					unset($tab[$i]);
				$i++;
			}
			ft_put_data($tab);
		}
		header('location: index.php');
		exit;
	}
	else {
		$tab = ft_get_data();
		foreach ($tab as $pr) {
			if ($_POST['product'] == ("ADD " . $pr["name"]))
				$_SESSION['basket'][] = $pr;
		}
		header('location: index.php');
		exit;
	}
?>