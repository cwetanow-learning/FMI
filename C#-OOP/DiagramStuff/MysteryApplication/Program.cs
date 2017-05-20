using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MysteryApplication
{
    class Program
    {
        public static void Main(string[] args)
        {
            int count = 1;

            while (count <= 10)
            {
                Console.WriteLine(count % 2 == 1 ? "****" : "++++++++");
                count++;
            }
        }
    }
}
