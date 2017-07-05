<?PHP
function ft_is_sort($tab)
{
	$arr = $tab;
	sort($tab);
	for ($i = 0; $arr[$i]; $i++)
		if (strcmp($arr[$i], $tab[$i]))
			return (false);
	return (true);
}
?>