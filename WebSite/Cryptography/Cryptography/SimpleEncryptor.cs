using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

public class SimpleEncryptor
{
    private static string defaultPassPhrase = "asVaZejsdkDEIFfdSsTddskmHdlEFJ";     // can be any string
    private static string saltValue = "s@1tsdmyValfjksuekasfhd";                // can be any string
    private static string hashAlgorithm = "SHA1";                           // can be "MD5"
    private static int passwordIterations = 2;                              // can be any number
    private static string initVector = "@1B2c3D4e5F6g7H8";                  // must be 16 bytes
    private static int keySize = 256;                                       // can be 192 or 128

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