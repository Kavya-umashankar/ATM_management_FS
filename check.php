<?php
session_start();
$acc=$_POST['accno'];
// $res=$_POST['res'];
 
 $a= shell_exec("verify.exe  $acc " );
 if($a=="1")
 {
  header("location: formv.php");
 }
 else
 { 
  echo " <h1>go to manager and get it registered </h1>";
  }
?>