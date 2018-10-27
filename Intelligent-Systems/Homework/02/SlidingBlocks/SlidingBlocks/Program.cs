using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using Wintellect.PowerCollections;

namespace SlidingBlocks
{
	public enum Direction
	{
		Root,
		Up,
		Down,
		Left,
		Right
	}

	public class Node : IComparable<Node>
	{
		public Node(int h, int g, int[][] matrix)
		{
			this.H = h;
			this.G = g;
			this.F = this.H + this.G;

			this.Matrix = matrix;
		}

		public int F { get; set; }
		public int H { get; set; }
		public int G { get; set; }

		public int EmptyRow { get; set; }
		public int EmptyCol { get; set; }

		public Direction Direction { get; set; }
		public Node Parent { get; set; }

		public int[][] Matrix { get; set; }

		public int CompareTo(Node other)
		{
			return this.F.CompareTo(other.F);
		}
	}

	public class Program
	{
		public static void Main(string[] args)
		{
			var n = int.Parse(Console.ReadLine());

			var size = (int)Math.Sqrt(n + 1);

			var blocks = new int[size][];

			for (int i = 0; i < size; i++)
			{
				blocks[i] = Console.ReadLine()
					.Split(' ')
					.Select(int.Parse)
					.ToArray();
			}

			var heuristic = GetHeuristic(blocks, size);

			var root = new Node(heuristic, 0, blocks) {
				Direction = Direction.Root
			};

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (blocks[i][j] == 0)
					{
						root.EmptyCol = j;
						root.EmptyRow = i;
						break;
					}
				}
			}

			var solution = Solve(root, size);
		}

		public static Node Solve(Node root, int size)
		{
			var bag = new OrderedBag<Node> {
				root
			};

			while (bag.Count > 0)
			{
				var current = bag.RemoveFirst();

				if (current.H == 0)
				{
					return current;
				}

				var children = GetChildren(current, size);

				foreach (var child in children)
				{
					bag.Add(child);
				}
			}

			return null;
		}

		public static IEnumerable<Node> GetChildren(Node node, int size)
		{
			var children = new List<Node>();

			if (node.EmptyRow > 0 && node.Direction != Direction.Up)
			{
				var copy = node.Matrix.Select(x => x.ToArray()).ToArray();

				var temp = copy[node.EmptyRow][node.EmptyCol];
				copy[node.EmptyRow][node.EmptyCol] = copy[node.EmptyRow - 1][node.EmptyCol];
				copy[node.EmptyRow - 1][node.EmptyCol] = temp;

				var heuristic = GetHeuristic(copy, size);

				var newNode = new Node(heuristic, node.G + 1, copy) {
					Parent = node,
					EmptyCol = node.EmptyCol,
					EmptyRow = node.EmptyRow - 1,
					Direction = Direction.Down
				};

				children.Add(newNode);
			}

			if (node.EmptyRow < size - 1 && node.Direction != Direction.Down)
			{
				var copy = node.Matrix.Select(x => x.ToArray()).ToArray();

				var temp = copy[node.EmptyRow][node.EmptyCol];
				copy[node.EmptyRow][node.EmptyCol] = copy[node.EmptyRow + 1][node.EmptyCol];
				copy[node.EmptyRow + 1][node.EmptyCol] = temp;

				var heuristic = GetHeuristic(copy, size);

				var newNode = new Node(heuristic, node.G + 1, copy) {
					Parent = node,
					EmptyCol = node.EmptyCol,
					EmptyRow = node.EmptyRow + 1,
					Direction = Direction.Up
				};

				children.Add(newNode);
			}

			if (node.EmptyCol > 0 && node.Direction != Direction.Left)
			{
				var copy = node.Matrix.Select(x => x.ToArray()).ToArray();

				var temp = copy[node.EmptyRow][node.EmptyCol];
				copy[node.EmptyRow][node.EmptyCol] = copy[node.EmptyRow][node.EmptyCol - 1];
				copy[node.EmptyRow][node.EmptyCol - 1] = temp;

				var heuristic = GetHeuristic(copy, size);

				var newNode = new Node(heuristic, node.G + 1, copy) {
					Parent = node,
					EmptyCol = node.EmptyCol - 1,
					EmptyRow = node.EmptyRow,
					Direction = Direction.Right
				};

				children.Add(newNode);
			}

			if (node.EmptyCol < size - 1 && node.Direction != Direction.Right)
			{
				var copy = node.Matrix.Select(x => x.ToArray()).ToArray();

				var temp = copy[node.EmptyRow][node.EmptyCol];
				copy[node.EmptyRow][node.EmptyCol] = copy[node.EmptyRow][node.EmptyCol + 1];
				copy[node.EmptyRow][node.EmptyCol + 1] = temp;

				var heuristic = GetHeuristic(copy, size);

				var newNode = new Node(heuristic, node.G + 1, copy) {
					Parent = node,
					EmptyCol = node.EmptyCol + 1,
					EmptyRow = node.EmptyRow,
					Direction = Direction.Left
				};

				children.Add(newNode);
			}

			return children;
		}

		public static int GetHeuristic(int[][] blocks, int size)
		{
			var result = 0;
			var number = 1;

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					var current = blocks[i][j];

					if (current != number && current != 0)
					{
						var solutionRow = current / size;
						var solutionCol = current % size - 1;

						if (current % size == 0)
						{
							solutionRow--;
							solutionCol = size - 1;
						}

						var distance = Math.Abs(i - solutionRow) + Math.Abs(j - solutionCol);

						if (distance > 0)
						{
							result += distance;
						}
					}

					number++;
				}
			}

			return result;
		}
	}
}
