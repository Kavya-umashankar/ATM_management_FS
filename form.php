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
    font-weight:bold;
  color:#000000;
  font-size:20px;
  font-family:courier;
  
   
}

body{
  background-color:grey;
}


</style>
<body>
<form action="abc.php" method="POST">
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
  <label for="entry">Select a entry time:</label>
<input type="time" id="entry" name="entry">

<label for="exit">Select a exit time:</label>
<input type="time" id="exit" name="exit">

  <div class="form-group">
    <label for="with">Withdraw amount:</label>
    <input type="number" class="form-control" id="with" name="with" placeholder="">
  </div>
  <div class="form-group">
    <label for="inputAddress2">Deposit amount:</label>
    <input type="number" class="form-control" id="deposit" placeholder="" name="deposit">
  </div>
  <div class="form-row">
    <div class="form-group col-md-6">
      <label for="acctype">account type</label>
      <input type="text" class="form-control" id="acctype" name="acctype">
    </div>
   

  </div>
  <div class="form-group">
    <div class="form-check">
     
  <button type="submit" class="btn btn-primary">SUBMIT</button>
</form>
<script>

</script>
</body>
