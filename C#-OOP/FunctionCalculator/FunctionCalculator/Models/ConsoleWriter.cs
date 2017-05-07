using System;
using FunctionCalculator.Contracts;

namespace FunctionCalculator.Models
{
    public class ConsoleWriter : IWriter
    {
        public void WriteLine(string message)
        {
            Console.WriteLine(message);
        }
    }
}
