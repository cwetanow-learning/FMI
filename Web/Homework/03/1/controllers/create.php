<?php

require_once "../libs/Init.php";
Init::_init(true);

use libs\Elective;

$elective = new Elective($_POST['title'], $_POST['description'], $_POST['lecturer']);

$success = $elective->insert();

if ($success)
{
    header('Location: ../index.php');
}