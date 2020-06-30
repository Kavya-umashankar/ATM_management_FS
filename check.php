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