using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TextChangeLib;

namespace TextChangeApp
{
	public partial class TextStatistics : Form
	{
		private Dictionary<char, int> counters;

		public TextStatistics()
		{
			InitializeComponent();
			this.textGenerator.TextChange += new TextChangeEventHandler(this.HandleTextChanged);
			this.counters = new Dictionary<char, int>();
		}

		private void HandleTextChanged(object sender, TextChangeEventArgs e)
		{
			this.txtBoxCodes.Text += string.Join("", e.Codes);
		}

		private void btnSortByFrequency_Click(object sender, EventArgs e)
		{
			foreach (var item in this.txtBoxCodes.Text)
			{
				if (this.counters.ContainsKey(item))
				{
					this.counters[item]++;
				}
				else
				{
					this.counters[item] = 1;
				}
			}

			this.txtBoxFrequency.Text = this.GetFormattedCounters(this.counters.OrderByDescending(x => x.Value));
		}

		private string GetFormattedCounters(IOrderedEnumerable<KeyValuePair<char, int>> countersDictionary)
		{
			var result = new StringBuilder();
			foreach (var counter in countersDictionary)
			{
				var line = string.Format("Character {0}: {1} Times", counter.Key, counter.Value);
				result.AppendLine(line);
			}

			return result.ToString();
		}
	}
}
