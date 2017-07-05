<?php
session_start();
if($_GET['submit'] == 'OK'){
$_SESSION['login'] = $_GET['login'];
$_SESSION['passwd'] = $_GET['passwd'];}
echo "<html><body>\n<form name=\"index.php\" method=\"get\">\nUsername: <input type=\"text\" name=\"login\" value=\"".$_SESSION['login']."\">\n<br>\n<br>\nPassword: <input type=\"password\" name=\"passwd\" value=\"".$_SESSION['passwd']."\"><br>\n<input type=\"submit\" name=\"submit\" value=\"OK\">\n</form>\n</body>\n</html>";?>

