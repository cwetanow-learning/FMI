using System;
using System.Collections.Generic;
using System.Linq;

namespace Solution
{
	public class Program
	{
		public static int NumberOfItems;
		public static int MaximumWeight;

		public static List<(int Weight, int Value)> items = new List<(int Weight, int Value)>();

		public static void Main(string[] args)
		{
			ParseInput();


		}

		public static List<bool[]> CreateInitialPopulation()
		{
			var population = new List<bool[]>();



			return population;
		}

		public static bool IsValid(bool[] element)
		{
			var totalWeight = 0;

			for (int i = 0; i < NumberOfItems; i++)
			{
				if (element[i])
				{
					totalWeight += items[i].Weight;

					if (totalWeight > MaximumWeight)
					{
						return false;
					}
				}
			}

			return true;
		}

		public static int Fitness(bool[] element)
		{
			var result = 0;

			for (int i = 0; i < NumberOfItems; i++)
			{
				if (element[i])
				{
					result += items[i].Value;
				}
			}

			return result;
		}

		public static void ParseInput()
		{
			var input = Console.ReadLine()
							.Split(' ')
							.Select(int.Parse)
							.ToList();

			NumberOfItems = input[1];
			MaximumWeight = input[0];

			for (int i = 0; i < NumberOfItems; i++)
			{
				input = Console.ReadLine()
							.Split(' ')
							.Select(int.Parse)
							.ToList();

				items.Add((input[0], input[1]));
			}
		}
	}
}
