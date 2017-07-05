#!/usr/bin/php
<?PHP
print($argc > 1 ? $argv[1] = trim(preg_replace('/[ \t]+/', ' ', $argv[1]))."\n" : "");
?>