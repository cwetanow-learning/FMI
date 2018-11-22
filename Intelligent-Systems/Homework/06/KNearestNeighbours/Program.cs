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

	public class Program
	{
		public static void Main(string[] args)
		{
			var dataset = GetData("../../../iris.txt");
		}

		public static List<Instance> GetData(string filename)
		{
			var dataset = new List<Instance>();

			var reader = new StreamReader(filename);
			var line = string.Empty;

			do
			{
				line = reader.ReadLine();

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
			} while (!string.IsNullOrEmpty(line));


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
