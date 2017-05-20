using System.Collections;

namespace Homework
{
    public class MyValue
    {
        private BitArray bits;

        public MyValue()
        {
        }

        public MyValue(int value)
        {
            this.Value = value;
            this.bits = new BitArray(new int[] { value });
        }

        public MyValue(MyValue value)
            : this(value.Value)
        {

        }

        public int Value { get; set; }

        public byte GetBit(byte position)
        {
            var bit = (this.Value & (1 << position - 1)) != 0;

            return bit ? (byte)1 : (byte)0;
        }

        public void SetBit(byte position, byte value)
        {
            this.bits[position] = value == 1;
        }
    }
}
