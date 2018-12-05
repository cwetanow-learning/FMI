using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace NaiveBayesClassifier
{
	public class Program
	{
		private static readonly string[] Classes = {
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

		public static void Main(string[] args)
		{
			var dataset = GetDataset("../../../data.txt");

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
			}
		}

		public static int Test(List<Instance> trainingData, List<Instance> testData)
		{
			var erros = 0;

			GetAggregatedStats(trainingData);

			foreach (var item in testData)
			{

			}

			return erros;
		}

		private static void GetAggregatedStats(List<Instance> trainingData)
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

				dataset.Add(instance);
			}

			return dataset;
		}

		private static IDictionary<string, bool?> GetClasses(List<string> values)
		{
			var classes = Classes
				.Select((@class, index) => new { Class = @class, Value = values[index] == "?" ? (bool?)null : values[index] == "y" })
				.ToDictionary(x => x.Class, x => x.Value);

			return classes;
		}
	}
}
