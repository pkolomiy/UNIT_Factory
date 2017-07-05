<?php
	session_start();

	function ft_choose_foorm(){
		if (!$_SESSION["user"]['login'])
			echo ('<div id="account-field">
				<p class="account-text">Log in</p>
				<form action="login.php" method="post">
					<p class="account-field-text">Username</p>
			         <input class="input-field" type="text" name="login" value='.$_SESSION["log_error"].'>
					<p class="account-field-text">Password</p>
					<input class="input-field" type="password" name="passwd" value="">
					<p><input class="login_conf_buttom" type="submit" name="submit" value="LOGIN"></p>
				</form>
		         <p class="account-text">Create Account</p>
			    <form action="create_account.php" method="post">
				    <p class="account-field-text">New username</p>
				    <input class="input-field" type="text" name="reg_login" value='.$_SESSION['reg_error'].'>
				    <p class="account-field-text">Password</p>
				    <input class="input-field" type="password" name="reg_passwd" value="">
				    <p class="account-field-text">Confirm password</p>
				    <input class="input-field" type="password" name="reg_conf_passwd" value="">
				    <p><input class="login_conf_buttom"  type="submit" name="submit" value="CREATE"></p>
				    <p class="account-field-text"></p>
			    </form>
		    </div>');
		elseif ($_SESSION["user"]['login'] == 'admin')
			echo ('<div id="account-field">
				<p class="account-text">Change Account</p>
				<form action="change_adm_account.php" method="post">
					<p class="account-field-text">Old username</p>
			         <input class="input-field" type="text" name="old_login" value='.$_SESSION["ch_adm_error"].'>
					<p class="account-field-text">New username</p>
			         <input class="input-field" type="text" name="new_login" value="">
					<p class="account-field-text">New password</p>
					<input class="input-field" type="password" name="new_adm_passwd" value="">
					<p><input class="login_conf_buttom" type="submit" name="submit" value="CHANGE"></p>
				</form>
		         <p class="account-text">Delete Account</p>
			    <form action="delete_account.php" method="post">
				    <p class="account-field-text">Username</p>
				    <input class="input-field" type="text" name="del_login" value='.$_SESSION['del_adm_error'].'>
				    <p><input class="login_conf_buttom"  type="submit" name="submit" value="DELETE"></p>
				    <p class="account-field-text"></p>
			    </form>
		    </div>');
		else
			echo ('<div id="account-field">
				<p class="account-text">Change password</p>
			    <form action="change_account.php" method="post">
				    <p class="account-field-text">Username</p>
				    <input class="input-field" type="text" name="ch_login" value='.$_SESSION['ch_error'].'>
				    <p class="account-field-text">Old Password</p>
				    <input class="input-field" type="password" name="old_passwd" value="">
				    <p class="account-field-text">New password</p>
				    <input class="input-field" type="password" name="new_passwd" value="">
				    <p><input class="login_conf_buttom"  type="submit" name="submit" value="CHANGE"></p>
				    <p class="account-field-text"></p>
			    </form>
		    </div>');
	}
?>
<html lang="en">
	<head>
		<meta charset="UTF-8">
		<title>Sport.unit</title>
		<link rel="stylesheet" href="styles.css">
	</head>
	<body>
		<div id = "main_list">
	        <div id = "main_name">
				<p id = "name">UNIT SPORT</p>
	        </div>
	        <div id="header">
			<a class="button-wrap" style="margin-left: 2px" href="index.php">
				<div class="button">
					<p class="button-text">Back</p>
				</div>
			</a>
	        </div>
	        <?php ft_choose_foorm() ?>
		</div>
		<div id = "main_list" style="height: 100px; margin-top: -1vw"></div>
	</body>
</html>
