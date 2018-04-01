
CREATE DATABASE IF NOT EXISTS `fmi-web` COLLATE utf8mb4_unicode_ci;
USE `fmi-web`;

CREATE TABLE electives (
  id INT AUTO_INCREMENT PRIMARY KEY,
  title VARCHAR(128),
  description VARCHAR(1024),
  lecturer VARCHAR(128),
  created_at timestamp default current_timestamp
);

INSERT INTO electives (title, description, lecturer)
VALUES
  ("Programming with Go", "Let's learn Go", "Nikolay Batchiyski"),
  ("AKDU", "Let's Graduate", "Svetlin Ivanov"),
  ("Web technologies", "Let's learn the web", "Milen Petrov");
