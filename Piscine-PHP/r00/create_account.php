<?php
	session_start();
	
	function ft_check_login($log)
	{
		if (!($i = strlen($log)))
			return (-1);
		while ($i--)
			if (!(($log[$i] >= 'a' and $log[$i] <= 'z') or ($log[$i] >= 'A' and $log[$i] <= 'Z') or ($log[$i] >= '0' and $log[$i] <= '9')))
					return (-1);
		return (0);
	}

	if ((ft_check_login($_POST["reg_login"]) == -1) or (ft_check_login($_POST["reg_passwd"]) == -1)) {
		$_SESSION['reg_error'] = "inc_data";
		header('location: login_page.php');
		exit;
	}
	
	if ($_POST["reg_login"] and $_POST["reg_passwd"] and $_POST["reg_conf_passwd"] and  $_POST["reg_passwd"] == $_POST["reg_conf_passwd"]) {
		if (!file_exists("private"))
			mkdir("private");
		if (!file_exists("private/passwd")) {
			$tab = array();
			$data["login"] = $_POST["reg_login"];
			$data["passwd"] = hash('whirlpool', $_POST["reg_passwd"]);
			$tab[] = $data;
			file_put_contents("private/passwd", serialize($tab));
			$_SESSION["user"]["login"] = $_POST["reg_login"];
			$_SESSION['reg_error'] = NULL;
			$_SESSION['log_error'] = NULL;
			header('location: index.php');
			exit;
		}
		else {
			$tab = unserialize(file_get_contents("private/passwd"));
			$flag = 0;
			foreach ($tab as $data) {
				if ($data["login"] == $_POST["reg_login"])
					$flag = -1;
			}
			if (!$flag)
			{
				$data["login"] = $_POST["reg_login"];
				$data["passwd"] = hash('whirlpool', $_POST["reg_passwd"]);
				$tab[] = $data;
				file_put_contents("private/passwd", serialize($tab));
				$_SESSION["user"]["login"] = $_POST["reg_login"];
				$_SESSION['reg_error'] = NULL;
				$_SESSION['log_error'] = NULL;
				header('location: index.php');
				exit;
			}
			else
				$_SESSION['reg_error'] = "inc_data";
		}
	}
	else
		$_SESSION['reg_error'] = "inc_data";
	header('location: login_page.php');
	exit;
?>