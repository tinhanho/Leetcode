<?php
// get the current view
$counter = file_get_contents("article_counter.dat");
 
if (!isset($_COOKIE['article_read'])) {
    setcookie("article_read", 1, time()+3600);
    $counter++;
    $fp = fopen("article_counter.dat, "w");
    fwrite($fp, $counter);
    fclose($fp);
}
 
echo "document.write('" . $counter . "');";
?>
