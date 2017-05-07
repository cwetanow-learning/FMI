using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextChangeLib
{
	public delegate void TextChangeEventHandler(object sender, TextChangeEventArgs e);

	public class TextChangeEventArgs
	{
		public TextChangeEventArgs() : this(new List<string>())
		{
		}

		public TextChangeEventArgs(List<string> codes)
		{
			this.Codes = codes;
		}

		public List<string> Codes { get; private set; }
	}
}
