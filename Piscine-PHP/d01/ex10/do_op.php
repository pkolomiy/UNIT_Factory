#!/usr/bin/php
<?PHP
function check_oper($oper)
{
	if ($oper == 42 || $oper == 43 || $oper == 45 ||
		$oper == 47 || $oper == 37)
		return (1);
	return (0);
}

if ($argc == 4)
{
	$first = trim($argv[1]);
	$second = trim($argv[3]);
	$oper = trim($argv[2]);
	if (strlen($oper) == 1 && check_oper(ord($oper)) &&
		is_numeric($first) && is_numeric($second))
	{
		if (ord($oper) == 43) echo ($first + $second)."\n";
		if (ord($oper) == 45) echo ($first - $second)."\n";
		if (ord($oper) == 42) echo ($first * $second)."\n";
		if (ord($oper) == 47) echo ($first / $second)."\n";
		if (ord($oper) == 37) echo ($first % $second)."\n";
	}
	else
		print("Incorrect Parameters\n");
}
else
	print("Incorrect Parameters\n");
?>