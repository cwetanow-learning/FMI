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

    public function load()
    {
        if ($this->id)
        {
            $stmt = (new Db())->getConn()->prepare("SELECT * FROM `electives` WHERE id = ?");
            $result = $stmt->execute([$this->id]);
        }
        
        $elective = $stmt->fetch();
        
        $this->title = $elective['title'];
        $this->description = $elective['description'];
        $this->lecturer = $elective['lecturer'];
    }

    public function update()
    {
        if ($this->id)
        {
            $stmt = (new Db())->getConn()->prepare("UPDATE `electives` SET `title`=? ,`description`= ?,`lecturer`= ? WHERE id = ?");
            $result = $stmt->execute([$this->title, $this->description, $this->lecturer, $this->id]);

            return $result;
        }
    }
  }
?>