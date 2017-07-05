<?php
class House
{
	function introduce()
	{
		print 'House '.$this->getHouseName().' of '.$this->getHouseSeat().' : "'.$this->getHouseMotto().'"'."\n";
	}
}
?>