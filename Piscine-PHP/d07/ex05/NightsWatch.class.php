<?php
class NightsWatch
{
	function fight(){}
	function recruit($jon){ if ($jon instanceof IFighter)$jon->fight();}
}
?>