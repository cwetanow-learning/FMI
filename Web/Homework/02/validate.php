<?php
$errors = array();

function validateRequired($str, $message, &$errors)
{
    if (!$str) {
        array_push($errors, $message . ' е задължително поле');
    }
}

function validateLength($str, $len, $message, &$errors)
{
    if (strlen($str) > $len) {
        array_push($errors, $message . ' е с максимална дължина 150 символа');
    }
}

function validateTitle($title, &$errors)
{
    validateRequired($title, 'Името', $errors);
    validateLength($title, 150, 'Името', $errors);
}

function validateLector($lector, &$errors)
{
    validateRequired($lector, 'Преподавател', $errors);
    validateLength($lector, 200, 'Преподавател', $errors);
}

function validateDescription($description, &$errors)
{
    validateRequired($description, 'Описание', $errors);
    validateLength($description, 10, 'Описание', $errors);
}

function validateGroup($group, &$errors)
{
    if ($group != 'm' && $group != 'pm' && $group != 'okn' && $group != 'ykn') {
        array_push($errors, 'Група е една измежду М, ПМ, ОКН и ЯКН');
    }
}

function validateCredits($credits, &$errors)
{
    if ($credits) {
        if (!is_numeric($credits)) {
            array_push($errors, 'Кредити е число');
        }
        
        if ($credits <= 0) {
            array_push($errors, 'Кредити е положително число');
        }
        
        if (!is_int($credits)) {
            array_push($errors, 'Кредити е цяло число');
        }
    }
}

if ($_POST) {
    if (isset($_POST['title'])) {
        $title = $_POST['title'];
        validateTitle($title, $errors);
    } else {
        array_push($errors, 'Името е задължително поле');
    }
    
    if (isset($_POST['lector'])) {
        $lector = $_POST['lector'];
        validateLector($lector, $errors);
    } else {
        array_push($errors, 'Преподавател е задължително поле');
    }
    
    if (isset($_POST['description'])) {
        $description = $_POST['description'];
        validateDescription($description, $errors);
    } else {
        array_push($errors, 'Описание е задължително поле');
    }
    
    if (isset($_POST['group'])) {
        $group = $_POST['group'];
        validateGroup($group, $errors);
    }
    
    if (isset($_POST['credits'])) {
        $credits = $_POST['credits'];
        validateCredits($credits, $errors);
    }
    
    foreach ($errors as $error) {
        echo $error, '<br>';
    }
}
?>  