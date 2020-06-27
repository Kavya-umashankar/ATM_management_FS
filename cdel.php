<?php


$tid= $_POST['tid'];

 
 $a= shell_exec("delete.exe  $tid" );
 if($a=="1")
 {
    header("location: derror.php");

 }
 else{
 header("location: disptry1.php"); 
 }
?>