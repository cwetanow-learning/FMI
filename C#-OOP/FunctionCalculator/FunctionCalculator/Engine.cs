using System;
using FunctionCalculator.Contracts;

namespace FunctionCalculator
{
    public class Engine
    {
        private readonly ITableMaker table;
        private readonly IWriter writer;
        private readonly IReader reader;

        public Engine(ITableMaker table, IWriter writer, IReader reader)
        {
            this.table = table;
            this.writer = writer;
            this.reader = reader;
        }

        public void Start()
        {
            this.writer.WriteLine("Enter beggining");
            var beggining = double.Parse(this.reader.ReadLine());

            this.writer.WriteLine("Enter end");
            var end = double.Parse(this.reader.ReadLine());

            if (beggining > end)
            {
                var switcher = beggining;
                beggining = end;
                end = switcher;
            }

            this.writer.WriteLine("Enter steps");
            var steps = int.Parse(this.reader.ReadLine());

            var printedTable = this.table.MakeTable(beggining, end, steps);

            var start = 0;
            var finish = printedTable.Count;

            do
            {
                for (int i = start; i < start + 20; i++)
                {
                    try
                    {
                        this.writer.WriteLine(printedTable[i]);
                    }
                    catch (Exception)
                    {
                        this.writer.WriteLine("No more elements");
                        break;
                    }
                }

                start += 20;

                this.writer.WriteLine("Press return to continue …");
            } while (this.reader.ReadLine() == "Return");
        }
    }
}
