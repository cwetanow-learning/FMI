using System;

namespace GeometryShapes
{
    public class Rectangle : Point
    {
        private Point point;

        public Rectangle() : this(new int[2], new Point())
        {
        }

        public Rectangle(int[] coords, Point lowerRight) : base(coords)
        {
            this.Point = lowerRight;
        }

        public Rectangle(Point point, Point lowerRightPoint) : base(point)
        {
            this.Point = lowerRightPoint;
        }

        public Point Point
        {
            get { return this.point; }
            set
            {
                if (value == null)
                {
                    throw new ArgumentNullException();
                }

                this.point = value;
            }
        }

        public override string ToString()
        {
            return string.Format($"Upper left: {base.ToString()}; Lower right: {this.point.ToString()}");
        }

        public virtual double Area()
        {
            // Dont know how to calculate it
            return 2;
        }
    }
}
