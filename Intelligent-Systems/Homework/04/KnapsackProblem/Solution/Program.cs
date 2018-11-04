using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Solution
{
	public class Program
	{
		public static int NumberOfItems;
		public static int MaximumWeight;
		public static int SizeOfPopulation;

		public static Random random = new Random();

		public static List<(int Weight, int Value)> items = new List<(int Weight, int Value)>();

		public static void Main(string[] args)
		{
			ParseInput();

			var population = CreateInitialPopulation();

			Evolution(population, SizeOfPopulation, 7, 30);
		}

		public static void Evolution(List<bool[]> population, int crossoversCount, int mutationPercent, int ages)
		{
			for (int i = 0; i < ages; i++)
			{
				population = PassAge(population, crossoversCount, mutationPercent);

				var fittest = population[0];

				var value = 0;
				for (int j = 0; j < NumberOfItems; j++)
				{
					if (fittest[j])
					{
						value += items[j].Value;
					}
				}

				Console.WriteLine($"{string.Join(' ', fittest.Select(x => x ? 1 : 0))} - {value}");
			}
		}

		private static List<bool[]> PassAge(List<bool[]> population, int crossoversCount, int mutationPercent)
		{
			var children = AgeCrossovers(population, crossoversCount, mutationPercent);
			population.AddRange(children);

			var nextPopulation = population
				.OrderByDescending(element => Fitness(element))
				.Take(SizeOfPopulation)
				.ToList();

			return nextPopulation;
		}

		public static List<bool[]> AgeCrossovers(List<bool[]> population, int crossoversCount, int mutationPercent)
		{
			var children = new List<bool[]>();

			var pool = population
				.SelectMany((element, index) => {
					return Enumerable.Repeat(index, index + 1);
				})
				.ToList();

			while (crossoversCount > 0)
			{
				var child = (bool[])null;

				while (!IsValid(child))
				{
					var firstParentIndex = random.Next(0, pool.Count());
					var secondParentIndex = random.Next(0, pool.Count());

					while (firstParentIndex == secondParentIndex)
					{
						secondParentIndex = random.Next(0, pool.Count());
					}

					var firstParent = population[pool[firstParentIndex]];
					var secondParent = population[pool[secondParentIndex]];
					child = Crossover(firstParent, secondParent);

					if (random.Next(1, 101) <= mutationPercent)
					{
						child = Mutate(child);
					}
				}

				children.Add(child);

				crossoversCount--;
			}

			return children;
		}

		public static bool[] Crossover(bool[] firstParent, bool[] secondParent)
		{
			var child = new List<bool>();

			var changeCount = random.Next(1, NumberOfItems + 1);

			var firstParentPart = firstParent.Take(changeCount);
			child.AddRange(firstParentPart);

			var secondParentPart = secondParent.Skip(changeCount);
			child.AddRange(secondParentPart);

			return child.ToArray();
		}

		//public static List<bool[]> AgeMutation(List<bool[]> population, int mutationPercent)
		//{
		//	var mutatedElements = population
		//		.Where(element => random.Next(1, 101) <= mutationPercent)
		//		.Select(Mutate)
		//		.ToList();

		//	return mutatedElements;
		//}

		public static bool[] Mutate(bool[] element)
		{
			var firstIndex = random.Next(0, NumberOfItems);
			var secondIndex = random.Next(firstIndex + 1, NumberOfItems);

			var sequence = element
				.Skip(firstIndex)
				.Take(secondIndex - firstIndex)
				.Reverse()
				.ToList();

			var newElement = element
				.Take(firstIndex)
				.ToList();

			newElement.AddRange(sequence);
			newElement.AddRange(element.Skip(secondIndex));

			return newElement.ToArray();
		}

		public static List<bool[]> CreateInitialPopulation()
		{
			var population = new List<bool[]>();

			var populationCheckHashSet = new HashSet<string>();

			var remainingItems = SizeOfPopulation;

			while (remainingItems > 0)
			{
				var (element, joinedElement) = CreateRandomElement();

				while (!IsValid(element) || populationCheckHashSet.Contains(joinedElement))
				{
					(element, joinedElement) = CreateRandomElement();
				}

				populationCheckHashSet.Add(joinedElement);
				population.Add(element);

				remainingItems--;
			}

			population = population
				.OrderByDescending(Fitness)
				.ToList();

			return population;
		}

		public static (bool[] element, string stringRepresentation) CreateRandomElement()
		{
			var element = new bool[NumberOfItems];
			var builder = new StringBuilder();

			for (int i = 0; i < NumberOfItems; i++)
			{
				element[i] = (random.Next(0, 101) % 2 == 0);
				builder.Append(element[i] ? 1 : 0);
			}

			return (element, builder.ToString());
		}

		public static bool IsValid(bool[] element)
		{
			if (element == null)
			{
				return false;
			}

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
			SizeOfPopulation = (int)Math.Log(Math.Pow(2, NumberOfItems));

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
