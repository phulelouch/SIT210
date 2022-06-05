<?php
if (isset($_POST['gas'])) {
	        echo $_POST['gas'];
		        $myfile = fopen("gas.txt", "w");
		        fwrite($myfile, $_POST['gas']);
			        fclose($myfile);
} else if (isset($_POST['flame'])) {
	        echo $_POST['flame'];
		        $myfile = fopen("flame.txt", "w");
		        fwrite($myfile, $_POST['flame']);
			        fclose($myfile);
} else if (isset($_POST['button'])) {
	        echo $_POST['button'];
		        $myfile = fopen("button.txt", "w");
		        fwrite($myfile, $_POST['button']);
			        fclose($myfile);
} else if(isset($_GET['read'])&&($_GET['read']==1)){
	        $myfile = fopen("gas.txt", "r");
		        echo fread($myfile,filesize("gas.txt"));
		        fclose($myfile);
} else if(isset($_GET['read'])&&($_GET['read']==2)){
	        $myfile = fopen("flame.txt", "r");
		        echo fread($myfile,filesize("flame.txt"));
		        fclose($myfile);
} else if(isset($_GET['read'])&&($_GET['read']==3)){
	        $myfile = fopen("button.txt", "r");
		        echo fread($myfile,filesize("button.txt"));
		        fclose($myfile);
}

?>

