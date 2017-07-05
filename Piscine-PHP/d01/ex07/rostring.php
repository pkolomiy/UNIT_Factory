#!/usr/bin/php
<?PHP
if ($argc > 1)
{
	$arr = array_merge(array_diff(explode(' ', $argv[1]), array("")));
	for ($i = 1; $arr[$i]; $i++)
		print("$arr[$i] ");
	print("$arr[0]\n");
}
?>