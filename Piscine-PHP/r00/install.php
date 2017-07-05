<?php

function ft_get_data()
{
	$tmp = explode("\n", file_get_contents("resourses/database.csv"));
	for($i = 1, $j = 0; $tmp[$i]; $i++,$j++)
	{
		$arr = explode(",", $tmp[$i]);
		$get[$j]['name'] = $arr[0];
		$get[$j]['price'] = $arr[1];
		$get[$j]['desc'] = $arr[2];
		$get[$j]['img'] = $arr[3];
		$get[$j]['category'] = $arr[4];
	}
	return ($get);
}

function ft_list_categories($get)
{
	for($i = 0; $get[$i]; $i++)
		$arr[$i] = $get[$i]['category'];
	return (array_merge(array_unique($arr)));
}

function ft_put_data($get)
{
	$get = array_merge(array("name,price,desc,img,category"), $get);
	for($i = 1; $get[$i]; $i++)
		$get[$i] = implode(",", $get[$i]);
	file_put_contents("resourses/database.csv", implode("\n", $get));
}

?>
