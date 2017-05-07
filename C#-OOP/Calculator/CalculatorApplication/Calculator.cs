using System;
using System.Windows.Forms;

namespace CalculatorApplication
{
    public partial class Calculator : Form
    {
        private int a;
        private int b;

        private char sign;

        public Calculator()
        {
            InitializeComponent();
        }

        private void button13_Click(object sender, EventArgs e)
        {
            b = int.Parse(txtInputField.Text);

            var result = Calculate();

            txtInputField.Text = result.ToString();
            a = 0;
            b = 0;
            this.sign = ' ';
        }

        private int Calculate()
        {
            switch (sign)
            {
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    return a / b;
                default:
                    return 0;
            }
        }

        private void buttonPlus_Click(object sender, EventArgs e)
        {
            a = (int.Parse(txtInputField.Text));
            sign = '+';
            txtInputField.Text = "0";
        }

        private void AddDigits(string digit)
        {
            if (txtInputField.Text != "0")
            {
                txtInputField.Text += digit;
            }
            else
            {
                txtInputField.Text = digit;
            }
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            AddDigits("1");
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            AddDigits("2");
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            AddDigits("3");
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            AddDigits("4");
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            AddDigits("5");
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            AddDigits("6");
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            AddDigits("7");
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            AddDigits("8");
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            AddDigits("9");
        }

        private void btn0_Click(object sender, EventArgs e)
        {
            AddDigits("0");
        }

        private void buttonMinus_Click(object sender, EventArgs e)
        {
            a = (int.Parse(txtInputField.Text));
            txtInputField.Text = "0";
            sign = '-';
        }

        private void btnMultiple_Click(object sender, EventArgs e)
        {
            a = (int.Parse(txtInputField.Text));
            txtInputField.Text = "0";
            sign = '*';
        }

        private void btnDivide_Click(object sender, EventArgs e)
        {
            a = (int.Parse(txtInputField.Text));
            txtInputField.Text = "0";
            sign = '/';
        }
    }
}
