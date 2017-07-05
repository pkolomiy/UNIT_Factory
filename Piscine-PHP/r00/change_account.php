<?php
	session_start();

	function ft_add() {
		$tab = unserialize(file_get_contents("private/passwd"));
		$fl = 0;
		$i = 0;
		foreach ($tab as $data) {
			if ($data["login"] == $_POST["ch_login"] and $data["passwd"] == hash('whirlpool', $_POST["old_passwd"])) {
				$tab[$i]["passwd"] = hash('whirlpool', $_POST["new_passwd"]);
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
	
	if ($_POST["ch_login"] and $_POST["old_passwd"] and $_POST["new_passwd"] and $_POST["ch_login"] == $_SESSION["user"]['login']) {
		if (ft_add()) {
			$_SESSION['ch_error'] = "inc_data";
			header('location: login_page.php');
			exit;
		}
		else {
			$_SESSION['ch_error'] = NULL;
			header('location: index.php');
			exit;
		}
	}
	else {
		$_SESSION['ch_error'] = "inc_data";
		header('location: login_page.php');
		exit;
	}
?>