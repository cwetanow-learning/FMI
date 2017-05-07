using System.Threading;

namespace DiagramStuff.Utils
{
    public static class DataGenerator
    {
        private static int nextId;

        static DataGenerator()
        {
            nextId = 0;
        }

        public static int GenerateId()
        {
            return Interlocked.Increment(ref nextId);
        }
    }
}
