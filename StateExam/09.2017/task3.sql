-- 1. Попълнете липсващите части, така че заявката да изведе име и държава на корабите, които никога не са потъвали в битка (може и да не са участвали)
select name, country
from ships 
left join outcomes on name=ship
join classes on ships.CLASS = CLASSES.CLASS
where RESULT is null or RESULT <> 'sunk'

-- 2. Попълнете липсващите части така, че заявката да изведе име, водоизместимост и брой оръдия на най-леките кораби с най-много оръдия.
select name, DISPLACEMENT, NUMGUNS
from CLASSES c join ships s on s.CLASS = s.CLASS
where DISPLACEMENT = (
select MIN(DISPLACEMENT) from CLASSES
) and
NUMGUNS = (select MAX(NUMGUNS) from CLASSES c1 where c1.CLASS=c.CLASS)

-- 3. Попълнете липсващите части така, че заявката да изведе име на битките, в които е участвал един кораб.