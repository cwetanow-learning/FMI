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
	}
}
