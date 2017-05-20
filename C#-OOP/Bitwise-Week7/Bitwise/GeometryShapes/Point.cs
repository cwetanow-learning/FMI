using System;

namespace GeometryShapes
{
    public class Point
    {
        private int[] coords;

        public Point() : this(new int[2])
        {

        }

        public Point(int[] coords)
        {
            this.Coordinates = coords;
        }

        public Point(Point point) : this(point.coords)
        {

        }

        public int[] Coordinates
        {
            get
            {
                return this.coords;
            }
            set
            {
                if (value == null || value.Length != 2)
                {
                    throw new ArgumentException();
                }

                this.coords = value;
            }
        }

        public override string ToString()
        {
            return string.Format($"x:{this.coords[0]},y:{this.coords[1]}");
        }
    }
}
