#!/usr/bin/php
<?PHP
if ($argc == 2 && is_readable($argv[1]))
	print(preg_replace_callback('/<a.*>.*<\/a>/si',function($arr){return(preg_replace_callback('/title=".*"|>(?s).*?</i',function($arr){return(preg_replace_callback('/".*"|>(?s).*?</',function ($arr){return (strtoupper($arr[0]));},$arr[0]));},$arr[0]));},file_get_contents($argv[1])));
?>