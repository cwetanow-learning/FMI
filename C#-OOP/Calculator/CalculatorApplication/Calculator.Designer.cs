namespace CalculatorApplication
{
    partial class Calculator
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
            this.txtInputField = new System.Windows.Forms.TextBox();
            this.pnlNumerics = new System.Windows.Forms.Panel();
            this.btn1 = new System.Windows.Forms.Button();
            this.btn00 = new System.Windows.Forms.Button();
            this.btn0 = new System.Windows.Forms.Button();
            this.btn9 = new System.Windows.Forms.Button();
            this.btn8 = new System.Windows.Forms.Button();
            this.btn7 = new System.Windows.Forms.Button();
            this.btn6 = new System.Windows.Forms.Button();
            this.btn3 = new System.Windows.Forms.Button();
            this.btn4 = new System.Windows.Forms.Button();
            this.btn5 = new System.Windows.Forms.Button();
            this.btn2 = new System.Windows.Forms.Button();
            this.pnlOperators = new System.Windows.Forms.Panel();
            this.btnPoint = new System.Windows.Forms.Button();
            this.btnEqual = new System.Windows.Forms.Button();
            this.btnDivide = new System.Windows.Forms.Button();
            this.btnMultiple = new System.Windows.Forms.Button();
            this.buttonMinus = new System.Windows.Forms.Button();
            this.buttonPlus = new System.Windows.Forms.Button();
            this.pnlClear = new System.Windows.Forms.Panel();
            this.btnClearAll = new System.Windows.Forms.Button();
            this.bntClear = new System.Windows.Forms.Button();
            this.btnOff = new System.Windows.Forms.Button();
            this.pnlNumerics.SuspendLayout();
            this.pnlOperators.SuspendLayout();
            this.pnlClear.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtInputField
            // 
            this.txtInputField.Location = new System.Drawing.Point(11, 20);
            this.txtInputField.Margin = new System.Windows.Forms.Padding(4);
            this.txtInputField.Name = "txtInputField";
            this.txtInputField.Size = new System.Drawing.Size(319, 22);
            this.txtInputField.TabIndex = 0;
            this.txtInputField.Text = "0";
            this.txtInputField.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // pnlNumerics
            // 
            this.pnlNumerics.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pnlNumerics.Controls.Add(this.btn1);
            this.pnlNumerics.Controls.Add(this.btn00);
            this.pnlNumerics.Controls.Add(this.btn0);
            this.pnlNumerics.Controls.Add(this.btn9);
            this.pnlNumerics.Controls.Add(this.btn8);
            this.pnlNumerics.Controls.Add(this.btn7);
            this.pnlNumerics.Controls.Add(this.btn6);
            this.pnlNumerics.Controls.Add(this.btn3);
            this.pnlNumerics.Controls.Add(this.btn4);
            this.pnlNumerics.Controls.Add(this.btn5);
            this.pnlNumerics.Controls.Add(this.btn2);
            this.pnlNumerics.Location = new System.Drawing.Point(11, 59);
            this.pnlNumerics.Margin = new System.Windows.Forms.Padding(4);
            this.pnlNumerics.Name = "pnlNumerics";
            this.pnlNumerics.Size = new System.Drawing.Size(116, 132);
            this.pnlNumerics.TabIndex = 1;
            // 
            // btn1
            // 
            this.btn1.Location = new System.Drawing.Point(8, 5);
            this.btn1.Margin = new System.Windows.Forms.Padding(4);
            this.btn1.Name = "btn1";
            this.btn1.Size = new System.Drawing.Size(32, 30);
            this.btn1.TabIndex = 4;
            this.btn1.Text = "1";
            this.btn1.UseVisualStyleBackColor = true;
            this.btn1.Click += new System.EventHandler(this.btn1_Click);
            // 
            // btn00
            // 
            this.btn00.Location = new System.Drawing.Point(36, 81);
            this.btn00.Margin = new System.Windows.Forms.Padding(4);
            this.btn00.Name = "btn00";
            this.btn00.Size = new System.Drawing.Size(60, 30);
            this.btn00.TabIndex = 14;
            this.btn00.Text = "00";
            this.btn00.UseVisualStyleBackColor = true;
            // 
            // btn0
            // 
            this.btn0.Location = new System.Drawing.Point(8, 81);
            this.btn0.Margin = new System.Windows.Forms.Padding(4);
            this.btn0.Name = "btn0";
            this.btn0.Size = new System.Drawing.Size(32, 30);
            this.btn0.TabIndex = 13;
            this.btn0.Text = "0";
            this.btn0.UseVisualStyleBackColor = true;
            this.btn0.Click += new System.EventHandler(this.btn0_Click);
            // 
            // btn9
            // 
            this.btn9.Location = new System.Drawing.Point(64, 57);
            this.btn9.Margin = new System.Windows.Forms.Padding(4);
            this.btn9.Name = "btn9";
            this.btn9.Size = new System.Drawing.Size(32, 30);
            this.btn9.TabIndex = 12;
            this.btn9.Text = "9";
            this.btn9.UseVisualStyleBackColor = true;
            this.btn9.Click += new System.EventHandler(this.btn9_Click);
            // 
            // btn8
            // 
            this.btn8.Location = new System.Drawing.Point(36, 57);
            this.btn8.Margin = new System.Windows.Forms.Padding(4);
            this.btn8.Name = "btn8";
            this.btn8.Size = new System.Drawing.Size(32, 30);
            this.btn8.TabIndex = 11;
            this.btn8.Text = "8";
            this.btn8.UseVisualStyleBackColor = true;
            this.btn8.Click += new System.EventHandler(this.btn8_Click);
            // 
            // btn7
            // 
            this.btn7.Location = new System.Drawing.Point(8, 57);
            this.btn7.Margin = new System.Windows.Forms.Padding(4);
            this.btn7.Name = "btn7";
            this.btn7.Size = new System.Drawing.Size(32, 30);
            this.btn7.TabIndex = 10;
            this.btn7.Text = "7";
            this.btn7.UseVisualStyleBackColor = true;
            this.btn7.Click += new System.EventHandler(this.btn7_Click);
            // 
            // btn6
            // 
            this.btn6.Location = new System.Drawing.Point(64, 30);
            this.btn6.Margin = new System.Windows.Forms.Padding(4);
            this.btn6.Name = "btn6";
            this.btn6.Size = new System.Drawing.Size(32, 30);
            this.btn6.TabIndex = 9;
            this.btn6.Text = "6";
            this.btn6.UseVisualStyleBackColor = true;
            this.btn6.Click += new System.EventHandler(this.btn6_Click);
            // 
            // btn3
            // 
            this.btn3.Location = new System.Drawing.Point(64, 4);
            this.btn3.Margin = new System.Windows.Forms.Padding(4);
            this.btn3.Name = "btn3";
            this.btn3.Size = new System.Drawing.Size(32, 30);
            this.btn3.TabIndex = 8;
            this.btn3.Text = "3";
            this.btn3.UseVisualStyleBackColor = true;
            this.btn3.Click += new System.EventHandler(this.btn3_Click);
            // 
            // btn4
            // 
            this.btn4.Location = new System.Drawing.Point(8, 31);
            this.btn4.Margin = new System.Windows.Forms.Padding(4);
            this.btn4.Name = "btn4";
            this.btn4.Size = new System.Drawing.Size(32, 30);
            this.btn4.TabIndex = 7;
            this.btn4.Text = "4";
            this.btn4.UseVisualStyleBackColor = true;
            this.btn4.Click += new System.EventHandler(this.btn4_Click);
            // 
            // btn5
            // 
            this.btn5.Location = new System.Drawing.Point(36, 31);
            this.btn5.Margin = new System.Windows.Forms.Padding(4);
            this.btn5.Name = "btn5";
            this.btn5.Size = new System.Drawing.Size(32, 30);
            this.btn5.TabIndex = 6;
            this.btn5.Text = "5";
            this.btn5.UseVisualStyleBackColor = true;
            this.btn5.Click += new System.EventHandler(this.btn5_Click);
            // 
            // btn2
            // 
            this.btn2.Location = new System.Drawing.Point(37, 4);
            this.btn2.Margin = new System.Windows.Forms.Padding(4);
            this.btn2.Name = "btn2";
            this.btn2.Size = new System.Drawing.Size(32, 30);
            this.btn2.TabIndex = 5;
            this.btn2.Text = "2";
            this.btn2.UseVisualStyleBackColor = true;
            this.btn2.Click += new System.EventHandler(this.btn2_Click);
            // 
            // pnlOperators
            // 
            this.pnlOperators.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pnlOperators.Controls.Add(this.btnPoint);
            this.pnlOperators.Controls.Add(this.btnEqual);
            this.pnlOperators.Controls.Add(this.btnDivide);
            this.pnlOperators.Controls.Add(this.btnMultiple);
            this.pnlOperators.Controls.Add(this.buttonMinus);
            this.pnlOperators.Controls.Add(this.buttonPlus);
            this.pnlOperators.Location = new System.Drawing.Point(149, 59);
            this.pnlOperators.Margin = new System.Windows.Forms.Padding(4);
            this.pnlOperators.Name = "pnlOperators";
            this.pnlOperators.Size = new System.Drawing.Size(95, 132);
            this.pnlOperators.TabIndex = 2;
            // 
            // btnPoint
            // 
            this.btnPoint.Location = new System.Drawing.Point(13, 94);
            this.btnPoint.Margin = new System.Windows.Forms.Padding(4);
            this.btnPoint.Name = "btnPoint";
            this.btnPoint.Size = new System.Drawing.Size(32, 30);
            this.btnPoint.TabIndex = 5;
            this.btnPoint.Text = ".";
            this.btnPoint.UseVisualStyleBackColor = true;
            // 
            // btnEqual
            // 
            this.btnEqual.Location = new System.Drawing.Point(44, 94);
            this.btnEqual.Margin = new System.Windows.Forms.Padding(4);
            this.btnEqual.Name = "btnEqual";
            this.btnEqual.Size = new System.Drawing.Size(32, 30);
            this.btnEqual.TabIndex = 5;
            this.btnEqual.Text = "=";
            this.btnEqual.UseVisualStyleBackColor = true;
            this.btnEqual.Click += new System.EventHandler(this.button13_Click);
            // 
            // btnDivide
            // 
            this.btnDivide.Location = new System.Drawing.Point(44, 65);
            this.btnDivide.Margin = new System.Windows.Forms.Padding(4);
            this.btnDivide.Name = "btnDivide";
            this.btnDivide.Size = new System.Drawing.Size(32, 30);
            this.btnDivide.TabIndex = 4;
            this.btnDivide.Text = "/";
            this.btnDivide.UseVisualStyleBackColor = true;
            this.btnDivide.Click += new System.EventHandler(this.btnDivide_Click);
            // 
            // btnMultiple
            // 
            this.btnMultiple.Location = new System.Drawing.Point(44, 37);
            this.btnMultiple.Margin = new System.Windows.Forms.Padding(4);
            this.btnMultiple.Name = "btnMultiple";
            this.btnMultiple.Size = new System.Drawing.Size(32, 30);
            this.btnMultiple.TabIndex = 5;
            this.btnMultiple.Text = "X";
            this.btnMultiple.UseVisualStyleBackColor = true;
            this.btnMultiple.Click += new System.EventHandler(this.btnMultiple_Click);
            // 
            // buttonMinus
            // 
            this.buttonMinus.Location = new System.Drawing.Point(44, 9);
            this.buttonMinus.Margin = new System.Windows.Forms.Padding(4);
            this.buttonMinus.Name = "buttonMinus";
            this.buttonMinus.Size = new System.Drawing.Size(32, 30);
            this.buttonMinus.TabIndex = 6;
            this.buttonMinus.Text = "-";
            this.buttonMinus.UseVisualStyleBackColor = true;
            this.buttonMinus.Click += new System.EventHandler(this.buttonMinus_Click);
            // 
            // buttonPlus
            // 
            this.buttonPlus.Location = new System.Drawing.Point(13, 9);
            this.buttonPlus.Margin = new System.Windows.Forms.Padding(4);
            this.buttonPlus.Name = "buttonPlus";
            this.buttonPlus.Size = new System.Drawing.Size(32, 86);
            this.buttonPlus.TabIndex = 0;
            this.buttonPlus.Text = "+";
            this.buttonPlus.UseVisualStyleBackColor = true;
            this.buttonPlus.Click += new System.EventHandler(this.buttonPlus_Click);
            // 
            // pnlClear
            // 
            this.pnlClear.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pnlClear.Controls.Add(this.btnClearAll);
            this.pnlClear.Controls.Add(this.bntClear);
            this.pnlClear.Location = new System.Drawing.Point(267, 59);
            this.pnlClear.Margin = new System.Windows.Forms.Padding(4);
            this.pnlClear.Name = "pnlClear";
            this.pnlClear.Size = new System.Drawing.Size(61, 88);
            this.pnlClear.TabIndex = 3;
            // 
            // btnClearAll
            // 
            this.btnClearAll.Location = new System.Drawing.Point(4, 46);
            this.btnClearAll.Margin = new System.Windows.Forms.Padding(4);
            this.btnClearAll.Name = "btnClearAll";
            this.btnClearAll.Size = new System.Drawing.Size(49, 30);
            this.btnClearAll.TabIndex = 6;
            this.btnClearAll.Text = "C/A";
            this.btnClearAll.UseVisualStyleBackColor = true;
            // 
            // bntClear
            // 
            this.bntClear.Location = new System.Drawing.Point(4, 9);
            this.bntClear.Margin = new System.Windows.Forms.Padding(4);
            this.bntClear.Name = "bntClear";
            this.bntClear.Size = new System.Drawing.Size(49, 30);
            this.bntClear.TabIndex = 6;
            this.bntClear.Text = "C";
            this.bntClear.UseVisualStyleBackColor = true;
            // 
            // btnOff
            // 
            this.btnOff.Location = new System.Drawing.Point(273, 162);
            this.btnOff.Margin = new System.Windows.Forms.Padding(4);
            this.btnOff.Name = "btnOff";
            this.btnOff.Size = new System.Drawing.Size(49, 30);
            this.btnOff.TabIndex = 6;
            this.btnOff.Text = "OFF";
            this.btnOff.UseVisualStyleBackColor = true;
            // 
            // Calculator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(341, 207);
            this.Controls.Add(this.btnOff);
            this.Controls.Add(this.pnlClear);
            this.Controls.Add(this.pnlOperators);
            this.Controls.Add(this.pnlNumerics);
            this.Controls.Add(this.txtInputField);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Calculator";
            this.Text = "Calculator";
            this.pnlNumerics.ResumeLayout(false);
            this.pnlOperators.ResumeLayout(false);
            this.pnlClear.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtInputField;
        private System.Windows.Forms.Panel pnlNumerics;
        private System.Windows.Forms.Button btn00;
        private System.Windows.Forms.Button btn0;
        private System.Windows.Forms.Button btn9;
        private System.Windows.Forms.Button btn8;
        private System.Windows.Forms.Button btn7;
        private System.Windows.Forms.Button btn6;
        private System.Windows.Forms.Button btn3;
        private System.Windows.Forms.Button btn4;
        private System.Windows.Forms.Button btn5;
        private System.Windows.Forms.Button btn2;
        private System.Windows.Forms.Button btn1;
        private System.Windows.Forms.Panel pnlOperators;
        private System.Windows.Forms.Button btnEqual;
        private System.Windows.Forms.Button btnDivide;
        private System.Windows.Forms.Button btnMultiple;
        private System.Windows.Forms.Button buttonMinus;
        private System.Windows.Forms.Button buttonPlus;
        private System.Windows.Forms.Panel pnlClear;
        private System.Windows.Forms.Button btnPoint;
        private System.Windows.Forms.Button btnClearAll;
        private System.Windows.Forms.Button bntClear;
        private System.Windows.Forms.Button btnOff;
    }
}

