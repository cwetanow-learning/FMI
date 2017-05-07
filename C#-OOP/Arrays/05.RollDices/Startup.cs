using System;

namespace _05.RollDices
{
    public class Startup
    {
        private static readonly Random dice = new Random();

        private const int RollCount = 36000;

        private const int TableSize = 6;

        public static void Main(string[] args)
        {
            var table = SeedTable();

            var averages = new double[TableSize, TableSize];

            for (var i = 0; i < TableSize; i++)
            {
                for (var j = 0; j < TableSize; j++)
                {
                    averages[i, j] = (double)table[i, j] / RollCount;

                    Console.WriteLine($"First dice: {i}, Second dice: {j}, Times: {table[i, j]}, Average times: {averages[i, j]:F5}");
                }
            }
        }

        public static int[,] SeedTable()
        {
            var table = new int[TableSize, TableSize];

            for (var i = 0; i < RollCount; i++)
            {
                var firstThrow = RollDice();
                var secondThrow = RollDice();

                table[firstThrow - 1, secondThrow - 1]++;
            }

            return table;
        }

        public static int RollDice()
        {
            return dice.Next(1, 7);
        }
    }
}
