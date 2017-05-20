using System;
using Sudoku.Models.Enums;

namespace Sudoku.Models
{
    public class GameGenerator
    {
        private const int BoardSize = 9;

        private int[,] board;

        // public API of the class
        public int[,] GetGame(Difficulty difficulty)
        {
            var numberOfCells = GetNumberOfCellsFilled(difficulty);

            return CreateGame(numberOfCells);
        }

        private int[,] CreateGame(int numberOfCells)
        {
            // initialize board
            this.board = new int[BoardSize, BoardSize];

            // fill board with correct solved sudoku
            this.GetNextCell(0, 0);

            // makes holes in the board depending on the difficulty
            this.MakeHoles(81 - numberOfCells);

            return CopyBoard();
        }

        private void MakeHoles(int holesToMake)
        {
            var random = new Random();

            // finds random coordinates to make empty
            while (holesToMake > 0)
            {
                var row = random.Next(0, 9);
                var col = random.Next(0, 9);

                // if the cell is already empty, it skips it
                if (board[row, col] == 0)
                {
                    continue;
                }

                board[row, col] = 0;
                --holesToMake;
            }
        }

        private int[,] CopyBoard()
        {
            var result = new int[BoardSize, BoardSize];

            // makes a copy of the current board
            for (var i = 0; i < BoardSize; i++)
            {
                for (var j = 0; j < BoardSize; j++)
                {
                    result[i, j] = this.board[i, j];
                }
            }

            return result;
        }

        private bool GetNextCell(int x, int y)
        {
            var nextX = x;
            var nextY = y;

            // all numbers to check
            var toCheck = new[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

            var random = new Random();

            var temp = 0;
            var current = 0;
            var top = toCheck.Length;

            for (int i = top - 1; i > 0; i--)
            {
                current = random.Next(i);
                temp = toCheck[current];
                toCheck[current] = toCheck[i];
                toCheck[i] = temp;
            }

            for (int i = 0; i < toCheck.Length; i++)
            {
                if (this.IsLegalMove(x, y, toCheck[i]))
                {
                    this.board[x, y] = toCheck[i];
                    if (x == 8)
                    {
                        if (y == 8)
                        {
                            return true;
                        } //We're done!  Yay!
                        else
                        {
                            nextX = 0;
                            nextY = y + 1;
                        }
                    }
                    else
                    {
                        nextX = x + 1;
                    }
                    if (this.GetNextCell(nextX, nextY))
                    {
                        return true;
                    }
                }
            }

            this.board[x, y] = 0;
            return false;
        }

        private bool IsLegalMove(int x, int y, int current)
        {
            // checks wether the current column contains the number
            for (int i = 0; i < 9; i++)
            {
                if (current == this.board[x, i])
                {
                    return false;
                }
            }

            // checks wether the current row contains the number
            for (int i = 0; i < 9; i++)
            {
                if (current == this.board[i, y])
                {
                    return false;
                }
            }

            int cornerX = 0;
            int cornerY = 0;
            if (x > 2)
            {
                cornerX = x > 5 ? 6 : 3;
            }
            if (y > 2)
            {
                cornerY = y > 5 ? 6 : 3;
            }
            for (int i = cornerX; i < 10 && i < cornerX + 3; i++)
            {
                for (int j = cornerY; j < 10 && j < cornerY + 3; j++)
                {
                    if (current == this.board[i, j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        private int GetNumberOfCellsFilled(Difficulty difficulty)
        {
            var min = 0;
            var max = 81;

            // set bounds for number of cells filled
            switch (difficulty)
            {
                case Difficulty.Beginner:
                    min = 50;
                    max = 60;
                    break;
                case Difficulty.Easy:
                    min = 36;
                    max = 50;
                    break;
                case Difficulty.Normal:
                    min = 32;
                    max = 36;
                    break;
                case Difficulty.Expert:
                    min = 27;
                    max = 32;
                    break;
                default:
                    min = 20;
                    max = 27;
                    break;
            }

            // get random number in bounds
            var random = new Random();
            var result = random.Next(min, max);
            return result;
        }
    }
}
