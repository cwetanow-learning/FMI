using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _02.TranspositionCipher
{
    public class TranspositionCipher
    {
        private int encryptionLength;

        public TranspositionCipher(string key)
        {
            this.Key = key;
            this.encryptionLength = this.Key.Length;
        }

        public string Key { get; private set; }

        public string Encrypt(string text)
        {
            var width = this.encryptionLength;
            var height = text.Length / width;

            var array = new char[height, width];

            var counter = 0;

            for (var i = 0; i < height; i++)
            {
                for (var j = 0; j < width; j++)
                {
                    array[i, j] = text[counter];
                    counter++;
                }
            }

            var result = new StringBuilder();

            for (var i = 0; i < width; i++)
            {
                for (var j = 0; j < height; j++)
                {
                    result.Append(array[j, i]);
                }
            }

            return result.ToString();
        }

        public string Decrypt(string text)
        {
            var rowsCount = text.Length / this.encryptionLength;

            var result = new StringBuilder();

            for (var i = 0; i < rowsCount; i++)
            {
                for (var j = i; j < text.Length; j += 3)
                {
                    result.Append(text[j]);
                }
            }

            return result.ToString();
        }
    }
}
