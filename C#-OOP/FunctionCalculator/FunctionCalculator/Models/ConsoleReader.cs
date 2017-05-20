using System;
using FunctionCalculator.Contracts;

namespace FunctionCalculator.Models
{
    public class ConsoleReader : IReader
    {
        public string ReadLine()
        {
            return Console.ReadLine();
        }
    }
}
