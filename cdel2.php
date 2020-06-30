<?php


$tid= $_POST['tid'];

 
 $a= shell_exec("delete2.exe  $tid" );
 if($a=="1")
 {
    header("location: derror.php");

 }
 else{
 header("location: disptry2.php"); 
 }
?>