<?PHP
function ft_split($arr)
{
	$ret = explode(' ', $arr);
	$tmp = array_keys($ret, "");
	$i = -1;
	while($tmp[++$i])
		unset($ret[$tmp[$i]]);
	sort($ret);
	return ($ret);
}
?>