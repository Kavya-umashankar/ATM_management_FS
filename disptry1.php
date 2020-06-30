<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
    <h1>TRANSACTION DETAILS</h1>
    <br>
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
body{
    background-image:url("https://wallpaperset.com/w/full/7/f/7/110547.jpg");
    color:white;
    border-width:thick;

}

.button {
  background-color:#dce4ec;
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
h3
{
    color:white;
}
</style>
<body>
<?php
$d= shell_exec("disptry.exe ");
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
echo"<div id=\"printTable\">";
echo "<table align=\"center\" cellpadding=\"7\" cellspacing=\"7\" border=\"3\" bordercolor=\"white\">";
echo "<tr>";
echo "<th>".$str[1]."</th>";
echo "<th>".$str[2]."</th>";
echo "<th>".$str[3]."</th>";
echo "<th>".$str[4]."</th>";
echo "<th>".$str[5]."</th>";
echo "<th>".$str[6]."</th>";
echo "<th>".$str[7]."</th>";
echo "<th>".$str[8]."</th>";
echo "<th>".$str[9]."</th>";
echo "</tr>";
echo "<tr>";
for($i = 11 ; $i != $c-1 ; $i++)
{
    if($i%10==0)
    {
        echo "</tr>";
        echo "<tr>";
    }
    else
        echo "<td>".$str[$i]."</td>";
   
}
echo "</table>";
echo"</div>";
?>
<a href='manager.php'><button class="button button4" style="width:7.3%">BACK
</button>


<a href="#null" onclick="printContent('printTable')"><h3>Click to print table<h3></a>
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
