function func()
{
	var get = prompt('TO DO','');
	if (get)
	{
		document.cookie=get + "=" + get + ";";
		wr(get);
	}
}

function getCookie(c_name)
{
	var i,x,y=Array(),R=document.cookie.split(";");

	for (i=0;i<R.length;i++)
		y[i] = R[i].substr(R[i].indexOf("=")+1);
	return unescape(y);
}

function list()
{
	var i,cc = document.cookie.split(";");
	for (i = 0; i < cc.length; i++)
		wr(cc[i].substr(cc[i].indexOf("=")+1));
}

function wr(get)
{
	var elem = document.getElementById('ft_list'),
		elem2 = document.createElement('div');
	elem2.innerText = get;
	elem2.setAttribute('style','background-color: #6fbfad; border-radius: 10px; margin-top: 10px;');
	elem2.addEventListener("click", function(){
		if (confirm("Are You Sure About That?"))
		{
			elem.removeChild(elem2);
			document.cookie=get + "=" + "" + ";";
		}}, false);
	elem.insertBefore(elem2, elem.firstChild);
}
