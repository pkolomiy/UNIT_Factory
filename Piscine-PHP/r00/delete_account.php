<?php
session_start();

function ft_del() {
	$tab = unserialize(file_get_contents("private/passwd"));
	$fl = 0;
	$i = 0;
	foreach ($tab as $data) {
		if ($data["login"] == $_POST["del_login"]) {
			$tab[$i]["login"] = NULL;
			$tab[$i]["passwd"] = NULL;
			$fl = 1;
		}
		$i = $i + 1;
	}
	if (!$fl)
		return (-1);
	else
		file_put_contents("private/passwd", serialize($tab));
	return (0);
}

if ($_POST["del_login"]) {
	if (ft_del()) {
		$_SESSION['del_adm_error'] = "inc_data";
		header('location: login_page.php');
		exit;
	}
	else {
		$_SESSION['del_adm_error'] = NULL;
		header('location: index.php');
		exit;
	}
}
else {
	$_SESSION['del_adm_error'] = "inc_data";
	header('location: login_page.php');
	exit;
}
?>