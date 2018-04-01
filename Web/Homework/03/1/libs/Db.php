<?php
namespace libs;

use \PDO;

class Db
{
    private $conn;

    public function __construct()
    {
        $host = CONFIG['db']['host'];
        $db   = CONFIG['db']['name'];
        $user = CONFIG['db']['user'];
        $pass = CONFIG['db']['password'];
        $charset = CONFIG['db']['charset'];

        $dsn = "mysql:host=$host;dbname=$db;charset=$charset";
        $opt = [
            PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
            PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
            PDO::ATTR_EMULATE_PREPARES   => false,
        ];
        $this->conn = new PDO($dsn, $user, $pass, $opt);
    }
    
    public function getConn()
    {
        return $this->conn;
    }
}