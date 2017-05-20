using System;
using System.Text;

namespace _03.Barcodes
{
    public class Startup
    {
        public static void Main(string[] args)
        {
            string[] Codes =
            {
                "||:::",
                ":::||",
                "::|:|",
                "::||:",
                ":|::|",
                ":|:|:",
                ":||::",
                "|::::",
                "|::|:",
                "|:|::"
            };

            Console.WriteLine("Enter three number zip code");
            var code = Console.ReadLine().ToCharArray();

            var result = new StringBuilder();

            for (var i = 0; i < code.Length; i++)
            {
                var digit = int.Parse(code[i].ToString());
                result.Append(Codes[digit]);
            }

            Console.WriteLine(result.ToString());
        }
    }
}
