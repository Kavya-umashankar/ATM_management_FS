<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <h1>details are</h1>
    <title>Document</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
<script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>

</head>
<style>
h1{
    text-align:center;
    color:#dce4ec;
    font-size:2cm;
}
form{
  align:center;
  margin-top:1.5cm;
  margin-left:11cm;
}
body{
    background-image:url("https://wallpaperset.com/w/full/7/f/7/110547.jpg");
    color:white;
    border-width:thick;

}
div.form-group{
  margin: 30px;
  background-color: #ffffff;
  border: 1px solid black;
  opacity: 0.6;
  font-weight:bold;
  color:#000000;
  font-size:25px;

}
button{
  margin-left:12cm;
}

</style>
<body>

<?php
$d= shell_exec("disptry2.exe ");
//echo $d;
//print_r(explode("|",$d));
//echo gettype($d);
$str =explode("|",$d);
$matches="---";
$c=array_search($matches,$str);

//echo "<br>$c<br>";
//print "heeloo";
//echo "<br>------------------------------------------------------------------------------------------------------------------------------------------------------------";
//echo "<br>";
echo "<h1 center> $str[0]</h1>";
echo "<table align=\"center\" cellpadding=\"7\" cellspacing=\"7\" border=\"3\" bordercolor=\"white\">";
echo "<tr>";
echo "<th>ACCOUNT NO</th>";
echo "<th>NAME</th>";
echo "<th>TYPE</th>";
echo "<th>BALANCE</th>";

echo "</tr>";
echo "<tr>";
for($i = 1 ; $i != $c-1 ; $i++)
{
    if($i%5==0)
    {
        echo "</tr>";
        echo "<tr>";
    }
    else
        echo "<td> $str[$i] </td>";
   
}
echo "</table>";
?>



<form action="cdel2.php" method="POST">
  <div class="form-group col-md-6">
  <div class transbox>
      <label for="tid"> Account number</label>
      <br>
      <input type="text" class="form-control" id="tid" name="tid" required>
    
      <button type="submit" class="btn btn-primary">DELETE</button>
      <br>
    </div>
    </div>
</body>
</html>