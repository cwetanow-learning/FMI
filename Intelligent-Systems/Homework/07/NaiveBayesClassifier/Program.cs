using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace NaiveBayesClassifier
{
	public class Program
	{
		public static void Main(string[] args)
		{
			var dataset = GetDataset("../../../data.txt");
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
					HandicappedInfants = splitted[1] == "?" ? (bool?)null : splitted[1] == "y",
					WaterProjectCostSharing = splitted[2] == "?" ? (bool?)null : splitted[2] == "y",
					AdoptionOfTheBudgetResolution = splitted[3] == "?" ? (bool?)null : splitted[3] == "y",
					PhysicianFeeFreeze = splitted[4] == "?" ? (bool?)null : splitted[4] == "y",
					ElSalvadorAid = splitted[5] == "?" ? (bool?)null : splitted[5] == "y",
					ReligiousGroupsInSchools = splitted[6] == "?" ? (bool?)null : splitted[6] == "y",
					AntiSatelliteTestBan = splitted[7] == "?" ? (bool?)null : splitted[7] == "y",
					AidToNicaraguanContras = splitted[8] == "?" ? (bool?)null : splitted[8] == "y",
					MxMissile = splitted[9] == "?" ? (bool?)null : splitted[9] == "y",
					Immigration = splitted[10] == "?" ? (bool?)null : splitted[10] == "y",
					SynfuelsCorporationCutback = splitted[11] == "?" ? (bool?)null : splitted[11] == "y",
					EducationSpending = splitted[12] == "?" ? (bool?)null : splitted[12] == "y",
					SuperfundRightToSue = splitted[13] == "?" ? (bool?)null : splitted[13] == "y",
					Crime = splitted[14] == "?" ? (bool?)null : splitted[14] == "y",
					DutyFreeExports = splitted[15] == "?" ? (bool?)null : splitted[15] == "y",
					ExportAdministrationActSouthAfrica = splitted[16] == "?" ? (bool?)null : splitted[16] == "y"
				};

				dataset.Add(instance);
			}

			return dataset;
		}
	}
}
