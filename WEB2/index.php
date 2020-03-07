<!DOCTYPE html>
<html lang="pt-br">
	<head>
		<meta charset="UTF-8">
		<title> Novo Drive </title>
	</head>
	<body>
 		<form method="POST">
			<h5> coloque aqui seu arquivo texto </h5>
			<h2> nao serao permitidos codigos de programacao ou binario</h2>
			<input type="text" name="link"/>
			<input type="submit"/>
		</form>
		<?php 
			$dir= "./";
			$url = $_POST["link"];
			$ch = curl_init($url); 

			if (!is_dir($dir))
			{
				echo "<h5>diretorio com erro</h5>";
			}
			if (!is_writable($dir))
			{
				echo "<h5>diretorio nao escrivivel</h5>";
			}
			
			$file_name=basename($url);
			if($file_name==$url)
			{
				echo "nao fez download";
			}
			
			else
			{
				$save_file_loc = $dir . $file_name;

				$fp = fopen ( $save_file_loc,'wb');

				curl_setopt($ch, CURLOPT_FILE, $fp);
				curl_setopt($ch, CURLOPT_HEADER, 0);

				curl_exec($ch);
				curl_close($ch);
	
				fclose ($fp);
				
				if(verifica($save_file_loc, $dir)==1)
				{
					echo "<h2>codigo de programacao ou binario!</h2>";
				}
				else
				{
					echo "<h5>tudo certo<h5>";
					$fp = fopen ( $save_file_loc,'wb');
					$ch = curl_init($url);
					curl_setopt($ch, CURLOPT_FILE, $fp);
					curl_setopt($ch, CURLOPT_HEADER, 0);

					curl_exec($ch);
					curl_close($ch);
	
					fclose ($fp);	
				}
		
			}

		function verifica ($save_file_loc)
		{
			$fp = fopen ( $save_file_loc,'r');
			while ($linha= fgets($fp,4096))	
			{
				$tamanho=strlen($linha);
				$tamanho--;
				for ($i=0;$i!==$tamanho;$i++)
				{
					if (($linha[$i]<' ') or ($linha[$i]>'z'))
					{
						fclose ($fp);
						unlink ($save_file_loc);
						return 1;
					}
				}	
			}
			fclose ($fp);
			unlink ($save_file_loc);
			return 0; //nao e codigo de programacao
		}


		?>
	</body>
</html>
