<?php

$str = explode("\n", file_get_contents('obstacle-map.txt'));

for($i = 0; $i != 100; $i++)
{
	$arr[$i] = explode(' ', $str[$i]);
	for($j = 0; $j != 150; $j++)
	{
		$ptr[$i][$j] = explode(',', $arr[$i][$j]);
		$vt[$i][$j] = $ptr[$i][$j][2];
	}
}

echo json_encode($vt);

?>