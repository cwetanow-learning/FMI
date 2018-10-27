using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

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

			var matrix = new int[size][];

			for (int i = 0; i < size; i++)
			{
				matrix[i] = Console.ReadLine()
					.Split(' ')
					.Select(int.Parse)
					.ToArray();
			}
		}
	}
}
