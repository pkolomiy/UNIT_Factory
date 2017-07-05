<?php
class Jaime extends Lannister
{
	function sleepWith($t)
	{
		if ($t instanceof Cersei)
			print "With pleasure, but only in a tower in Winterfell, then.\n";
		else
			parent::sleepWith($t);
	}
}
?>