#!/usr/bin/php
<?PHP
if ($argc > 1)
{
	$look = $argv[1];
	unset($argv[0]);
	unset($argv[1]);
	$argv = array_merge($argv);
	for ($i = count($argv) - 1; $i != -1; $i--)
	{
		$str = explode(":", $argv[$i]);
		if (!strcmp($look, $str[0]))
		{
			print("$str[1]\n");
			break;
		}
	}
}
?>