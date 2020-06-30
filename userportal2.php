<?php
session_start();
?>
<!DOCTYPE html>
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
form{
    margin-top:4cm;
    margin-right:3cm;
    margin-left:3cm;

   
}
body{
    background-image:url("https://wallpaperset.com/w/full/7/f/7/110547.jpg");
    color:#FFE5B4;
}
h4{
  margin-left:2cm;
}
.btn{
  margin-left:15cm;
}
</style>
<body>
<form action="abc2.php" method="POST">
<?php
      $tidrand=rand(1000000,9999999);
      $stid = (string) $tidrand;
      $tid = "tid".$stid;
      $_SESSION["tid"] = $tid;    
      ?>

    
    <?php
     echo "<h2>Transaction Id:  \"  ".$tid." \"</h2>";
     echo"<br>";
    $acc= $_SESSION["ACCNO"];
    echo "<h2>Account number: $acc</h2><br>";
    $n = $_SESSION["NAME"];
    echo "<h2>Name: $n </h2><br>";
    $a = $_SESSION['ACCTYPE'];
    echo "<h2>Account type: $a </h2><br>";
    $b = $_SESSION["BAL"];
    echo "<h2>Current balance: Rs $b </h2><br>"
    ?>
  <div class="form-row">
    <label for="inputAddress2"><h2>Deposit amount:<h2></label>
    <input type="number" class="form-control" id="deposit" placeholder="" name="deposit">
  </div>
  
  <div class="form-group">
    <div class="form-check">
     <br>
</form>
<script>

</script>
<?php
    $entrytime = date('d-m-y h:i:s');
    //print_r(explode(" ",$entrytime));
    $timee=explode(" ",$entrytime);
    $_SESSION['entrytime'] = $timee[0]."_".$timee[1];
    echo "<h4><br>Entry Time Recorded :".$entrytime."</h4>";
  ?>
  <button type="submit" class="btn btn-primary">SUBMIT</button>
</body>
</html>