	 function random(id) {
	   document.getElementById(id).innerHTML = getRandomInt(1, 6);
	 }
	 function getRandomInt(min, max) {
       return Math.floor(Math.random() * (max - min + 1)) + min;
     }
