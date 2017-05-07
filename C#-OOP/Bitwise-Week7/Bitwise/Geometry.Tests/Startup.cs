using System;
using GeometryShapes;

namespace Geometry.Tests
{
    public class Startup
    {
        public static void Main(string[] args)
        {
            var point1 = new Point();
            var point2 = new Point();

            var rectangle = new Rectangle(point1.Coordinates, point2);

            var cube = new Parallelepiped(rectangle, 12);

            Console.WriteLine(cube.Volume());
        }
    }
}
