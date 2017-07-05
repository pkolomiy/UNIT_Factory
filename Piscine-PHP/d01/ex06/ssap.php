#!/usr/bin/php
<?PHP
if ($argc > 1)
{
	for ($i = 1, $arr = array(); $argv[$i]; $i++)
		$arr = array_merge($arr, array_diff(explode(' ', $argv[$i]), array("")));
	sort($arr);
	for ($i = 0; $arr[$i]; $i++)
		print("$arr[$i]\n");
}
?>