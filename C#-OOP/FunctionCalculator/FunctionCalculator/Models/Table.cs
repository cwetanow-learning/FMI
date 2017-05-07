using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using FunctionCalculator.Contracts;

namespace FunctionCalculator.Models
{
    public class Table : ITableMaker
    {
        private const int FunctionValuesCount = 20;

        private IFunctionCalculator calculator;

        public Table(IFunctionCalculator calculator)
        {
            this.calculator = calculator;
        }

        public IList<string> MakeTable(double start, double end, double steps)
        {
            var result = new List<string>();

            var step = (end - start) / steps;
            var current = start;

            for (int i = 0; i < steps; i++)
            {
                var row = this.CalculateRow(current, i);
                result.Add(row);

                current += step;
            }

            return result;
        }

        private string CalculateRow(double x, int count)
        {
            var funcValue = calculator.CalculateFunction(x);
            var result = $"x{count}={x:F2}\tf(x{count})={funcValue:F4}";
            return result;
        }
    }
}
