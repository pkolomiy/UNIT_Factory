#!/usr/bin/php
<?PHP
if ($argc == 2 && $str = file_get_contents($argv[1]))
{
	$tmp = explode("//", $argv[1]);
	$ht = implode(array($tmp[0],"//"));
	$tmp = explode("/", $tmp[1]);
	$domain = $tmp[0];
	mkdir($domain);
	preg_match_all('/<img.*?>/s', $str, $arr);
	for ($i = 0; $arr[0][$i]; $i++)
		preg_match_all('/src=".*?"/', $arr[0][$i], $arr2[$i]);
	for ($i = 0; $arr2[$i]; $i++)
	{
		$tmp = explode("\"", $arr2[$i][0][0]);
		$arr[$i] = $tmp[1];
	}
	for ($i = 0; $arr[$i]; $i++)
	{
		preg_match('/[^\/]+\.[a-zA-Z]{3,4}$/', $arr[$i], $ptr[$i]);
		$vtr[$i] = $ptr[$i][0];
	}
	for ($i = 0, $j = 0; $arr[$i]; $i++)
	{
		if (!strncmp($arr[$i], $ht, strlen($ht)))
		{
			if ($vtr[$i])
				file_put_contents(implode(array($domain,"/",$vtr[$i])), file_get_contents($arr[$i]));
			else
				file_put_contents(implode(array($domain,"/","image ",$j++,".jpg")), file_get_contents($arr[$i]));
		}
		else
		{
			if ($vtr[$i])
			{
				if (ord($arr[$i][0]) == 47)
					file_put_contents(implode(array($domain,"/",$vtr[$i])), file_get_contents(implode(array($ht,$domain,$arr[$i]))));
				else
					file_put_contents(implode(array($domain,"/",$vtr[$i])), file_get_contents(implode(array($ht,$domain,"/",$arr[$i]))));;
			}
			else
				if (ord($arr[$i][0]) == 47)
					file_put_contents(implode(array($domain,"/","image ",$j++,".jpg")), file_get_contents(implode(array($ht,$domain,$arr[$i]))));
				else
					file_put_contents(implode(array($domain,"/","image ",$j++,".jpg")), file_get_contents(implode(array($ht,$domain,"/",$arr[$i]))));
		}
	}
}
?>