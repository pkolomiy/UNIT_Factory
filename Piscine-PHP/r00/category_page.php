<?php
	include "install.php";
	session_start();

	function ft_pict_ct($tab, $ct) {
		foreach ($tab as $pr)
			if ($pr["category"] == $ct)
				return ($pr["img"]);
	}
	
	function ft_add_category(){
		$tab = ft_get_data();
		$un = ft_list_categories($tab);
		foreach ($un as $ct){
			echo ('<div id="account-field">
						<p class="category-text">'.$ct.'</p>
						<form action="choose_category.php" method="POST">
							<input class="category-img" type="image" name = "cat" value="'.$ct.'" src="resourses/'.ft_pict_ct($tab, $ct).'" />
						</form>');
			if ($_SESSION['user']['login'] == 'admin')
				echo ('<form action="del_categ.php" method="post">
							<p><input class="category_buttom"  type="submit" name="submit" value="DELETE '.$ct.'"></p>
							<p class="account-field-text"></p>
						</form>');
			else
				echo ('<p class="account-field-text"></p><br>');
			echo ('</div>');
		}
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
		    <a class="button-wrap" style="float: right ; margin-right: 2px" href="<?php ft_basket_ref() ?>">
				<div class="button"">
			        <p class="button-text"><?php ft_name_basket() ?></p>
	            </div>
			</a>
	        </div>
	        <?php ft_add_category() ?>
		</div>
		<div id = "main_list" style="height: 100px; margin-top: -1vw"></div>
	</body>
</html>
