using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace NQueens
{
	public class Program
	{
		private static readonly int MaxSteps = 75;
		private static Random random = new Random();

		public static int restarts = -1;
		public static int steps = 0;

		public static int n;
		public static int[][] hitsMatrix;
		public static int[] queens;

		public static void Main(string[] args)
		{
			n = int.Parse(Console.ReadLine());

			var sw = new Stopwatch();

			sw.Restart();
			Restart();
			Solve();
			sw.Stop();

			Console.WriteLine($"N: {n}; Restarts: {restarts}; Time: {sw.ElapsedMilliseconds / (double)1000}s");
			Console.WriteLine(string.Join(' ', queens));
		}

		public static void PrintSolution()
		{
			for (int i = 0; i < n; i++)
			{
				var builder = new StringBuilder();
				for (int j = 0; j < n; j++)
				{
					var symbol = "_";

					if (queens[i] == j)
					{
						symbol = "*";
					}

					builder.Append(symbol);
				}

				Console.WriteLine(builder.ToString());
			}
		}

		public static void PrintMatrix()
		{
			for (int i = 0; i < n; i++)
			{
				Console.WriteLine(string.Join(' ', hitsMatrix[i]));
			}

			Console.WriteLine();
		}

		public static void Restart()
		{
			restarts++;
			Initialize();
			steps = 0;
		}

		public static void Initialize()
		{
			queens = new int[n];
			hitsMatrix = new int[n][];

			for (int i = 0; i < n; i++)
			{
				hitsMatrix[i] = new int[n];
				queens[i] = -1;
			}

			for (int i = 0; i < n; i++)
			{
				var moves = GetBestMoveForRow(i);

				var nextMoveIndex = random.Next(0, moves.Count);

				var nextCol = moves[nextMoveIndex];

				MakeMove(i, nextCol);
			}
		}

		private static List<int> GetBestMoveForRow(int row)
		{
			var matrixRow = hitsMatrix[row];
			var min = matrixRow.Min();

			if (queens[row] > -1 && matrixRow[queens[row]] == min)
			{
				return new List<int>();
			}

			var moves = matrixRow
				.Select((element, index) => new { element, index })
				.Where(obj => obj.element == min && obj.index != queens[row])
				.Select(obj => obj.index)
				.ToList();

			return moves;
		}

		private static List<(int row, int col, int nextCol)> GetBestMoves()
		{
			var result = new List<(int row, int col, int nextCol)>();

			var maxHitsChange = -1;

			for (int i = 0; i < n; i++)
			{
				var rowBestMoves = GetBestMoveForRow(i);

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

		private static void MakeMove(int row, int nextCol)
		{
			var col = queens[row];

			queens[row] = nextCol;

			// Update old position
			if (col >= 0)
			{
				UpdateMatrix(row, col, -1);
			}

			// Update new position
			UpdateMatrix(row, nextCol, 1);
		}

		public static void UpdateMatrix(int row, int col, int increment)
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

		public static void Solve()
		{
			while (true)
			{
				if (IsSolution())
				{
					return;
				}

				var nextMoves = GetBestMoves();

				if (nextMoves.Count == 0)
				{
					Restart();
					continue;
				}

				var randomIndex = random.Next(0, nextMoves.Count);

				var (row, col, nextCol) = nextMoves[randomIndex];

				MakeMove(row, nextCol);

				steps++;

				if (steps > MaxSteps)
				{
					Restart();
				}
			}
		}

		private static bool IsSolution()
		{
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
