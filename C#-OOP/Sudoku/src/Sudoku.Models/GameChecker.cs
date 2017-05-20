using System.Collections.Generic;

namespace Sudoku.Models
{
    public class GameChecker
    {
        // Singleton implementation of the checker, thread safe
        private static GameChecker instance;

        private static object lockObject = new object();

        private GameChecker() { }


        public static GameChecker Instance
        {
            get
            {
                if (instance == null)
                {
                    lock (lockObject)
                    {
                        if (instance == null)
                        {
                            instance = new GameChecker();
                        }
                    }
                }

                return instance;
            }
        }

        // Validates that a board is correctly solved
        public bool Validate(int[,] board)
        {
            const int integersInGame = 9;
            var rowSet = new HashSet<int>[integersInGame];
            this.InitializeSet(integersInGame, rowSet);
            var columnSet = new HashSet<int>[integersInGame];
            this.InitializeSet(integersInGame, columnSet);
            var subGridSet = new HashSet<int>[integersInGame];
            this.InitializeSet(integersInGame, subGridSet);

            for (var row = 0; row < integersInGame; row++)
            {
                for (var column = 0; column < integersInGame; column++)
                {
                    // if the current row contains that number, it is not correct
                    var cval = board[row, column];
                    if (rowSet[row].Contains(cval))
                    {
                        return false;
                    }

                    // if the current column contains that number, it is not correct
                    rowSet[row].Add(cval);
                    if (columnSet[column].Contains(cval))
                    {
                        return false;
                    }
                    columnSet[column].Add(cval);

                    // if the current 3x3 grid contains that number, it is not correct
                    var subGridNumber = this.FigureOutSubGrid(row, column);
                    if (subGridSet[subGridNumber].Contains(cval))
                    {
                        return false;
                    }
                    subGridSet[subGridNumber].Add(cval);
                }
            }
            return true;
        }

        // initializes the row set with empty columns
        private void InitializeSet(int integersInGame, HashSet<int>[] rowSet)
        {
            for (var i = 0; i < integersInGame; i++)
            {
                rowSet[i] = new HashSet<int>();
            }
        }

        // finds the subgrid of these coordinates
        private int FigureOutSubGrid(int row, int column)
        {
            return column / 3 + row / 3 * 3;
        }
    }
}
