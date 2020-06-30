<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
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
    margin-top:5cm;
}
body{
    background-image:url("https://wallpaperset.com/w/full/7/f/7/110547.jpg");
    color:white;
    border-width:thick;

}
.button {
  background-color:#DCE4EC;
  border:bold;
  color: black;
  padding: 20px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  margin: 4px 2px;
}

.button4 {
    border-radius: 8px;
    margin-top:1cm;
    margin-left:30cm;
}
</style>
<?php
session_start();
$acc=$_POST['accno'];
// $res=$_POST['res'];
 
 $a= shell_exec("verify.exe  $acc " );
 if($a=="1")
 {
   $res=shell_exec("det.exe $acc");
   print_r(explode("|",$res));
   $r=explode("|",$res);
   $ACCNO=$r[11];
   $NAME=$r[12];
   $acctype=$r[13];
   $BAL=$r[14];
   $_SESSION['ACCNO']= $ACCNO;
   $_SESSION['NAME']= $NAME;
   $_SESSION['ACCTYPE']=$acctype;
   $_SESSION['BAL']=$BAL;
   header('location: formv.php');
 }
 else
 { 
  echo " <h1>go to manager and get it registered </h1>";
  }
?>
<a href='front.php'><button class="button button4" style="width:7.3%">BACK

</button>
</body>
</html>