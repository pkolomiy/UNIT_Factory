<?php
	include "install.php";

	session_start();
	
	function ft_add_goods() {
		$_SESSION['price'] = 0;
		foreach ($_SESSION['basket'] as $pr) {
			$_SESSION['price'] = $_SESSION['price'] + $pr["price"];
			echo ('<div id="account-field">
						<p class="category-text">'.$pr["name"].'</p>
						<img class="category-img" src="resourses/'.$pr["img"].'">
						<p class="price-text">'.$pr["price"].' $</p>
						<p class="description-text"></p><br>
					</div>');
		}
	}
?>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Sport.unit</title>
	<link rel="stylesheet" href="styles.css">
</head>
<body>
	<div id = "main_list">
		<div id = "main_name">
			<p id = "name">UNIT SPORT</p>
		</div>
		<div id="header">
			<a class="button-wrap" style="margin-left: 2px" href="index.php">
				<div class="button">
					<p class="button-text">Back</p>
				</div>
			</a>
		</div>
		<?php ft_add_goods() ?>
		<div id="account-field">
			<p class="category-text">Total Price</p>
			<p class="price-text"><?=$_SESSION['price']?> $</p>
			<form action="buy.php" method="post">
				<p><input class="category_buttom"  type="submit" name="submit" value="BUY"></p>
				<p class="account-field-text"></p>
			</form>
			
		</div>
	</div>
	<div id = "main_list" style="height: 100px; margin-top: -1vw"></div>
</body>
</html>
