<?php
function exist($post)
{
	if (file_exists("../private") &&
		$get = unserialize(file_get_contents("../private/passwd")))
		foreach($get as $arr)
			if($arr['login'] == $post['login'])
				return (false);
	return (true);
}
if ($_POST["passwd"] !== "" && $_POST["login"] !== "" &&
	$_POST["submit"] == "OK" && exist($_POST))
{
	$i = 0;
	if (!file_exists("../private"))
		mkdir("../private");
	else if ($tmp = unserialize(file_get_contents("../private/passwd")))
		while ($tmp[$i])
			$i++;
	$tmp[$i]['login'] = $_POST['login'];
	$tmp[$i]['passwd'] = hash("whirlpool", $_POST['passwd']);
	file_put_contents("../private/passwd",  serialize($tmp));
	echo "OK\n";
}
else
	echo "ERROR\n";
?>