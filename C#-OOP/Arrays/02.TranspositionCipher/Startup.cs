using System;

namespace _02.TranspositionCipher
{
    public class Startup
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Enter plain text");
            var text = Console.ReadLine();

            Console.WriteLine("Enter cipher");
            var key = Console.ReadLine();

            var encryptor = new TranspositionCipher(key);

            var encrypted = encryptor.Encrypt(text);
            Console.WriteLine($"This is the encrypted text: {encrypted}");

            var decrypted = encryptor.Decrypt(encrypted);
            Console.WriteLine($"This is the decrypted text: {decrypted}");
        }
    }
}
