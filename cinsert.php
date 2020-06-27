<style>
.button {
  background-color: #0067cd;
  border:bold;
  color: white;
  padding: 20px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  margin: 4px 2px;
  .button6 {
    border-radius: 8px;
    margin-top:1cm;
    margin-left:5cm;

}
}
</style>

<?php
session_start();

//$tid1=$_SESSION['tid'];
$accno=$_POST['accno'];
$name=$_POST['name'];
$entry=$_SESSION['entrytime'];
$exit= date('d-m-y h:i:s');
$timee=explode(" ",$exit);
$exit1=$timee[0]."_".$timee[1];
$bal=$_POST['bal'];
$deposit="";
$acctype=$_POST['acctype'];


echo shell_exec("insert.exe  \"$accno\" \"$name\"  \"$acctype\" \"$bal \"" );
//echo shell_exec("hashing.exe  \"$tid1\"  \"$accno\" \"$name\" \"$entry\" \"$exit1\"  \"$with\" \"$deposit\" \"$acctype\" " );

?>
<html>
<body>

<table align="center" border="1" >
<tr>
<td colspan="2"><h2>Transaction receipt</h2></td>
</tr>
<th>Transaction ID:</th>
<?php
//echo "<td>".$tid1."</td>";
?>
</tr>
<tr>
<th>Account Number:</th>
<?php
echo "<td>".$accno."</td>";
?>
</tr>
<tr>
<th>Name:</th>
<?php
echo "<td>".$name."</td>";
?>
</tr>
<tr>
<th>Entry Time:</th>
<?php
echo "<td>".$entry."</td>";
?>
</tr>
<tr>
<th>Exit Time:</th>
<?php
echo "<td>".$exit1."</td>";
?>
</tr>
<tr>
<th>Balance Amount:</th>
<?php
echo "<td>".$bal."</td>";
?>
</tr>
<tr>
<th>Account Type:</th>
<?php
echo "<td>".$acctype,"</td>";
?>
</tr>
</table>
<a href='front.php'><button class="button button6" style="width:17.3%">BACK</button></a><br>
