using System.Collections.Generic;

namespace NaiveBayesClassifier
{
	public class FrequencyTable<TClass>
	{
		public FrequencyTable()
		{
			this.AggregatedData = new Dictionary<string, IDictionary<TClass, int>>();
			this.TotalItems = 0;
		}

		public int TotalItems { get; set; }

		public IDictionary<string, IDictionary<TClass, int>> AggregatedData { get; set; }
	}
}
