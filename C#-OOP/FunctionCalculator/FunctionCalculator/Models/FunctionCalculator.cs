using FunctionCalculator.Contracts;

namespace FunctionCalculator.Models
{
    public class FunctionCalculator : IFunctionCalculator
    {
        private IMathematicCalculator calculator;

        public FunctionCalculator(IMathematicCalculator calculator)
        {
            this.calculator = calculator;
        }

        public double CalculateFunction(double x)
        {
            var numerator = calculator.Absolute(x - 2);
            numerator = calculator.Pow(numerator, 2);

            var denominator = calculator.Pow(x, 2) + 1;

            var result = numerator / denominator;
            return result;
        }
    }
}
