<?php

require_once "libs/Init.php";
Init::_init();

use libs\Elective;

$id = $_GET["id"];

if($id){
  $elective = new Elective("","","");
  $elective->setId($id);

  $elective->load();
}
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <title>Създаване</title>
        <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css"
          rel="stylesheet"
          crossorigin="anonymous">
    </head>
    <body>
    <div class="container">    
        <form action="controllers/update.php?id=<?php echo $elective->getId() ?>" method="POST">
        <div class="form-group">
                <label for="title">Име на предмета</label>
                <input type="text"
                       required
                       maxlength="150"
                       class="form-control"
                       name="title"
                       value="<?php echo $elective->getTitle() ?>">
            </div>
            <div class="form-group">
                <label for="lector">Преподавател </label>
                <input type="text"
                       required
                       maxlength="200"
                       class="form-control"
                       name="lecturer" 
                       value="<?php echo $elective->getLecturer() ?>">
            </div>
            <div class="form-group">
                <label for="description">Описание </label>
                <input type="text"
                       required
                       maxlength="10"
                       class="form-control"
                       name="description" 
                       value="<?php echo $elective->getDescription() ?>">
            </div>

                        <button type="submit"
                    class="btn btn-default">Изпрати</button>
        </form>
        </div>
    </body>
</html>