namespace TextChangeApp
{
	partial class TextStatistics
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

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.textGenerator = new TextChangeLib.TextGenerator();
			this.btnSortByFrequency = new System.Windows.Forms.Button();
			this.txtBoxCodes = new System.Windows.Forms.TextBox();
			this.txtBoxFrequency = new System.Windows.Forms.TextBox();
			this.lblCodes = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// textGenerator
			// 
			this.textGenerator.Location = new System.Drawing.Point(12, 12);
			this.textGenerator.Name = "textGenerator";
			this.textGenerator.Size = new System.Drawing.Size(290, 179);
			this.textGenerator.TabIndex = 0;
			// 
			// btnSortByFrequency
			// 
			this.btnSortByFrequency.Location = new System.Drawing.Point(47, 182);
			this.btnSortByFrequency.Name = "btnSortByFrequency";
			this.btnSortByFrequency.Size = new System.Drawing.Size(228, 23);
			this.btnSortByFrequency.TabIndex = 2;
			this.btnSortByFrequency.Text = "Sort by frequency";
			this.btnSortByFrequency.UseVisualStyleBackColor = true;
			this.btnSortByFrequency.Click += new System.EventHandler(this.btnSortByFrequency_Click);
			// 
			// txtBoxCodes
			// 
			this.txtBoxCodes.Location = new System.Drawing.Point(331, 82);
			this.txtBoxCodes.Multiline = true;
			this.txtBoxCodes.Name = "txtBoxCodes";
			this.txtBoxCodes.Size = new System.Drawing.Size(368, 278);
			this.txtBoxCodes.TabIndex = 3;
			// 
			// txtBoxFrequency
			// 
			this.txtBoxFrequency.Location = new System.Drawing.Point(47, 236);
			this.txtBoxFrequency.Multiline = true;
			this.txtBoxFrequency.Name = "txtBoxFrequency";
			this.txtBoxFrequency.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.txtBoxFrequency.Size = new System.Drawing.Size(228, 124);
			this.txtBoxFrequency.TabIndex = 4;
			// 
			// lblCodes
			// 
			this.lblCodes.AutoSize = true;
			this.lblCodes.Location = new System.Drawing.Point(328, 46);
			this.lblCodes.Name = "lblCodes";
			this.lblCodes.Size = new System.Drawing.Size(37, 13);
			this.lblCodes.TabIndex = 5;
			this.lblCodes.Text = "Codes";
			// 
			// TextStatistics
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(735, 377);
			this.Controls.Add(this.lblCodes);
			this.Controls.Add(this.txtBoxFrequency);
			this.Controls.Add(this.txtBoxCodes);
			this.Controls.Add(this.btnSortByFrequency);
			this.Controls.Add(this.textGenerator);
			this.Name = "TextStatistics";
			this.Text = "Form1";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private TextChangeLib.TextGenerator textGenerator;
		private System.Windows.Forms.Button btnSortByFrequency;
		private System.Windows.Forms.TextBox txtBoxCodes;
		private System.Windows.Forms.TextBox txtBoxFrequency;
		private System.Windows.Forms.Label lblCodes;
	}
}

