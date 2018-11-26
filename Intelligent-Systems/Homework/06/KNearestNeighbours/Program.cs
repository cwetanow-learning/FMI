using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KNearestNeighbours
{
	public enum InstanceClass
	{
		Setosa,
		Versicolour,
		Virginica
	}

	public class Instance
	{

		public InstanceClass Class { get; set; }

		public double SepalLength { get; set; }
		public double SepalWidth { get; set; }

		public double PetalLength { get; set; }
		public double PetalWidth { get; set; }
	}

	public class GroupedNeighbours : IComparable<GroupedNeighbours>
	{
		public InstanceClass Classification { get; set; }
		public double DistanceSum { get; set; }

		public int CompareTo(GroupedNeighbours other)
		{
			return this.DistanceSum.CompareTo(other.DistanceSum);
		}
	}

	public class Program
	{
		public static IEnumerable<Instance> TrainingData;

		public static void Main(string[] args)
		{
			var dataset = GetData("../../../iris.txt");
			dataset.Shuffle();

			var k = (int)Math.Sqrt(dataset.Count);

			var errors = DoTest(dataset, k, 5);
			Console.WriteLine(errors / (double)5);
		}

		public static void TestWithDifferentK(IList<Instance> dataset)
		{
			var n = dataset.Count / 5;

			var results = Enumerable.Range(5, n - 5)
				.ToDictionary(item => item, item => 0.0);

			var repeats = 10;

			for (int j = 0; j < repeats; j++)
			{
				dataset.Shuffle();
				for (int k = 5; k < n; k++)
				{
					var errors = DoTest(dataset, k, 5);

					results[k] += errors;
				}
			}

			foreach (var kvp in results)
			{
				var result = 100 - kvp.Value / (repeats * 5);
				Console.WriteLine($"K: {kvp.Key}; Accuracy {result}%");
			}
		}

		public static int DoTest(IList<Instance> dataset, int k, int n)
		{
			var errors = 0;

			var nthOfDataset = dataset.Count / n;

			for (var i = 0; i < n; i++)
			{
				var testData = dataset
					.Skip(nthOfDataset * i)
					.Take(nthOfDataset)
					.ToList();

				TrainingData = dataset
					.Except(testData)
					.ToList();

				foreach (var item in testData)
				{
					var classification = Classify(item, k);

					if (classification != item.Class)
					{
						errors++;
					}
				}
			}

			return errors;
		}

		public static InstanceClass Classify(Instance instance, int k)
		{
			var nearestNeighbours = GetNearestNeighbours(instance, k);

			var classification = nearestNeighbours
				.GroupBy(n => n.Class)
				.Select(group => new { classification = group.Key, distanceSum = group.Select(x => 1 / GetDistance(instance, x)).Sum() })
				.OrderByDescending(x => x.distanceSum)
				.Select(x => x.classification)
				.FirstOrDefault();

			return classification;
		}

		public static ICollection<Instance> GetNearestNeighbours(Instance instance, int k)
		{
			var neighbours = TrainingData
				.OrderBy(i => GetDistance(instance, i))
				.Take(k)
				.ToList();

			return neighbours;
		}

		public static double GetDistance(Instance instance, Instance otherInstance)
		{
			var distance = Math.Pow(instance.PetalLength - otherInstance.PetalLength, 2);
			distance += Math.Pow(instance.PetalWidth - otherInstance.PetalWidth, 2);
			distance += Math.Pow(instance.SepalLength - otherInstance.SepalLength, 2);
			distance += Math.Pow(instance.SepalWidth - otherInstance.SepalWidth, 2);

			distance = Math.Sqrt(distance);

			return distance;
		}

		public static IList<Instance> GetData(string filename)
		{
			var dataset = new List<Instance>();

			var reader = new StreamReader(filename);
			var line = string.Empty;

			while (true)
			{
				line = reader.ReadLine();

				if (string.IsNullOrEmpty(line))
				{
					break;
				}

				var splitted = line
					.Split(',', StringSplitOptions.RemoveEmptyEntries)
					.Select(x => x.Replace('.', ','))
					.ToList();

				var entry = new Instance {
					SepalLength = double.Parse(splitted[0]),
					SepalWidth = double.Parse(splitted[1]),
					PetalLength = double.Parse(splitted[2]),
					PetalWidth = double.Parse(splitted[3]),
					Class = GetClass(splitted[4])
				};

				dataset.Add(entry);
			}

			return dataset;
		}

		public static InstanceClass GetClass(string element)
		{
			if (element.Contains(InstanceClass.Setosa.ToString().ToLower()))
			{
				return InstanceClass.Setosa;
			}

			if (element.Contains(InstanceClass.Versicolour.ToString().ToLower()))
			{
				return InstanceClass.Versicolour;
			}

			if (element.Contains(InstanceClass.Virginica.ToString().ToLower()))
			{
				return InstanceClass.Virginica;
			}

			return 0;
		}
	}
}
