using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataModel.Tools
{

    public class SimpleEncryptor
    {
        private static string defaultPassPhrase = System.Configuration.ConfigurationSettings.AppSettings["defaultPassPhrase"];// can be any string
        private static string saltValue = System.Configuration.ConfigurationSettings.AppSettings["saltValue"];                // can be any string
        private static string hashAlgorithm = System.Configuration.ConfigurationSettings.AppSettings["hashAlgorithm"];        // can be "MD5"
        private static int passwordIterations = 2;                                                                            // can be any number
        private static string initVector = System.Configuration.ConfigurationSettings.AppSettings["initVector"];              // must be 16 bytes
        private static int keySize = 256;                                                                                     // can be 192 or 128

        public static string Encrypt(string plainText, string passPhrase)
        {
            if (passPhrase == String.Empty)
                passPhrase = defaultPassPhrase;

            return RijndaelEncryptor.Encrypt(plainText, passPhrase, saltValue, hashAlgorithm, passwordIterations, initVector, keySize);
        }

        public static string Decrypt(string cipherText, string passPhrase)
        {
            if (passPhrase == String.Empty)
                passPhrase = defaultPassPhrase;

            return RijndaelEncryptor.Decrypt(cipherText, passPhrase, saltValue, hashAlgorithm, passwordIterations, initVector, keySize);
        }
    }

}