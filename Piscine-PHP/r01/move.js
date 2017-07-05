$(document).ready(
	function()
	{
		var sm1 = [[3,80],[4,80],[5,80]],
			sm2 = [[20,90],[21,90],[22,90]],
			sm3 = [[15,50],[16,50],[17,50]],
			sm4 = [[140,10],[141,10],[142,10]],
			sm5 = [[130,30],[131,30],[132,30]],
			sm6 = [[110,10],[111,10],[112,10]];
		var t1=1,t2=1,t3=1,t4=1,t5=1,t6=1;
		var ship = 1;
		function small_turn_1(i)
		{
			$('#x' + sm1[0][0] + 'y' + sm1[0][1]).attr('class', 'cell');
			$('#x' + sm1[1][0] + 'y' + sm1[1][1]).attr('class', 'cell');
			$('#x' + sm1[2][0] + 'y' + sm1[2][1]).attr('class', 'cell');
			sm1[0][0] = i ? ((t1 == 1 || t1 == 4) ? sm1[0][0] - 1 : sm1[0][0] + 1) :
			((t1 == 1 || t1 == 3) ? sm1[0][0] - 1 : sm1[0][0] + 1);
			sm1[0][1] = i ? ((t1 == 1 || t1 == 3) ? sm1[0][1] + 1 : sm1[0][1] - 1) :
			((t1 == 2 || t1 == 3) ? sm1[0][1] + 1 : sm1[0][1] - 1);
			sm1[2][0] = i ? ((t1 == 1 || t1 == 4) ? sm1[2][0] + 1 : sm1[2][0] - 1) :
			((t1 == 1 || t1 == 3) ? sm1[2][0] + 1 : sm1[2][0] - 1);
			sm1[2][1] = i ? ((t1 == 1 || t1 == 3) ? sm1[2][1] - 1 : sm1[2][1] + 1) :
			((t1 == 2 || t1 == 3) ? sm1[2][1] - 1 : sm1[2][1] + 1);
			$('#x' + sm1[0][0] + 'y' + sm1[0][1]).attr('class', 'cell-ship');
			$('#x' + sm1[1][0] + 'y' + sm1[1][1]).attr('class', 'cell-ship');
			$('#x' + sm1[2][0] + 'y' + sm1[2][1]).attr('class', 'cell-ship');
		}
		function small_turn_2(i)
		{
			$('#x' + sm2[0][0] + 'y' + sm2[0][1]).attr('class', 'cell');
			$('#x' + sm2[1][0] + 'y' + sm2[1][1]).attr('class', 'cell');
			$('#x' + sm2[2][0] + 'y' + sm2[2][1]).attr('class', 'cell');
			sm2[0][0] = i ? ((t2 == 1 || t2 == 4) ? sm2[0][0] - 1 : sm2[0][0] + 1) :
			((t2 == 1 || t2 == 3) ? sm2[0][0] - 1 : sm2[0][0] + 1);
			sm2[0][1] = i ? ((t2 == 1 || t2 == 3) ? sm2[0][1] + 1 : sm2[0][1] - 1) :
			((t2 == 2 || t2 == 3) ? sm2[0][1] + 1 : sm2[0][1] - 1);
			sm2[2][0] = i ? ((t2 == 1 || t2 == 4) ? sm2[2][0] + 1 : sm2[2][0] - 1) :
			((t2 == 1 || t2 == 3) ? sm2[2][0] + 1 : sm2[2][0] - 1);
			sm2[2][1] = i ? ((t2 == 1 || t2 == 3) ? sm2[2][1] - 1 : sm2[2][1] + 1) :
			((t2 == 2 || t2 == 3) ? sm2[2][1] - 1 : sm2[2][1] + 1);
			$('#x' + sm2[0][0] + 'y' + sm2[0][1]).attr('class', 'cell-ship');
			$('#x' + sm2[1][0] + 'y' + sm2[1][1]).attr('class', 'cell-ship');
			$('#x' + sm2[2][0] + 'y' + sm2[2][1]).attr('class', 'cell-ship');
		}
		function small_turn_3(i)
		{
			$('#x' + sm3[0][0] + 'y' + sm3[0][1]).attr('class', 'cell');
			$('#x' + sm3[1][0] + 'y' + sm3[1][1]).attr('class', 'cell');
			$('#x' + sm3[2][0] + 'y' + sm3[2][1]).attr('class', 'cell');
			sm3[0][0] = i ? ((t3 == 1 || t3 == 4) ? sm3[0][0] - 1 : sm3[0][0] + 1) :
			((t3 == 1 || t3 == 3) ? sm3[0][0] - 1 : sm3[0][0] + 1);
			sm3[0][1] = i ? ((t3 == 1 || t3 == 3) ? sm3[0][1] + 1 : sm3[0][1] - 1) :
			((t3 == 2 || t3 == 3) ? sm3[0][1] + 1 : sm3[0][1] - 1);
			sm3[2][0] = i ? ((t3 == 1 || t3 == 4) ? sm3[2][0] + 1 : sm3[2][0] - 1) :
			((t3 == 1 || t3 == 3) ? sm3[2][0] + 1 : sm3[2][0] - 1);
			sm3[2][1] = i ? ((t3 == 1 || t3 == 3) ? sm3[2][1] - 1 : sm3[2][1] + 1) :
			((t3 == 2 || t3 == 3) ? sm3[2][1] - 1 : sm3[2][1] + 1);
			$('#x' + sm3[0][0] + 'y' + sm3[0][1]).attr('class', 'cell-ship');
			$('#x' + sm3[1][0] + 'y' + sm3[1][1]).attr('class', 'cell-ship');
			$('#x' + sm3[2][0] + 'y' + sm3[2][1]).attr('class', 'cell-ship');
		}
		function small_turn_4(i)
		{
			$('#x' + sm4[0][0] + 'y' + sm4[0][1]).attr('class', 'cell');
			$('#x' + sm4[1][0] + 'y' + sm4[1][1]).attr('class', 'cell');
			$('#x' + sm4[2][0] + 'y' + sm4[2][1]).attr('class', 'cell');
			sm4[0][0] = i ? ((t4 == 1 || t4 == 4) ? sm4[0][0] - 1 : sm4[0][0] + 1) :
			((t4 == 1 || t4 == 3) ? sm4[0][0] - 1 : sm4[0][0] + 1);
			sm4[0][1] = i ? ((t4 == 1 || t4 == 3) ? sm4[0][1] + 1 : sm4[0][1] - 1) :
			((t4 == 2 || t4 == 3) ? sm4[0][1] + 1 : sm4[0][1] - 1);
			sm4[2][0] = i ? ((t4 == 1 || t4 == 4) ? sm4[2][0] + 1 : sm4[2][0] - 1) :
			((t4 == 1 || t4 == 3) ? sm4[2][0] + 1 : sm4[2][0] - 1);
			sm4[2][1] = i ? ((t4 == 1 || t4 == 3) ? sm4[2][1] - 1 : sm4[2][1] + 1) :
			((t4 == 2 || t4 == 3) ? sm4[2][1] - 1 : sm4[2][1] + 1);
			$('#x' + sm4[0][0] + 'y' + sm4[0][1]).attr('class', 'cell-ship');
			$('#x' + sm4[1][0] + 'y' + sm4[1][1]).attr('class', 'cell-ship');
			$('#x' + sm4[2][0] + 'y' + sm4[2][1]).attr('class', 'cell-ship');
		}
		function small_turn_5(i)
		{
			$('#x' + sm5[0][0] + 'y' + sm5[0][1]).attr('class', 'cell');
			$('#x' + sm5[1][0] + 'y' + sm5[1][1]).attr('class', 'cell');
			$('#x' + sm5[2][0] + 'y' + sm5[2][1]).attr('class', 'cell');
			sm5[0][0] = i ? ((t5 == 1 || t5 == 4) ? sm5[0][0] - 1 : sm5[0][0] + 1) :
			((t5 == 1 || t5 == 3) ? sm5[0][0] - 1 : sm5[0][0] + 1);
			sm5[0][1] = i ? ((t5 == 1 || t5 == 3) ? sm5[0][1] + 1 : sm5[0][1] - 1) :
			((t5 == 2 || t5 == 3) ? sm5[0][1] + 1 : sm5[0][1] - 1);
			sm5[2][0] = i ? ((t5 == 1 || t5 == 4) ? sm5[2][0] + 1 : sm5[2][0] - 1) :
			((t5 == 1 || t5 == 3) ? sm5[2][0] + 1 : sm5[2][0] - 1);
			sm5[2][1] = i ? ((t5 == 1 || t5 == 3) ? sm5[2][1] - 1 : sm5[2][1] + 1) :
			((t5 == 2 || t5 == 3) ? sm5[2][1] - 1 : sm5[2][1] + 1);
			$('#x' + sm5[0][0] + 'y' + sm5[0][1]).attr('class', 'cell-ship');
			$('#x' + sm5[1][0] + 'y' + sm5[1][1]).attr('class', 'cell-ship');
			$('#x' + sm5[2][0] + 'y' + sm5[2][1]).attr('class', 'cell-ship');
		}
		function small_turn_6(i)
		{
			$('#x' + sm6[0][0] + 'y' + sm6[0][1]).attr('class', 'cell');
			$('#x' + sm6[1][0] + 'y' + sm6[1][1]).attr('class', 'cell');
			$('#x' + sm6[2][0] + 'y' + sm6[2][1]).attr('class', 'cell');
			sm6[0][0] = i ? ((t6 == 1 || t6 == 4) ? sm6[0][0] - 1 : sm6[0][0] + 1) :
			((t6 == 1 || t6 == 3) ? sm6[0][0] - 1 : sm6[0][0] + 1);
			sm6[0][1] = i ? ((t6 == 1 || t6 == 3) ? sm6[0][1] + 1 : sm6[0][1] - 1) :
			((t6 == 2 || t6 == 3) ? sm6[0][1] + 1 : sm6[0][1] - 1);
			sm6[2][0] = i ? ((t6 == 1 || t6 == 4) ? sm6[2][0] + 1 : sm6[2][0] - 1) :
			((t6 == 1 || t6 == 3) ? sm6[2][0] + 1 : sm6[2][0] - 1);
			sm6[2][1] = i ? ((t6 == 1 || t6 == 3) ? sm6[2][1] - 1 : sm6[2][1] + 1) :
			((t6 == 2 || t6 == 3) ? sm6[2][1] - 1 : sm6[2][1] + 1);
			$('#x' + sm6[0][0] + 'y' + sm6[0][1]).attr('class', 'cell-ship');
			$('#x' + sm6[1][0] + 'y' + sm6[1][1]).attr('class', 'cell-ship');
			$('#x' + sm6[2][0] + 'y' + sm6[2][1]).attr('class', 'cell-ship');
		}
		function move_small_1()
		{
			if ($('#x' + (sm1[2][0] + 1) + 'y' + sm1[2][1]).attr('class') != 'cell-obstacle' && (sm1[2][0] + 1 < 150) && (sm1[2][1] + 1 < 100) &&
				(sm1[2][0] - 1 >= 0) && (sm1[2][1] - 1 >= 0))
			{
				$('#x' + sm1[0][0] + 'y' + sm1[0][1]).attr('class', 'cell');
				$('#x' + sm1[1][0] + 'y' + sm1[1][1]).attr('class', 'cell');
				$('#x' + sm1[2][0] + 'y' + sm1[2][1]).attr('class', 'cell');
				sm1[0][0] = t1 == 1 ? sm1[0][0] + 1 :
					(t1 == 2 ? sm1[0][0] - 1 : sm1[0][0]);
				sm1[0][1] = t1 == 4 ? sm1[0][1] + 1 :
					(t1 == 3 ? sm1[0][1] - 1 : sm1[0][1]);
				sm1[1][0] = t1 == 1 ? sm1[1][0] + 1 :
					(t1 == 2 ? sm1[1][0] - 1 : sm1[1][0]);
				sm1[1][1] = t1 == 4 ? sm1[1][1] + 1 :
					(t1 == 3 ? sm1[1][1] - 1 : sm1[1][1]);
				sm1[2][0] = t1 == 1 ? sm1[2][0] + 1 :
					(t1 == 2 ? sm1[2][0] - 1 : sm1[2][0]);
				sm1[2][1] = t1 == 4 ? sm1[2][1] + 1 :
					(t1 == 3 ? sm1[2][1] - 1 : sm1[2][1]);
				$('#x' + sm1[0][0] + 'y' + sm1[0][1]).attr('class', 'cell-ship');
				$('#x' + sm1[1][0] + 'y' + sm1[1][1]).attr('class', 'cell-ship');
				$('#x' + sm1[2][0] + 'y' + sm1[2][1]).attr('class', 'cell-ship');
			}
		}
		function move_small_2()
		{
			if ($('#x' + (sm2[2][0] + 1) + 'y' + sm2[2][1]).attr('class') != 'cell-obstacle' && (sm2[2][0] + 1 < 150) && (sm2[2][1] + 1 < 100) &&
				(sm2[2][0] - 1 >= 0) && (sm2[2][1] - 1 >= 0))
			{
				$('#x' + sm2[0][0] + 'y' + sm2[0][1]).attr('class', 'cell');
				$('#x' + sm2[1][0] + 'y' + sm2[1][1]).attr('class', 'cell');
				$('#x' + sm2[2][0] + 'y' + sm2[2][1]).attr('class', 'cell');
				sm2[0][0] = t2 == 1 ? sm2[0][0] + 1 :
					(t2 == 2 ? sm2[0][0] - 1 : sm2[0][0]);
				sm2[0][1] = t2 == 4 ? sm2[0][1] + 1 :
					(t2 == 3 ? sm2[0][1] - 1 : sm2[0][1]);
				sm2[1][0] = t2 == 1 ? sm2[1][0] + 1 :
					(t2 == 2 ? sm2[1][0] - 1 : sm2[1][0]);
				sm2[1][1] = t2 == 4 ? sm2[1][1] + 1 :
					(t2 == 3 ? sm2[1][1] - 1 : sm2[1][1]);
				sm2[2][0] = t2 == 1 ? sm2[2][0] + 1 :
					(t2 == 2 ? sm2[2][0] - 1 : sm2[2][0]);
				sm2[2][1] = t2 == 4 ? sm2[2][1] + 1 :
					(t2 == 3 ? sm2[2][1] - 1 : sm2[2][1]);
				$('#x' + sm2[0][0] + 'y' + sm2[0][1]).attr('class', 'cell-ship');
				$('#x' + sm2[1][0] + 'y' + sm2[1][1]).attr('class', 'cell-ship');
				$('#x' + sm2[2][0] + 'y' + sm2[2][1]).attr('class', 'cell-ship');
			}
		}
		function move_small_3()
		{
			if ($('#x' + (sm3[2][0] + 1) + 'y' + sm3[2][1]).attr('class') != 'cell-obstacle' && (sm3[2][0] + 1 < 150) && (sm3[2][1] + 1 < 100) &&
				(sm3[2][0] - 1 >= 0) && (sm3[2][1] - 1 >= 0))
			{
				$('#x' + sm3[0][0] + 'y' + sm3[0][1]).attr('class', 'cell');
				$('#x' + sm3[1][0] + 'y' + sm3[1][1]).attr('class', 'cell');
				$('#x' + sm3[2][0] + 'y' + sm3[2][1]).attr('class', 'cell');
				sm3[0][0] = t3 == 1 ? sm3[0][0] + 1 :
					(t3 == 2 ? sm3[0][0] - 1 : sm3[0][0]);
				sm3[0][1] = t3 == 4 ? sm3[0][1] + 1 :
					(t3 == 3 ? sm3[0][1] - 1 : sm3[0][1]);
				sm3[1][0] = t3 == 1 ? sm3[1][0] + 1 :
					(t3 == 2 ? sm3[1][0] - 1 : sm3[1][0]);
				sm3[1][1] = t3 == 4 ? sm3[1][1] + 1 :
					(t3 == 3 ? sm3[1][1] - 1 : sm3[1][1]);
				sm3[2][0] = t3 == 1 ? sm3[2][0] + 1 :
					(t3 == 2 ? sm3[2][0] - 1 : sm3[2][0]);
				sm3[2][1] = t3 == 4 ? sm3[2][1] + 1 :
					(t3 == 3 ? sm3[2][1] - 1 : sm3[2][1]);
				$('#x' + sm3[0][0] + 'y' + sm3[0][1]).attr('class', 'cell-ship');
				$('#x' + sm3[1][0] + 'y' + sm3[1][1]).attr('class', 'cell-ship');
				$('#x' + sm3[2][0] + 'y' + sm3[2][1]).attr('class', 'cell-ship');
			}
		}
		function move_small_4()
		{
			if ($('#x' + (sm4[2][0] + 1) + 'y' + sm4[2][1]).attr('class') != 'cell-obstacle' && (sm4[2][0] + 1 < 150) && (sm4[2][1] + 1 < 100) &&
				(sm4[2][0] - 1 >= 0) && (sm4[2][1] - 1 >= 0))
			{
				$('#x' + sm4[0][0] + 'y' + sm4[0][1]).attr('class', 'cell');
				$('#x' + sm4[1][0] + 'y' + sm4[1][1]).attr('class', 'cell');
				$('#x' + sm4[2][0] + 'y' + sm4[2][1]).attr('class', 'cell');
				sm4[0][0] = t4 == 1 ? sm4[0][0] + 1 :
					(t4 == 2 ? sm4[0][0] - 1 : sm4[0][0]);
				sm4[0][1] = t4 == 4 ? sm4[0][1] + 1 :
					(t4 == 3 ? sm4[0][1] - 1 : sm4[0][1]);
				sm4[1][0] = t4 == 1 ? sm4[1][0] + 1 :
					(t4 == 2 ? sm4[1][0] - 1 : sm4[1][0]);
				sm4[1][1] = t4 == 4 ? sm4[1][1] + 1 :
					(t4 == 3 ? sm4[1][1] - 1 : sm4[1][1]);
				sm4[2][0] = t4 == 1 ? sm4[2][0] + 1 :
					(t4 == 2 ? sm4[2][0] - 1 : sm4[2][0]);
				sm4[2][1] = t4 == 4 ? sm4[2][1] + 1 :
					(t4 == 3 ? sm4[2][1] - 1 : sm4[2][1]);
				$('#x' + sm4[0][0] + 'y' + sm4[0][1]).attr('class', 'cell-ship');
				$('#x' + sm4[1][0] + 'y' + sm4[1][1]).attr('class', 'cell-ship');
				$('#x' + sm4[2][0] + 'y' + sm4[2][1]).attr('class', 'cell-ship');
			}
		}
		function move_small_5()
		{
			if ($('#x' + (sm5[2][0] + 1) + 'y' + sm5[2][1]).attr('class') != 'cell-obstacle' && (sm5[2][0] + 1 < 150) && (sm5[2][1] + 1 < 100) &&
				(sm5[2][0] - 1 >= 0) && (sm5[2][1] - 1 >= 0))
			{
				$('#x' + sm5[0][0] + 'y' + sm5[0][1]).attr('class', 'cell');
				$('#x' + sm5[1][0] + 'y' + sm5[1][1]).attr('class', 'cell');
				$('#x' + sm5[2][0] + 'y' + sm5[2][1]).attr('class', 'cell');
				sm5[0][0] = t5 == 1 ? sm5[0][0] + 1 :
					(t5 == 2 ? sm5[0][0] - 1 : sm5[0][0]);
				sm5[0][1] = t5 == 4 ? sm5[0][1] + 1 :
					(t5 == 3 ? sm5[0][1] - 1 : sm5[0][1]);
				sm5[1][0] = t5 == 1 ? sm5[1][0] + 1 :
					(t5 == 2 ? sm5[1][0] - 1 : sm5[1][0]);
				sm5[1][1] = t5 == 4 ? sm5[1][1] + 1 :
					(t5 == 3 ? sm5[1][1] - 1 : sm5[1][1]);
				sm5[2][0] = t5 == 1 ? sm5[2][0] + 1 :
					(t5 == 2 ? sm5[2][0] - 1 : sm5[2][0]);
				sm5[2][1] = t5 == 4 ? sm5[2][1] + 1 :
					(t5 == 3 ? sm5[2][1] - 1 : sm5[2][1]);
				$('#x' + sm5[0][0] + 'y' + sm5[0][1]).attr('class', 'cell-ship');
				$('#x' + sm5[1][0] + 'y' + sm5[1][1]).attr('class', 'cell-ship');
				$('#x' + sm5[2][0] + 'y' + sm5[2][1]).attr('class', 'cell-ship');
			}
		}
		function move_small_6()
		{
			if ($('#x' + (sm6[2][0] + 1) + 'y' + sm6[2][1]).attr('class') != 'cell-obstacle' && (sm6[2][0] + 1 < 150) && (sm6[2][1] + 1 < 100) &&
				(sm6[2][0] - 1 >= 0) && (sm6[2][1] - 1 >= 0))
			{
				$('#x' + sm6[0][0] + 'y' + sm6[0][1]).attr('class', 'cell');
				$('#x' + sm6[1][0] + 'y' + sm6[1][1]).attr('class', 'cell');
				$('#x' + sm6[2][0] + 'y' + sm6[2][1]).attr('class', 'cell');
				sm6[0][0] = t6 == 1 ? sm6[0][0] + 1 :
					(t6 == 2 ? sm6[0][0] - 1 : sm6[0][0]);
				sm6[0][1] = t6 == 4 ? sm6[0][1] + 1 :
					(t6 == 3 ? sm6[0][1] - 1 : sm6[0][1]);
				sm6[1][0] = t6 == 1 ? sm6[1][0] + 1 :
					(t6 == 2 ? sm6[1][0] - 1 : sm6[1][0]);
				sm6[1][1] = t6 == 4 ? sm6[1][1] + 1 :
					(t6 == 3 ? sm6[1][1] - 1 : sm6[1][1]);
				sm6[2][0] = t6 == 1 ? sm6[2][0] + 1 :
					(t6 == 2 ? sm6[2][0] - 1 : sm6[2][0]);
				sm6[2][1] = t6 == 4 ? sm6[2][1] + 1 :
					(t6 == 3 ? sm6[2][1] - 1 : sm6[2][1]);
				$('#x' + sm6[0][0] + 'y' + sm6[0][1]).attr('class', 'cell-ship');
				$('#x' + sm6[1][0] + 'y' + sm6[1][1]).attr('class', 'cell-ship');
				$('#x' + sm6[2][0] + 'y' + sm6[2][1]).attr('class', 'cell-ship');
			}
		}
		$("#ship1").click(function (){
			$("#ship1").attr('src' , 'small-r.png');
			$("#ship2").attr('src' , 'small.png');
			$("#ship3").attr('src' , 'small.png');
			$("#ship4").attr('src' , 'small.png');
			$("#ship5").attr('src' , 'small.png');
			$("#ship6").attr('src' , 'small.png');
			ship = 1
									 });
		$("#ship2").click(function (){
			$("#ship2").attr('src' , 'small-r.png');
			$("#ship1").attr('src' , 'small.png');
			$("#ship3").attr('src' , 'small.png');
			$("#ship4").attr('src' , 'small.png');
			$("#ship5").attr('src' , 'small.png');
			$("#ship6").attr('src' , 'small.png');
			ship = 2
		});
		$("#ship3").click(function (){
			$("#ship3").attr('src' , 'small-r.png');
			$("#ship2").attr('src' , 'small.png');
			$("#ship1").attr('src' , 'small.png');
			$("#ship4").attr('src' , 'small.png');
			$("#ship5").attr('src' , 'small.png');
			$("#ship6").attr('src' , 'small.png');
			ship = 3});
		$("#ship4").click(function (){
			$("#ship4").attr('src' , 'small-r.png');
			$("#ship2").attr('src' , 'small.png');
			$("#ship3").attr('src' , 'small.png');
			$("#ship1").attr('src' , 'small.png');
			$("#ship5").attr('src' , 'small.png');
			$("#ship6").attr('src' , 'small.png');
			ship = 4});
		$("#ship5").click(function (){
			$("#ship5").attr('src' , 'small-r.png');
			$("#ship2").attr('src' , 'small.png');
			$("#ship3").attr('src' , 'small.png');
			$("#ship4").attr('src' , 'small.png');
			$("#ship1").attr('src' , 'small.png');
			$("#ship6").attr('src' , 'small.png');
			ship = 5});
		$("#ship6").click(function (){
			$("#ship6").attr('src' , 'small-r.png');
			$("#ship2").attr('src' , 'small.png');
			$("#ship3").attr('src' , 'small.png');
			$("#ship4").attr('src' , 'small.png');
			$("#ship5").attr('src' , 'small.png');
			$("#ship1").attr('src' , 'small.png');
			ship = 6});
		$("#go-left").click(function ()
					   {
						   var x = parseInt($('#rubik-left').html());
						   if (x)
						   {
							   $('#rubik-left').html(x - 1);
							   if (ship == 1)
								   move_small_1();
							   else if (ship == 2)
								   move_small_2();
							   else if (ship == 3)
								   move_small_3();
						   }
					   });
		$("#cwturn-left").click(function ()
								{
									if (ship == 1)
									{
										t1 = t1 == 1 ? 3 : (t1 == 3 ? 2 : (t1 == 2 ? 4 : 1));
										small_turn_1(1);
									}
									else if (ship == 2)
									{
										t2 = t2 == 1 ? 3 : (t2 == 3 ? 2 : (t2 == 2 ? 4 : 1));
										small_turn_2(1);
									}
									else if (ship == 3)
									{
										t3 = t3 == 1 ? 3 : (t3 == 3 ? 2 : (t3 == 2 ? 4 : 1));
										small_turn_3(1);
									}
								});
		$("#wturn-left").click(function ()
						   {
							   if (ship == 1)
							   {
								   t1 = t1 == 1 ? 4 : (t1 == 3 ? 1 : (t1 == 2 ? 3 : 2));
								   small_turn_1(0);
							   }
							   else if (ship == 2)
							   {
								   t2 = t2 == 1 ? 4 : (t2 == 3 ? 1 : (t2 == 2 ? 3 : 2));
								   small_turn_2(0);
							   }
							   else if (ship == 3)
							   {
								   t3 = t3 == 1 ? 4 : (t3 == 3 ? 1 : (t3 == 2 ? 3 : 2));
								   small_turn_3(0);
							   }
						   });
		$("#go-right").click(function ()
					   {
						   var y = parseInt($('#rubik-right').html());
						   if (y)
						   {
							   $('#rubik-right').html(y - 1);
							   if (ship == 4)
								   move_small_4();
							   else if (ship == 5)
								   move_small_5();
							   else if (ship == 6)
								   move_small_6();
						   }
					   });
		$("#cwturn-right").click(function ()
						   {
							   if (ship == 4)
							   {
								   t4 = t4 == 1 ? 3 : (t4 == 3 ? 2 : (t4 == 2 ? 4 : 1));
								   small_turn_4(1);
							   }
							   else if (ship == 5)
							   {
								   t5 = t5 == 1 ? 3 : (t5 == 3 ? 2 : (t5 == 2 ? 4 : 1));
								   small_turn_5(1);
							   }
							   else if (ship == 6)
							   {
								   t6 = t6 == 1 ? 3 : (t6 == 3 ? 2 : (t6 == 2 ? 4 : 1));
								   small_turn_6(1);
							   }
						   });
		$("#wturn-right").click(function ()
						   {
							   if (ship == 4)
							   {
								   t4 = t4 == 1 ? 4 : (t4 == 3 ? 1 : (t4 == 2 ? 3 : 2));
								   small_turn_4(0);
							   }
							   else if (ship == 5)
							   {
								   t5 = t5 == 1 ? 4 : (t5 == 3 ? 1 : (t5 == 2 ? 3 : 2));
								   small_turn_5(0);
							   }
							   else if (ship == 6)
							   {
								   t6 = t6 == 1 ? 4 : (t6 == 3 ? 1 : (t6 == 2 ? 3 : 2));
								   small_turn_6(0);
							   }
						   });
		$("#at1").click(function ()
					   {
	alert('This is a DEMO. Buy full license to see full game - 1500$!');

					   });
		$("#at2").click(function ()
						{
							alert('This is a DEMO. Buy full license to see full game - 1500$!');


					   });
	});
