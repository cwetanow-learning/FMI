﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Solution
{
	public class Program
	{
		public class Element
		{
			public Element()
			{
				this.Chromosomes = new bool[NumberOfItems];
			}

			public bool[] Chromosomes { get; set; }

			public int Fitness { get; set; }

			public int Weight { get; set; }

			public string Representation { get; set; }
		}

		public static int NumberOfItems;
		public static int MaximumWeight;
		public static int SizeOfPopulation;

		public static Random random = new Random();

		public static List<(int Weight, int Value)> items = new List<(int Weight, int Value)>();

		public static void Main(string[] args)
		{
			ParseInput();

			var population = CreateInitialPopulation();

			Evolution(population, SizeOfPopulation, 7, 100);
		}

		public static void Evolution(List<Element> population, int crossoversCount, int mutationPercent, int ages)
		{
			var fittest = population[0];
			var counter = 0;

			for (int i = 0; i < ages; i++)
			{
				population = PassAge(population, crossoversCount, mutationPercent);

				var newFittest = population[0];

				if (newFittest.Fitness > fittest.Fitness)
				{
					counter = 0;
					fittest = newFittest;
				}
				else
				{
					counter++;
				}

				Console.WriteLine($"{fittest.Representation} - {fittest.Fitness}");
				if (counter > 5)
				{
					Console.WriteLine("No progress last 5 ages");
					break;
				}
			}
		}

		private static List<Element> PassAge(List<Element> population, int crossoversCount, int mutationPercent)
		{
			var children = AgeCrossovers(population, crossoversCount, mutationPercent);
			population.AddRange(children);

			var nextPopulation = population
				.OrderByDescending(element => element.Fitness)
				.Take(SizeOfPopulation)
				.ToList();

			return nextPopulation;
		}

		public static List<Element> AgeCrossovers(List<Element> population, int crossoversCount, int mutationPercent)
		{
			var children = new List<Element>();

			var pool = population
				.SelectMany((element, index) => {
					return Enumerable.Repeat(index, index + 1);
				})
				.ToList();

			while (crossoversCount > 0)
			{
				var child = (Element)null;

				while (!IsValid(child))
				{
					var poolSize = pool.Count;

					var firstParentIndex = random.Next(0, poolSize);
					var secondParentIndex = random.Next(0, poolSize);

					while (firstParentIndex == secondParentIndex)
					{
						secondParentIndex = random.Next(0, poolSize);
					}

					var firstParent = population[pool[firstParentIndex]];
					var secondParent = population[pool[secondParentIndex]];
					child = Crossover(firstParent, secondParent);

					if (random.Next(1, 101) <= mutationPercent)
					{
						child = Mutate(child);
					}
					SetCharacteristics(child);
				}

				SetCharacteristics(child);

				children.Add(child);

				crossoversCount--;
			}

			return children;
		}

		public static Element Crossover(Element firstParent, Element secondParent)
		{
			var childChromosomes = new List<bool>();

			var changeCount = random.Next(1, NumberOfItems + 1);

			var firstParentPart = firstParent.Chromosomes.Take(changeCount);
			childChromosomes.AddRange(firstParentPart);

			var secondParentPart = secondParent.Chromosomes.Skip(changeCount);
			childChromosomes.AddRange(secondParentPart);

			var child = new Element { Chromosomes = childChromosomes.ToArray() };

			return child;
		}

		public static Element Mutate(Element element)
		{
			var firstIndex = random.Next(0, NumberOfItems);
			var secondIndex = random.Next(firstIndex + 1, NumberOfItems);

			var sequence = element
				.Chromosomes
				.Skip(firstIndex)
				.Take(secondIndex - firstIndex)
				.Reverse()
				.ToList();

			var newChromosomes = element
				.Chromosomes
				.Take(firstIndex)
				.ToList();

			newChromosomes.AddRange(sequence);
			newChromosomes.AddRange(element.Chromosomes.Skip(secondIndex));
			element.Chromosomes = newChromosomes.ToArray();

			return element;
		}

		public static List<Element> CreateInitialPopulation()
		{
			var populationCheck = new Dictionary<string, Element>();

			var remainingItems = SizeOfPopulation;

			while (remainingItems > 0)
			{
				var element = CreateRandomElement();

				while (!IsValid(element) || populationCheck.ContainsKey(element.Representation))
				{
					element = CreateRandomElement();
				}

				populationCheck.Add(element.Representation, element);

				remainingItems--;
			}

			var population = populationCheck
					.Select(kvp => kvp.Value)
					.OrderByDescending(element => element.Fitness)
					.ToList();

			return population;
		}

		public static Element CreateRandomElement()
		{
			var element = new Element();

			var indexes = Enumerable.Range(0, NumberOfItems)
				.ToHashSet();

			var iterations = NumberOfItems;

			while (iterations > 0)
			{
				var randomIndex = random.Next(0, NumberOfItems);

				while (!indexes.Contains(randomIndex))
				{
					randomIndex = random.Next(0, NumberOfItems);
				}

				var isAdded = (random.Next(0, 101) % 2 == 0);

				if (isAdded)
				{
					if (element.Weight + items[randomIndex].Weight > MaximumWeight)
					{
						break;
					}

					element.Weight += items[randomIndex].Weight;
				}

				element.Chromosomes[randomIndex] = isAdded;

				indexes.Remove(randomIndex);
				iterations--;
			}

			SetCharacteristics(element);

			return element;
		}

		public static bool IsValid(Element element)
		{
			return element != null && element.Weight <= MaximumWeight;
		}

		public static int GetWeight(Element element)
		{
			var weight = 0;

			for (int i = 0; i < NumberOfItems; i++)
			{
				if (element.Chromosomes[i])
				{
					weight += items[i].Weight;
				}
			}

			return weight;
		}

		public static int Fitness(Element element)
		{
			var result = 0;

			for (int i = 0; i < NumberOfItems; i++)
			{
				if (element.Chromosomes[i])
				{
					result += items[i].Value;
				}
			}

			return result;
		}

		public static void SetCharacteristics(Element element)
		{
			element.Fitness = Fitness(element);

			if (element.Weight == 0)
			{
				element.Weight = GetWeight(element);
			}

			var builder = new StringBuilder();
			foreach (var chromosome in element.Chromosomes)
			{
				builder.Append(chromosome ? '1' : '0');
			}

			element.Representation = builder.ToString();
		}

		public static void ParseInput()
		{
			var input = Console.ReadLine()
							.Split(' ')
							.Select(int.Parse)
							.ToList();

			NumberOfItems = input[1];
			MaximumWeight = input[0];
			SizeOfPopulation = NumberOfItems;

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
