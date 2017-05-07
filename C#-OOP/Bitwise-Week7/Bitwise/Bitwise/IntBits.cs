using System;

namespace Bitwise
{
    public class IntBits
    {
        private bool[] bits;

        public IntBits(int value)
        {
            this.bits = GetBinaryRepresentation(value);
        }

        public bool this[int index]
        {
            get { return this.bits[index]; }
            set { this.bits[index] = value; }
        }

        private static bool[] GetBinaryRepresentation(int value)
        {
            var stringBits = Convert.ToString(value, 2).PadLeft(32, '0');

            var array = new bool[32];

            for (var i = 0; i < stringBits.Length; i++)
            {
                if (stringBits[i]=='1')
                {
                    array[i] = true;
                }
            }

            return array;
        }
    }
}
