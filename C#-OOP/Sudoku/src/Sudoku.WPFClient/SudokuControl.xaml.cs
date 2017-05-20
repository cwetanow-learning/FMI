using System.Text.RegularExpressions;
using System.Windows.Controls;
using System.Windows.Input;

namespace Sudoku.Models
{
    /// <summary>
    /// Interaction logic for SudokuControl.xaml
    /// </summary>
    public partial class SudokuControl : UserControl
    {
        public SudokuControl()
        {
            InitializeComponent();
        }

        private void UIElement_OnPreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            e.Handled = new Regex("[^1-9.-]").IsMatch(e.Text);
        }
    }
}
