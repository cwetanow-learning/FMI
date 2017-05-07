namespace DiagramStuff.Models
{
    public class Time
    {
        private int hour;
        private int minute;
        private int second;

        public Time()
        {

        }

        public Time(int hour, int minute, int second)
        {
            this.Hour = hour;
            this.Minute = minute;
            this.Second = second;
        }

        public int Hour
        {
            get
            {
                return this.hour;
            }
            set
            {
                this.hour = value;
            }
        }

        public int Minute
        {
            get
            {
                return this.minute;
            }
            set
            {
                this.minute = value;
            }
        }

        public int Second
        {
            get
            {
                return this.second;
            }
            set
            {
                this.second = value;
            }
        }
    }
}
