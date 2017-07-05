<?php
	include "install.php";
	
	session_start();

	function ft_name_log() {
		if ($_SESSION['user']['login'])
			echo "Logout";
		else
			echo "Login";
	}
	
	function ft_ref_log() {
		if ($_SESSION['user']['login'])
			echo ("index.php");
		else
			echo ("login_page.php");
	}
	
	function ft_name_reg() {
		if ($_SESSION['user']['login'])
			echo ($_SESSION["user"]["login"]);
		else
			echo "Register";
	}
	
	function ft_basket_ref() {
		if ($_SESSION['user']['login'] == 'admin')
			echo ("add_product_page.php");
		else
			echo "basket_page.php";
	}
	
	function ft_name_basket () {
		if ($_SESSION['user']['login'] == 'admin')
			echo ("Product");
		else
			echo "Basket";
	}
	
	function ft_text_pr_but() {
		if ($_SESSION['user']['login'] == 'admin')
			return ("DELETE ");
		else
			return ("ADD ");
	}
	
	function ft_echo_product($pr) {
		echo ('<div id="account-field">
						<p class="category-text">'.$pr["name"].'</p>
						<img class="category-img" src="resourses/'.$pr["img"].'">
						<p class="price-text">'.$pr["price"].' $</p>
						<p class="description-text">'.$pr["desc"].'</p>
						<form action="basket_del.php" method="post">
							<p><input class="category_buttom"  type="submit" name="product" value="'.ft_text_pr_but().$pr["name"].'"></p>
							<p class="account-field-text"></p>
						</form>
					</div>');
	}
	
	function ft_add_goods() {
		$tab = ft_get_data();
		foreach ($tab as $pr){
			if ($_SESSION['category']){
				if ($_SESSION['category'] == $pr["category"])
					ft_echo_product($pr);
			}
			else
				ft_echo_product($pr);
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
			<a class="button-wrap" style="margin-left: 2px" href="logout.php">
		        <div class="button">
					<p class="button-text"><?php ft_name_log() ?></p>
				</div>
			</a>
		    <a class="button-wrap" style="margin-left: 2px" href="login_page.php">
			    <div class="button">
				    <p class="button-text"><?php ft_name_reg()?></p>
			    </div>
		    </a>
		    <a class="button-wrap" style="float: right ; margin-right: 2px" href="<?php ft_basket_ref() ?>">
			    <div class="button"">
			    <p class="button-text"><?php ft_name_basket() ?></p>
	        </div>
			</a>
			<a class="button-wrap" style="float: right; margin-right: 2px" href="category_page.php">
				<div class="button">
					<p class="button-text">Categories</p>
				</div>
			</a>
		</div>
		<?php ft_add_goods() ?>
	</div>
	<div id = "main_list" style="height: 100px; margin-top: -1vw"></div>
</body>
</html>
