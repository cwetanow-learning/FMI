using System;
using System.Collections.Generic;
using System.IO;
using System.Windows.Forms;

namespace TextChangeLib
{
	public partial class TextGenerator : UserControl
	{
		private const string TxtExtension = ".txt";
		private const int GenerateCount = 50;

		private List<string> codes;

		private List<string> letters = new List<string>
		{
			"у", "е", "и", "ш", "щ", "к", "с", "д", "з", "ц", "ь", "я", "а", "о", "ж", "г", "т", "н", "в", "м", "ч", "ю", "й", "ъ", "э", "ф", "х", "п", "р", "л", "б"
		};

		public TextGenerator()
		{
			InitializeComponent();
			this.codes = new List<string>();
		}

		public event TextChangeEventHandler TextChange;

		private void btnWriteToFile_Click(object sender, EventArgs e)
		{
			this.saveFileDialog.ShowDialog();
			var fileName = this.saveFileDialog.FileName;
			fileName = fileName.EndsWith(TxtExtension) ? fileName : fileName + TxtExtension;

			File.AppendAllText(fileName, string.Join("", this.codes));
		}

		private void btnQuit_Click(object sender, EventArgs e)
		{
			Environment.Exit(0);
		}

		private void btnReadFromFile_Click(object sender, EventArgs e)
		{
			this.openFileDialog.ShowDialog();
			var fileName = this.openFileDialog.FileName;

			var text = File.ReadAllText(fileName);

			foreach (var character in text)
			{
				this.codes.Add(character.ToString());
			}
		}

		private void btnGenerateRandomCode_Click(object sender, EventArgs e)
		{
			var random = new Random();
			for (int i = 0; i < GenerateCount; i++)
			{
				var next = letters[random.Next(0, 31)];
				this.codes.Add(next);
			}

			if (this.TextChange != null)
			{
				var args = new TextChangeEventArgs(this.codes);

				this.TextChange(this, args);
			}
		}
	}
}
