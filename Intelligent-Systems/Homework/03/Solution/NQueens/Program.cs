using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

namespace NQueens
{
	public class Program
	{
		private const int MaxSteps = 60;
		private static Random random = new Random();

		public static void Main(string[] args)
		{
			var n = int.Parse(Console.ReadLine());
			var sw = Stopwatch.StartNew();

			var result = Restart(n);
			sw.Stop();

			Console.WriteLine(sw.ElapsedMilliseconds);
			Console.WriteLine(string.Join(' ', result));
		}

		public static void PrintMatrix(int[][] hitsMatrix, int n)
		{
			for (int i = 0; i < n; i++)
			{
				Console.WriteLine(string.Join(' ', hitsMatrix[i]));
			}

			Console.WriteLine();
		}

		public static int[] Restart(int n)
		{
			var (queens, hitsMatrix) = Initialize(n);

			return Solve(queens, hitsMatrix, 0);
		}

		public static (int[] queens, int[][] hitsMatrix) Initialize(int n)
		{
			var queens = new int[n];
			var hitsMatrix = new int[n][];

			for (int i = 0; i < n; i++)
			{
				hitsMatrix[i] = new int[n];
				queens[i] = -1;
			}

			for (int i = 0; i < n; i++)
			{
				//var nextQueen = random.Next(0, n);

				//while (queens[nextQueen] >= 0)
				//{
				//	nextQueen = random.Next(0, n);
				//}

				var moves = GetBestMoveForRow(queens, hitsMatrix, i);

				var nextMoveIndex = random.Next(0, moves.Count);

				var nextCol = moves[nextMoveIndex];

				(queens, hitsMatrix) = MakeMove(i, nextCol, queens, hitsMatrix);

				//Console.WriteLine($"{i} {queens[i]}");
				//PrintMatrix(hitsMatrix, n);
			}

			return (queens, hitsMatrix);
		}

		private static List<int> GetBestMoveForRow(int[] queens, int[][] hitsMatrix, int row)
		{
			var matrixRow = hitsMatrix[row];
			var min = matrixRow.Min();

			var moves = matrixRow
				.Select((element, index) => new { element, index })
				.Where(obj => obj.element == min && obj.element != queens[row])
				.Select(obj => obj.index)
				.ToList();

			return moves;
		}

		private static List<(int row, int col, int nextCol)> GetBestMoves(int[] queens, int[][] hitsMatrix)
		{
			var result = new List<(int row, int col, int nextCol)>();

			var n = queens.Length;

			var maxHitsChange = -1;

			for (int i = 0; i < n; i++)
			{
				var rowBestMoves = GetBestMoveForRow(queens, hitsMatrix, i);

				if (rowBestMoves.Any())
				{
					var first = rowBestMoves.First();

					var change = hitsMatrix[i][queens[i]] - hitsMatrix[i][first];

					if (change >= maxHitsChange)
					{
						if (change > maxHitsChange)
						{
							result.Clear();
						}

						rowBestMoves.ForEach(nextCol => {
							result.Add((i, queens[i], nextCol));
						});
					}
				}
			}

			return result;
		}

		private static (int[] queens, int[][] hitsMatrix) MakeMove(int row, int nextCol, int[] queens, int[][] hitsMatrix)
		{
			var n = queens.Length;
			var col = queens[row];

			queens[row] = nextCol;

			//Console.WriteLine($"{row} {col} -> {queens[row]}");
			//PrintMatrix(hitsMatrix, n);

			// Update old position
			if (col >= 0)
			{
				UpdateMatrix(row, col, -1, hitsMatrix, n);
			}

			// Update new position
			UpdateMatrix(row, nextCol, 1, hitsMatrix, n);

			return (queens, hitsMatrix);
		}

		public static void UpdateMatrix(int row, int col, int increment, int[][] hitsMatrix, int n)
		{
			for (int i = 0; i < n; i++)
			{
				if (i != row)
				{
					hitsMatrix[i][col] += increment;
				}
			}

			// Update upper half diagonals
			for (int i = row - 1; i >= 0; i--)
			{
				var currentCol = col - (row - i);

				if (currentCol >= 0)
				{
					hitsMatrix[i][currentCol] += increment;
				}

				currentCol = row - i + col;

				if (currentCol < n && currentCol >= 0)
				{
					hitsMatrix[i][currentCol] += increment;
				}
			}

			// Update lower half diagonals
			for (int i = row + 1; i < n; i++)
			{
				var currentCol = col + (row - i);

				if (currentCol < n && currentCol >= 0)
				{
					hitsMatrix[i][currentCol] += increment;
				}

				currentCol = i - row + col;

				if (currentCol < n && currentCol >= 0)
				{
					hitsMatrix[i][currentCol] += increment;
				}
			}
		}

		public static int[] Solve(int[] queens, int[][] hitsMatrix, int steps)
		{
			while (steps < MaxSteps)
			{
				//PrintMatrix(hitsMatrix, queens.Length);

				if (IsSolution(queens, hitsMatrix))
				{
					return queens;
				}

				var nextMoves = GetBestMoves(queens, hitsMatrix);

				if (!nextMoves.Any())
				{
					return Restart(queens.Length);
				}

				var randomIndex = random.Next(0, nextMoves.Count);

				var (row, col, nextCol) = nextMoves[randomIndex];

				MakeMove(row, nextCol, queens, hitsMatrix);

				steps++;
			}

			return Restart(queens.Length);
		}

		private static bool IsSolution(int[] queens, int[][] hitsMatrix)
		{
			var n = queens.Length;

			for (int i = 0; i < n; i++)
			{
				var row = i;
				var col = queens[i];

				if (hitsMatrix[row][col] != 0)
				{
					return false;
				}
			}

			return true;
		}
	}
}
