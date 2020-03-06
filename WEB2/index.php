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
			
			$output= shell_exec("wget ".$_POST["link"]);
				
			if ($output!=0)
			{
			 echo "<h5> nao fez download </h5>";
			}

		?>
	</body>
</html>
