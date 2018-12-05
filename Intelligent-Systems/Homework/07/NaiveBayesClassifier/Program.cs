using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace NaiveBayesClassifier
{
	public class Program
	{
		private static readonly string[] OptionNames = {
			"HandicappedInfants",
			"WaterProjectCostSharing",
			"AdoptionOfTheBudgetResolution",
			"PhysicianFeeFreeze",
			"ElSalvadorAid",
			"ReligiousGroupsInSchools",
			"AntiSatelliteTestBan",
			"AidToNicaraguanContras",
			"MxMissile",
			"Immigration",
			"SynfuelsCorporationCutback",
			"EducationSpending",
			"SuperfundRightToSue",
			"Crime",
			"DutyFreeExports",
			"ExportAdministrationActSouthAfrica"
		};

		private static readonly HashSet<string> Classes = new HashSet<string>();

		public static void Main(string[] args)
		{
			var dataset = GetDataset("../../../data.txt");
			dataset.Shuffle();

			DoTests(dataset);
		}

		public static void DoTests(IList<Instance> dataset)
		{
			var n = 10;
			var nthOfDatasetCount = dataset.Count / n;

			for (int i = 0; i < n; i++)
			{
				var testData = dataset
					.Skip(i * nthOfDatasetCount)
					.Take(nthOfDatasetCount)
					.ToList();

				var trainingData = dataset
					.Except(testData)
					.ToList();

				var errors = Test(trainingData, testData);

				Console.WriteLine($"{i + 1}th of dataset; {errors} errors from {testData.Count} attempts; {1 - ((double)errors / testData.Count)}%");
			}
		}

		public static int Test(List<Instance> trainingData, List<Instance> testData)
		{
			var erros = 0;

			var frequencyTables = GetFrequencyTables(trainingData);
			var classProbabilities = GetClassProbabilities(trainingData);

			foreach (var item in testData)
			{
				var classification = Classify(item, frequencyTables, classProbabilities);

				if (!classification.Equals(item.ClassName))
				{
					erros++;
				}
			}

			return erros;
		}

		private static Dictionary<string, double> GetClassProbabilities(List<Instance> trainingData)
		{
			var totalItems = trainingData.Count;

			return trainingData
					.GroupBy(instance => instance.ClassName)
					.ToDictionary(group => group.Key, group => group.Count() / (double)totalItems);

		}

		private static string Classify(Instance item, Dictionary<string, Dictionary<string, FrequencyTable<bool>>> frequencyTables, Dictionary<string, double> classProbabilities)
		{
			var classification = string.Empty;
			var bestProbability = double.MinValue;

			foreach (var @class in Classes)
			{
				var probability = classProbabilities[@class];

				foreach (var option in item.Options)
				{
					if (option.Value.HasValue)
					{
						var optionFrequencyTable = frequencyTables[@class][option.Key];

						if (optionFrequencyTable.Options.ContainsKey(option.Value.Value))
						{
							var optionProbability = optionFrequencyTable.Options[option.Value.Value] / (double)optionFrequencyTable.TotalItems;

							probability *= optionProbability;
						}
						else
						{
							probability = 0;
							break;
						}
					}
				}

				if (probability > bestProbability)
				{
					bestProbability = probability;
					classification = @class;
				}
			}

			return classification;
		}

		private static Dictionary<string, Dictionary<string, FrequencyTable<bool>>> GetFrequencyTables(List<Instance> trainingData)
		{
			var frequencyTables = new Dictionary<string, Dictionary<string, FrequencyTable<bool>>>();

			foreach (var item in trainingData)
			{
				var itemClass = item.ClassName;

				if (!frequencyTables.ContainsKey(itemClass))
				{
					frequencyTables.Add(itemClass, new Dictionary<string, FrequencyTable<bool>>());
				}

				var classFrequencyTable = frequencyTables[itemClass];

				foreach (var option in item.Options)
				{
					if (option.Value.HasValue)
					{
						if (!classFrequencyTable.ContainsKey(option.Key))
						{
							classFrequencyTable.Add(option.Key, new FrequencyTable<bool>());
						}

						var optionTable = classFrequencyTable[option.Key];

						if (!optionTable.Options.ContainsKey(option.Value.Value))
						{
							optionTable.Options.Add(option.Value.Value, 0);
						}

						optionTable.Options[option.Value.Value] = optionTable.Options[option.Value.Value] + 1;
						optionTable.TotalItems++;
					}
				}
			}

			return frequencyTables;
		}

		public static IList<Instance> GetDataset(string filename)
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
					.Split(',')
					.ToList();

				var instance = new Instance {
					ClassName = splitted[0],
					Options = GetClasses(splitted.Skip(1).ToList())
				};

				if (!Classes.Contains(instance.ClassName))
				{
					Classes.Add(instance.ClassName);
				}

				dataset.Add(instance);
			}

			return dataset;
		}

		private static IDictionary<string, bool?> GetClasses(List<string> values)
		{
			var classes = OptionNames
				.Select((@class, index) => new { Class = @class, Value = values[index] == "?" ? (bool?)null : values[index] == "y" })
				.ToDictionary(x => x.Class, x => x.Value);

			return classes;
		}
	}
}
