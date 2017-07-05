#!/usr/bin/php
<?PHP

while (1)
{
	print("Enter a number: ");
	$fd = fgets(STDIN);
	if (!$fd)
	{
		print("^D\n");
		break;
	}
	if (is_numeric(($nbr = trim($fd))))
	{
		if ((!($nbr % 2) || !($nbr)) && $nbr > -1)
			print("The number $nbr is even\n");
		else if ($nbr < 0)
			print("The number $nbr is negative\n");
		else
			print("The number $nbr is odd\n");
	}
	else
		print("'$nbr' is not a number\n");
}

?>