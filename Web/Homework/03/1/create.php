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
        <form action="controllers/create.php" method="POST">
        <div class="form-group">
                <label for="title">Име на предмета</label>
                <input type="text"
                       required
                       maxlength="150"
                       class="form-control"
                       name="title">
            </div>
            <div class="form-group">
                <label for="lector">Преподавател </label>
                <input type="text"
                       required
                       maxlength="200"
                       class="form-control"
                       name="lecturer">
            </div>
            <div class="form-group">
                <label for="description">Описание </label>
                <input type="text"
                       required
                       maxlength="10"
                       class="form-control"
                       name="description">
            </div>

                        <button type="submit"
                    class="btn btn-default">Изпрати</button>
        </form>
        </div>
    </body>
</html>