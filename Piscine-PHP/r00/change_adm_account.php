<?php
	session_start();
	
	function ft_old_log($tab){
		if ($_POST["new_login"])
		{
			foreach ($tab as $data) {
				if ($data["login"] == $_POST["new_login"])
					return (-1);
			}
		}
		return (0);
	}
	
	function ft_add() {
		$tab = unserialize(file_get_contents("private/passwd"));
		$fl = 0;
		$i = 0;
		if (ft_old_log($tab))
			return (-1);
		foreach ($tab as $data) {
			if ($data["login"] == $_POST["old_login"]) {
				if ($_POST["new_login"])
					$tab[$i]["login"] = $_POST["new_login"];
				if ($_POST["new_adm_passwd"])
					$tab[$i]["passwd"] = hash('whirlpool', $_POST["new_adm_passwd"]);
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

	if ($_POST["old_login"] and ($_POST["new_login"] or $_POST["new_adm_passwd"])) {
		if (ft_add()) {
			$_SESSION['ch_adm_error'] = "inc_data";
			header('location: login_page.php');
			exit;
		}
		else {
			$_SESSION['ch_adm_error'] = NULL;
			header('location: index.php');
			exit;
		}
	}
	else {
		$_SESSION['ch_adm_error'] = "inc_data";
		header('location: login_page.php');
		exit;
	}
?>