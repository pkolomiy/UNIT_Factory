#!/usr/bin/php
<?PHP
if ($argc == 2)
{
	$moi = array("janvier","fevrier","mars","avril","mai","juin","juillet",
				 "aout","septembre","octobre","novembre","decembre");
	date_default_timezone_set("Europe/Paris");
	if (preg_match('/^([Dd]imanche|[Ll]undi|[Mm](ardi|ercredi)|[Jj]eudi|[Vv]endredi|[Ss]amedi) [1-3]?[0-9] ([Jj]anvier|[Ff]evrier|[Mm][ars|ai]|[Aa]vril|[Jj][uin|uillet]|[Aa]out|([Ss]eptem|[Oo]cto|[Nn]ovem|[Dd]ecem)bre){1} [0-9]{4} ([01]?[0-9]|2[0-3])(:[0-5][0-9]){2}$/', $argv[1]))
	{
		$arr = explode(' ', $argv[1]);
		$arr[2][0] = ord($arr[2][0]) >= 65 && ord($arr[2][0]) <= 90 ?
			chr(ord($arr[2][0]) + 32) : $arr[2][0];
		for ($i = 0; !is_numeric($arr[2]); $i++)
			$arr[2] = $moi[$i] === $arr[2] ? $i + 1 : $arr[2];
		print($arr[1] < 32 ? strtotime("$arr[1]-$arr[2]-$arr[3] $arr[4]")."\n" :
			  "Wrong Format\n");
	}
	else
		print("Wrong Format\n");
}
?>