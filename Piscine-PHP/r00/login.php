<?php
	session_start();

	if (file_exists("private/passwd") and $_POST["login"] and $_POST["passwd"]) {
		$tab = unserialize(file_get_contents("private/passwd"));
		foreach ($tab as $data) {
			if ($data["login"] == $_POST["login"] and $data["passwd"] == hash('whirlpool', $_POST["passwd"])) {
				$_SESSION["user"]["login"] = $_POST["login"];
				$_SESSION['log_error'] = NULL;
				$_SESSION['reg_error'] = NULL;
				header('location: index.php');
				exit;
			}
		}
		
	}
	$_SESSION['log_error'] = "inc_data";
	header('location: login_page.php');
?>