$(document).ready(
	function()
	{
		map();
		function map()
		{
			//var elem = $('#row')[i];
			$('<div>')
				.attr('class','table')
				.appendTo('.shipboard');
			for (i = 0; i != 100; i++)
			{
				$('<div>')
					.attr('class','row')
					.attr('id','y'+i)
					.appendTo('.table');
				for (j = 0; j != 150; j++)
				{
					$('<div>')
						.attr('class','cell')
						.attr('id','x'+j+'y'+i)
						.html('&nbsp;&nbsp;&nbsp;&nbsp;')
						.appendTo('#y'+i);
				}
			}
			$.getJSON("obstacle.php", function(json){
				$.each(json, function(y,arr)
					   {
						   $.each(arr, function(x,z)
								  {
									  if (z == '1')
										  $('#x'+ x +'y'+ y).attr('class', 'cell-obstacle');
								  });
					   });
			});
			$('#x3y80').attr('class', 'cell-ship');
			$('#x4y80').attr('class', 'cell-ship');
			$('#x5y80').attr('class', 'cell-ship');
			$('#x20y90').attr('class', 'cell-ship');
			$('#x21y90').attr('class', 'cell-ship');
			$('#x22y90').attr('class', 'cell-ship');
			$('#x15y50').attr('class', 'cell-ship');
			$('#x16y50').attr('class', 'cell-ship');
			$('#x17y50').attr('class', 'cell-ship');
			$('#x140y10').attr('class', 'cell-ship');
			$('#x141y10').attr('class', 'cell-ship');
			$('#x142y10').attr('class', 'cell-ship');
			$('#x130y30').attr('class', 'cell-ship');
			$('#x131y30').attr('class', 'cell-ship');
			$('#x132y30').attr('class', 'cell-ship');
			$('#x110y10').attr('class', 'cell-ship');
			$('#x111y10').attr('class', 'cell-ship');
			$('#x112y10').attr('class', 'cell-ship');
		}
	});
