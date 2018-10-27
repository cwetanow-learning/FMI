using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace SlidingBlocks
{
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

		public static bool IsSolution(int[][] blocks, int size)
		{
			if (blocks[size - 1][size - 1] != 0)
			{
				return false;
			}

			var currentNumber = 1;

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (i == size - 1 && j == size - 1)
					{
						break;
					}

					if (blocks[i][j] != currentNumber)
					{
						return false;
					}

					currentNumber++;
				}
			}



			return true;
		}
	}
}
