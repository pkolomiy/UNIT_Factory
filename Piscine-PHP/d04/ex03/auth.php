<?php
function auth($login, $passwd)
{
	$tmp = unserialize(file_get_contents("../private/passwd"));
	for($i = 0; $tmp[$i]; $i++)
		if ($login == $tmp[$i]['login'] &&
			hash("whirlpool", $passwd) == $tmp[$i]['passwd'])
			return (true);
	return (false);
}
?>