#!/usr/bin/php
<?PHP
if ($argc == 2)
{
	$arr = array_merge(array_diff(explode(' ', $argv[1]), array("")));
	for ($i = 0; $arr[$i]; $i++)
	{
		print("$arr[$i]");
		if ($arr[$i+1])
			print(" ");
	}
	print("\n");
}
?>