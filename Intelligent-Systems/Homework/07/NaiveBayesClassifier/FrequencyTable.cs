using System.Collections.Generic;

namespace NaiveBayesClassifier
{
	public class FrequencyTable<TOption>
	{
		public FrequencyTable()
		{
			this.Options = new Dictionary<TOption, int>();
			this.TotalItems = 0;
		}

		public int TotalItems { get; set; }

		public IDictionary<TOption, int> Options { get; set; }
	}
}
