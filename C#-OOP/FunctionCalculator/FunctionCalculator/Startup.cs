using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using FunctionCalculator.Models;

namespace FunctionCalculator
{
    class Startup
    {
        static void Main(string[] args)
        {
            var mathsCalculator = new MathematicCalculator();

            var functionCalc = new Models.FunctionCalculator(mathsCalculator);

            var table = new Table(functionCalc);

            var writer = new ConsoleWriter();
            var reader = new ConsoleReader();

            var engine = new Engine(table, writer, reader);
            engine.Start();
        }
    }
}
