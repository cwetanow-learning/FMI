# N Queens problem

Place n queens on a n x n chess board so that none of them heats another

## Generate starting board
- Matrix of hits, each cell indicates how many queens hit it
- Place each queen on different row
- Place each queen on a random column with least hits
- Keep queens in array with ints. Index is number of row, value is number of column

## Each move
- Heuristic is number of conflicts of a queen with the others
- Move the queen with the best conflict reduce (if q1 has 30 and 10 after move, and q2 has 50 and 40 after move, we move q1)
- If more than one queen is optimal to move, pick random queen

## Steps
- Pick a new place
- Update matrix of hits

## This solution does not guarantee a solution.
- It should be done with about 50 steps
- Keep a counter and if number of steps is above certain value(50), do a random restart