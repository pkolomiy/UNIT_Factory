<?php
abstract class Fighter
{
	private $_f;
	function __construct($f){$this->_f = $f;}
	function getType(){return $this->_f;}
	abstract function fight($target);
}
?>