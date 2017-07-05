#!/usr/bin/php
<?PHP
$fd = fopen("/var/run/utmpx", 'r');
date_default_timezone_set("Europe/Kiev");
for ($i = 0; $str = fread($fd, 628); $i++)
	$dar[$i] = unpack("Z256login/Z4id/Z32tty/ipid/itype/Itime", $str);
sort($dar);
foreach($dar as $arr)
	print($arr["type"] == 7 ? $arr["login"]." ".$arr["tty"]."  ".date('M  j H:i',$arr["time"])." \n" : "");
?>