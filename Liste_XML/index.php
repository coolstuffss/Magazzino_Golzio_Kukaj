<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Magazzino Kukaj Golzio</title>
</head>
<body>

    <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="POST" enctype="multipart/form-data">
        Select file to upload:
        <input type="file" name="filetoupload" id="file">
        <input type="submit" value="Upload" name="submit">
    </form>

    <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "magazzino";
        
        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        if($_SERVER["REQUEST_METHOD"] == "POST"){
		$xml=simplexml_load_file($_FILES['filetoupload']['tmp_name']) or die("Error: Cannot create object");
        $i=0;
        $sql = '';
        while($i < count($xml->magazzino)){
                $magazzino = $xml->magazzino[$i]["id"];
                $j=0;
                while($j < count($xml->magazzino[$i]->prodotto)){
                    $prodotto = $xml->magazzino[$i]->prodotto[$j];
                    $codice =       $prodotto->codice;
                    $nome =         $prodotto->nome;
                    $quantita =     $prodotto->quantita;
                    $descrizione =  $prodotto->descrizione;
                    $scaffale =     $prodotto->scaffale;
                    $prezzo =       $prodotto->prezzo;
                        
                    $sql="INSERT INTO prodotti (IdProdotto, Nome, Quantita, descrizione, Scaffale, prezzo, collocazione)
                           VALUES ($codice, '$nome', $quantita, '$descrizione', $scaffale, $prezzo, $magazzino);\n";
                           echo $sql;
                        if ($conn->query($sql) === TRUE) {
                            echo "New record created successfully";
                        } else {
                            echo "Error: <br>" . $conn->error;
                        }
                    $j++;
                }
                
            $i++;
        }
    }
        
	?>

</body>
</html>