<?php
require_once 'Fighter.class.php';
class UnholyFactory
{
	private $_arr = array();
	function absorb($new)
	{
		if (!($new instanceof Fighter))
			print "(Factory can't absorb this, it's not a fighter)\n";
		else if (array_key_exists($new->getType(), $this->_arr))
			print "(Factory already absorbed a fighter of type ".$new->getType().")\n";
		else
		{
			$this->_arr[$new->getType()] = $new;
			print "(Factory absorbed a fighter of type ".$new->getType().")\n";
		}
	}
	function fabricate($rf)
	{
		if (array_key_exists($rf, $this->_arr))
		{
			print "(Factory fabricates a fighter of type ".$rf.")\n";
			return $this->_arr[$rf];
		}
		print "(Factory hasn't absorbed any fighter of type ".$rf.")\n";
		return null;
	}
}
?>