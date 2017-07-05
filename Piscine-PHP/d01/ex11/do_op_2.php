#!/usr/bin/php
<?PHP
function do_op($str)
{
	if (count($arr = explode("+", $str)) == 2){
		if (is_numeric($arr[0]) && is_numeric($arr[1]))
			return ($arr[0] + $arr[1]);}
	else if (count($arr = explode("*", $str)) > 1){
		if (is_numeric($arr[0]) && is_numeric($arr[1]))
			return ($arr[0] * $arr[1]);}
	else if (count($arr = explode("/", $str)) == 2){
		if (is_numeric($arr[0]) && is_numeric($arr[1]))
			return ($arr[0] / $arr[1]);}
	else if (count($arr = explode("%", $str)) == 2){
		if (is_numeric($arr[0]) && is_numeric($arr[1]))
			return ($arr[0] % $arr[1]);}
	else if (($i = count($arr = explode("-", $str))) >= 2 && $i <= 4){
		if (is_numeric($arr[0]) && is_numeric($arr[1]))
			return ($arr[0] - $arr[1]);
		else if ($arr[1] == "" && is_numeric($arr[0]) && is_numeric($arr[2]))
			return ($arr[0] + $arr[2]);
		else if ($arr[0] == "" && is_numeric($arr[1]) && is_numeric($arr[2]))
			return (-$arr[1] - $arr[2]);
		else if ($arr[0] == "" && is_numeric($arr[1]) &&
				 $arr[2] == "" && is_numeric($arr[3]))
			return (-$arr[1] + $arr[3]);}
	return ("Syntax Error");
}

if ($argc == 2)
{
	$arr = array_merge(array_diff(explode(" ", $argv[1]), array("")));
	if (count($arr) == 1)
		echo do_op($arr[0])."\n";
	else if (count($arr) > 1)
		echo do_op(implode($arr))."\n";
	else
		print("Syntax Error\n");
}
else
	print("Incorrect Parameters\n");
?>