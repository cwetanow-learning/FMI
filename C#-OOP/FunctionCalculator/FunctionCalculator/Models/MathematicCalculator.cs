using System;
using FunctionCalculator.Contracts;

namespace FunctionCalculator.Models
{
    public class MathematicCalculator : IMathematicCalculator
    {
        public double Absolute(double number)
        {
            return Math.Abs(number);
        }

        public double Pow(double number, int power)
        {
            return Math.Pow(number, power);
        }
    }
}
