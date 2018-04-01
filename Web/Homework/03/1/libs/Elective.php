<?php 
namespace libs;

use libs\Db;

class Elective
{
    
    private $id;
    private $title;
    private $description;
    private $lecturer;
    
    public function __construct($title, $description, $lecturer)
    {
        $this->title = $title;
        $this->description =$description ;
        $this->lecturer=$lecturer ;
    }
    
    public function getId()
    {
        return $this->id;
    }
    
    public function setId($id)
    {    
        $this->id = $id;
    }
    
    public function getTitle()
    {
        return $this->title;
    }
    
    public function setTitle($title)
    {    
        $this->title = $title;
    }
    
    public function getDescription()
    {
        return $this->description;
    }
    
    public function setDescription($description)
    {    
        $this->description = $description;
    }
    
    public function getLecturer()
    {
        return $this->lecturer;
    }
    
    public function setLecturer($lecturer)
    {    
        $this->lecturer = $lecturer;
    }
    
    public function insert()
    {        
        $stmt = (new Db())->getConn()->prepare("INSERT INTO `electives` (title, description, lecturer) VALUES (?, ?, ?) ");
        return $stmt->execute([$this->title, $this->description, $this->lecturer]);
    }
  }
?>