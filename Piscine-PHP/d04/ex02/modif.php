<?php
function valid($post)
{
	$tmp = unserialize(file_get_contents("../private/passwd"));
	for($i = 0; $tmp[$i]; $i++)
		if ($post['login'] == $tmp[$i]['login'] &&
			hash("whirlpool", $post['oldpw']) == $tmp[$i]['passwd'])
		{
			$tmp[$i]['passwd'] = hash("whirlpool", $post['newpw']);
			file_put_contents("../private/passwd",  serialize($tmp));
			return (true);
		}
	return (false);
}
echo ($_POST['oldpw'] !== "" && $_POST['newpw'] !== "" &&
	$_POST['login'] !== "" && $_POST['submit'] == "OK" && valid($_POST) ?
	  "OK\n" : "ERROR\n");
?>