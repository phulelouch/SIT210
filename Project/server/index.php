<?php
if (isset($_POST['gas'])) { //read gas value with post request and put it in a txt file
	        echo $_POST['gas'];
		        $myfile = fopen("gas.txt", "w");
		        fwrite($myfile, $_POST['gas']);
			        fclose($myfile);
} else if (isset($_POST['flame'])) {//read flame value with post request and put it in a txt file
	        echo $_POST['flame'];
		        $myfile = fopen("flame.txt", "w");
		        fwrite($myfile, $_POST['flame']);
			        fclose($myfile);
} else if (isset($_POST['button'])) { //read button status with post request and put it in a txt file, 1 mean button is pressed
	        echo $_POST['button'];
		        $myfile = fopen("button.txt", "w");
		        fwrite($myfile, $_POST['button']);
			        fclose($myfile);
} else if(isset($_GET['read'])&&($_GET['read']==1)){ //read gas value
	        $myfile = fopen("gas.txt", "r");
		        echo fread($myfile,filesize("gas.txt"));
		        fclose($myfile);
} else if(isset($_GET['read'])&&($_GET['read']==2)){//read flame value
	        $myfile = fopen("flame.txt", "r");
		        echo fread($myfile,filesize("flame.txt"));
		        fclose($myfile);
} else if(isset($_GET['read'])&&($_GET['read']==3)){//read button state value
	        $myfile = fopen("button.txt", "r");
		        echo fread($myfile,filesize("button.txt"));
		        fclose($myfile);
}

?>

