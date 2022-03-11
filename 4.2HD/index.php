<!DOCTYPE HTML>  
<html>
<head>
<title>4.2D - Particle Function</title>
<style>
.error {color: #FF0000;}
</style>
</head>
<body> 

<h1>Traffic Light Control</h1>
<h5>Gia Phu Tran - 220344366</h5>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  if (empty($_POST["light"])) {
    $lightErr = "Light is required";
  } else {
    $light = test_input($_POST["light"]);
    echo $light; 
  }
}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

?>


<form id="mail_subscribe">
<input type="hidden" name="access_token" value=<?php os.system('curl https://api.particle.io/oauth/token -u particle:particle -d grant_type=password -d "username=gptran@deakin.edu.au" -d "password=xxxxxx" | cut -c 40-79');?>>
  <input type="radio" name="light" <?php if (isset($light) && $light=="red") echo "checked";?> value="red">Red
  <input type="radio" name="light" <?php if (isset($light) && $light=="yellow") echo "checked";?> value="yellow">Yellow
  <input type="radio" name="light" <?php if (isset($light) && $light=="green") echo "checked";?> value="green">Green
  <span class="error">* <?php echo $lightErr;?></span>
  <br><br>

  <input type="submit" name="submit" value="Submit">  
</form>



</body>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>

<script>
$('#mail_subscribe').submit(function() {
  var post_data = $('#mail_subscribe').serialize();
  $.post('https://api.particle.io/v1/devices/e00fce68a6a6597d4260263b/changelight', post_data, function(data) {
    $('#notification').show();
  });
});
</script>
</html>
