namespace TextChangeLib
{
	partial class TextGenerator
	{
		/// <summary> 
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary> 
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Component Designer generated code

		/// <summary> 
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.btnWriteToFile = new System.Windows.Forms.Button();
			this.btnReadFromFile = new System.Windows.Forms.Button();
			this.btnQuit = new System.Windows.Forms.Button();
			this.btnGenerateRandomCode = new System.Windows.Forms.Button();
			this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
			this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
			this.SuspendLayout();
			// 
			// btnWriteToFile
			// 
			this.btnWriteToFile.Location = new System.Drawing.Point(38, 44);
			this.btnWriteToFile.Name = "btnWriteToFile";
			this.btnWriteToFile.Size = new System.Drawing.Size(97, 23);
			this.btnWriteToFile.TabIndex = 0;
			this.btnWriteToFile.Text = "Write to file";
			this.btnWriteToFile.UseVisualStyleBackColor = true;
			this.btnWriteToFile.Click += new System.EventHandler(this.btnWriteToFile_Click);
			// 
			// btnReadFromFile
			// 
			this.btnReadFromFile.Location = new System.Drawing.Point(168, 44);
			this.btnReadFromFile.Name = "btnReadFromFile";
			this.btnReadFromFile.Size = new System.Drawing.Size(95, 23);
			this.btnReadFromFile.TabIndex = 1;
			this.btnReadFromFile.Text = "Read from file";
			this.btnReadFromFile.UseVisualStyleBackColor = true;
			this.btnReadFromFile.Click += new System.EventHandler(this.btnReadFromFile_Click);
			// 
			// btnQuit
			// 
			this.btnQuit.Location = new System.Drawing.Point(38, 83);
			this.btnQuit.Name = "btnQuit";
			this.btnQuit.Size = new System.Drawing.Size(225, 23);
			this.btnQuit.TabIndex = 2;
			this.btnQuit.Text = "Quit";
			this.btnQuit.UseVisualStyleBackColor = true;
			this.btnQuit.Click += new System.EventHandler(this.btnQuit_Click);
			// 
			// btnGenerateRandomCode
			// 
			this.btnGenerateRandomCode.Location = new System.Drawing.Point(64, 124);
			this.btnGenerateRandomCode.Name = "btnGenerateRandomCode";
			this.btnGenerateRandomCode.Size = new System.Drawing.Size(179, 23);
			this.btnGenerateRandomCode.TabIndex = 3;
			this.btnGenerateRandomCode.Text = "Generate random code";
			this.btnGenerateRandomCode.UseVisualStyleBackColor = true;
			this.btnGenerateRandomCode.Click += new System.EventHandler(this.btnGenerateRandomCode_Click);
			// 
			// openFileDialog
			// 
			this.openFileDialog.FileName = "openFileDialog1";
			// 
			// TextGenerator
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.Controls.Add(this.btnGenerateRandomCode);
			this.Controls.Add(this.btnQuit);
			this.Controls.Add(this.btnReadFromFile);
			this.Controls.Add(this.btnWriteToFile);
			this.Name = "TextGenerator";
			this.Size = new System.Drawing.Size(290, 179);
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button btnWriteToFile;
		private System.Windows.Forms.Button btnReadFromFile;
		private System.Windows.Forms.Button btnQuit;
		private System.Windows.Forms.Button btnGenerateRandomCode;
		private System.Windows.Forms.OpenFileDialog openFileDialog;
		private System.Windows.Forms.SaveFileDialog saveFileDialog;
	}
}
