﻿using System.Collections.Generic;

namespace NaiveBayesClassifier
{
	public class Instance
	{
		public string ClassName { get; set; }

		public IDictionary<string, bool?> Classes { get; set; }
	}
}
