<?php
	session_start();

	function ft_funct_erorr(){
		echo ($_SESSION['er_ad']);
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
	<div id="account-field">
		<p class="account-text">Add Product</p>
		<form action="add_prod.php" method="post">
			<p class="account-field-text">Category</p>
			<input class="input-field" type="text" name="category" value="<?php ft_funct_erorr()?>">
			<p class="account-field-text">Name of product</p>
			<input class="input-field" type="text" name="name" value="<?php ft_funct_erorr()?>">
			<p class="account-field-text">Price</p>
			<input class="input-field" type="text" name="price" value="<?php ft_funct_erorr()?>">
			<p class="account-field-text">Description</p>
			<input class="input-field" type="text" name="desc" value="<?php ft_funct_erorr()?>">
			<p class="account-field-text">Name of picture</p>
			<input class="input-field" type="text" name="img" value="<?php ft_funct_erorr()?>">
			<p><input class="login_conf_buttom"  type="submit" name="submit" value="ADD PRODUCT"></p>
			<p class="account-field-text"></p>
		</form>
	</div>
</div>
<div id = "main_list" style="height: 100px; margin-top: -1vw"></div>
</body>
</html>
