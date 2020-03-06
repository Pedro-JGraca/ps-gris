<!DOCTYPE html>
<html lang="pt-br">
	<head>
		<meta charset="UTF-8">
		<title> Novo Drive </title>
	</head>
	<body>
 		<form method="POST">
			<h5> arquivo </h5>
			<input type="text" name="link"/>
			<input type="submit"/>
		</form>
		<?php 
			$file_name = basename ($_POST["link"]);

			if (file_put_contents($file_name, file_get_contents($_POST["link"])))
			{
				echo "<h5>fez download </h5>";
			}
			else
			{
			 echo "<h5> nao fez download </h5>";
			}

		?>
	</body>
</html>
