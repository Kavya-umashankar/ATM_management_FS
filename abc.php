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
}
  .button6 {
    border-radius: 8px;
    margin-top:1cm;
    margin-left:5cm;

}
body{
    background-image:url("https://wallpaperset.com/w/full/7/f/7/110547.jpg");
    color:white;
    border-width:thick;
    font-size:50px;
}
table{
  width:50%;
  height:50%;
  font-size:20px;
}
h5{
  color:white;
}
</style>

<?php
session_start();

$tid1=$_SESSION["tid1"];
$accno= $_SESSION["ACCNO"];
$n = $_SESSION["NAME"];
$a = $_SESSION["ACCTYPE"];
$b = $_SESSION["BAL"];
$entry=$_SESSION['entrytime'];
date_default_timezone_set('Asia/Kolkata');
$exit= date('d-m-y h:i:s');
$timee=explode(" ",$exit);
$exit1=$timee[0]."_".$timee[1];
$with=$_POST['with'];
$deposit="";
//printf(gettype($b));
$b1=(int)$b -(int)$with;
if($b1 >=2000)
{
  //echo shell_exec("insert.exe  \"$accno\" \"$n\"  \"$acctype\" \"$b1 \"" );
  //custmain, c1index -->main data(balance)
  $f= shell_exec("replace.exe \"$accno\" ");
   shell_exec("insert.exe  \"$accno\" \"$n\"  \"$a\" \"$b1 \"" );
  //cust,cindex -->manager
   shell_exec("insert1.exe  \"$tid1\"  \"$accno\" \"$n\" \"$entry\" \"$exit1\"  \"$with\" \"$deposit\" \"$a\" \"$b1\" " );
  //hashfile
//echo shell_exec("hashing.exe  \"$tid1\"  \"$accno\" \"$name\" \"$entry\" \"$exit1\"  \"$with\" \"$deposit\" \"$acctype\" " );
//print_r(explode("|",$f));
?>
<html>
<body>
<div id="printTable">
<table align="center" border="1" >
<tr>
<td colspan="2"><h2>Transaction receipt</h2></td>
</tr>
<th>Transaction ID:</th>
<?php
echo "<td>".$tid1."</td>";
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
echo "<td>".$n."</td>";
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
<th>Withdraw Amount:</th>
<?php
echo "<td>".$with."</td>";
?>
</tr>
<tr>
<th>Account Type:</th>
<?php
echo "<td>".$a."</td>";
?>
</tr>
<tr>
<th>Balance:</th>
<?php
echo "<td>".$b1."</td>";
?>
</tr>
</table>
</div>
<a href='front.php'><button class="button button6" style="width:17.3%">BACK</button></a><br>
<?php
}
else
{
  echo "<h2>ERROR:BALACE SHOULD BE GREATER THAN 2000 AFTER DEDUCTION</h2>";
}

?>

<a href="#null" onclick="printContent('printTable')"><h5>Click to print table<h5></a>
<script type="text/javascript">
<!--
function printContent(id){
str=document.getElementById(id).innerHTML
newwin=window.open('','printwin','left=100,top=100,width=400,height=400')
newwin.document.write('<HTML>\n<HEAD>\n')
newwin.document.write('<TITLE>Print Page</TITLE>\n')
newwin.document.write('<script>\n')
newwin.document.write('function chkstate(){\n')
newwin.document.write('if(document.readyState=="complete"){\n')
newwin.document.write('window.close()\n')
newwin.document.write('}\n')
newwin.document.write('else{\n')
newwin.document.write('setTimeout("chkstate()",2000)\n')
newwin.document.write('}\n')
newwin.document.write('}\n')
newwin.document.write('function print_win(){\n')
newwin.document.write('window.print();\n')
newwin.document.write('chkstate();\n')
newwin.document.write('}\n')
newwin.document.write('<\/script>\n')
newwin.document.write('</HEAD>\n')
newwin.document.write('<BODY onload="print_win()">\n')
newwin.document.write(str)
newwin.document.write('</BODY>\n')
newwin.document.write('</HTML>\n')
newwin.document.close()
}
//-->
</script>
</body>
</html>