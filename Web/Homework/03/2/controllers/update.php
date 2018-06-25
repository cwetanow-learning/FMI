<?php

require_once "../libs/Init.php";
Init::_init(true);

use libs\Elective;

$id = $_GET["id"];

if($id){
    $elective = new Elective($_POST['title'], $_POST['description'], $_POST['lecturer']);
    $elective->setId($id);

    $success = $elective->update();

    if ($success)
    {
        header('Location: ../electives.php?id='.$id);
    }
}