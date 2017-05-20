namespace GeometryShapes
{
    public class Parallelepiped : Rectangle
    {
        public Parallelepiped(Rectangle rectangle, int height) : base(rectangle.Coordinates, rectangle.Point)
        {
            this.Height = height;
        }

        public int Height { get; set; }

        public override string ToString()
        {
            return base.ToString() + "; Height: " + this.Height;
        }

        public override double Area()
        {
            // Dont know how to calculate it
            return base.Area();
        }
    }
}
