using System;

namespace Sudoku.Models
{
    [Serializable]
    public class SudokuGame
    {
        public SudokuGame()
        {
            this.Board = new int[9, 9];
        }

        public SudokuGame(int[,] board)
        {
            this.Board = board;
        }

        public int[,] Board { get; set; }

        public TimeSpan Elapsed { get; set; }
    }
}
