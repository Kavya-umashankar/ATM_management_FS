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
</style>
<body>
<form action="cinsert.php" method="POST">


  <div class="form-row">
    <div class="form-group col-md-6">
      <label for="accno">Account number</label>
      <input type="number" class="form-control" id="accno" name="accno">
    </div>
    <div class="form-group col-md-6">
      <label for="name">Name</label>
      <input type="text" class="form-control" id="name" name="name">
    </div>
  </div>
  <div class="form-group">
    <label for="bal">Balance amount:</label>
    <input type="number" class="form-control" id="bal" name="bal" placeholder="">
  </div>
  
  <div class="form-row">
    <div class="form-group col-md-6">
      <label for="acctype">account type</label>
      <input type="text" class="form-control" id="acctype" name="acctype">
    </div>
  </div>
  <?php
    $entrytime = date('d-m-y h:i:s');
    //print_r(explode(" ",$entrytime));
    $timee=explode(" ",$entrytime);
    $_SESSION['entrytime'] = $timee[0]."_".$timee[1];
    echo "<h4><br>Entry Time Recorded :".$entrytime."</h4>";
  ?>
  <br>
  <div class="form-group">
    <div class="form-check">
     
  <button type="submit" class="btn btn-primary">SUBMIT</button>
</form>
<script>

</script>
</body>