using System;
using System.Collections.Generic;
using System.Linq;

namespace TicTacToe
{
	public class Node
	{
		public int Value { get; set; }

		public ICollection<Node> Children { get; set; }

		public char[][] Board { get; set; }
	}

	public class Program
	{
		public const int BoardSize = 3;

		public const char Person = 'X';
		public const char Computer = 'O';
		public const char Empty = '-';

		public static void Main(string[] args)
		{
			var board = InitBoard();

			Console.WriteLine("You are X, play first?");
			var player = Console.ReadLine() == "y" ? Person : Computer;

			while (!IsGameOver(board))
			{
				var row = -1;
				var col = -1;

				if (player == Person)
				{
					var input = Console.ReadLine()
						.Split()
						.Select(int.Parse)
						.ToList();

					row = input[0];
					col = input[1];

					player = Computer;
				}
				else
				{
					(row, col) = GetNextMove(board, Computer);

					player = Person;
				}

				PrintBoard(board);
			}
		}

		public static void MakeMove(char[][] board, char player, int row, int col)
		{
			board[row][col] = player;
		}

		public static (int row, int col) GetNextMove(char[][] board, char player)
		{
			var row = -1;
			var col = -1;

			return (row, col);
		}

		public static (int row, int col, int score) Minimax(char[][] board, bool isMaxPlayer, int alpha, int beta)
		{
			if (IsDraw(board))
			{
				return (-1, -1, 0);
			}

			if (IsSolution(board, Computer))
			{
				var emptyCount = board
									.SelectMany(row => row)
									.Where(cell => cell == Empty)
									.Count();

				return (-1, -1, emptyCount + 1);
			}

			var bestRow = -1;
			var bestCol = -1;

			if (isMaxPlayer)
			{
				var newBoard = board.Select(x => x.ToArray()).ToArray();

			}
			else
			{

			}

			return (bestRow, bestCol, (isMaxPlayer ? alpha : beta));
		}

		public static char[][] GetPredefinedBoard()
		{
			var board = new char[BoardSize][] {
				new char[3]{' ', ' ' , ' ' },
				new char[3]{' ', ' ' , ' ' },
				new char[3]{' ',  ' ', ' ' }
			};

			return board;
		}

		public static void PrintBoard(char[][] board)
		{
			for (int i = 0; i < BoardSize; i++)
			{
				Console.WriteLine(string.Join(' ', board[i]));
			}

			Console.WriteLine();
		}

		public static char[][] InitBoard()
		{
			var board = new char[BoardSize][];
			for (int i = 0; i < BoardSize; i++)
			{
				board[i] = Enumerable.Repeat(Empty, BoardSize)
					.ToArray();
			}

			return board;
		}

		public static bool IsDraw(char[][] board)
		{
			var isDraw = !board
				.SelectMany(b => b)
				.Any(c => c == Empty);

			return isDraw;
		}

		public static bool IsGameOver(char[][] board)
		{
			if (IsSolution(board, Person) || IsSolution(board, Computer))
			{
				return true;
			}

			return IsDraw(board);
		}

		public static bool IsSolution(char[][] board, char player)
		{
			var isLeftDiagonalSolution = true;
			var isRightDiagonalSolution = true;

			for (int j = 0; j < BoardSize; j++)
			{
				if (!isLeftDiagonalSolution && !isRightDiagonalSolution)
				{
					break;
				}

				if (isLeftDiagonalSolution && board[j][j] != player)
				{
					isLeftDiagonalSolution = false;
				}

				if (isRightDiagonalSolution && board[BoardSize - 1 - j][j] != player)
				{
					isRightDiagonalSolution = false;
				}
			}

			if (isLeftDiagonalSolution || isRightDiagonalSolution)
			{
				return true;
			}

			for (int i = 0; i < BoardSize; i++)
			{
				var isRowSolution = true;
				var isColSolution = true;

				for (int j = 0; j < BoardSize; j++)
				{
					if (!isRowSolution && !isColSolution)
					{
						break;
					}

					if (isRowSolution && board[i][j] != player)
					{
						isRowSolution = false;
					}

					if (isColSolution && board[j][i] != player)
					{
						isColSolution = false;
					}
				}

				if (isRowSolution || isColSolution)
				{
					return true;
				}
			}

			return false;
		}
	}
}
