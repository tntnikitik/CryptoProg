#include "fcrypt.h"
#include <fstream>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/sha.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/files.h>

using namespace CryptoPP;

void FileEncryptor::EncryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& password)
{
    AutoSeededRandomPool prng;

    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    PKCS5_PBKDF2_HMAC<SHA256> pbkdf;
    pbkdf.DeriveKey(key, key.size(), 0, (byte*)password.data(), password.size(), (byte*)"", 0, 1000);

    byte iv[AES::BLOCKSIZE];
    prng.GenerateBlock(iv, sizeof(iv));

    CBC_Mode<AES>::Encryption encryptor;
    encryptor.SetKeyWithIV(key, key.size(), iv);

    std::ifstream inStream(inputFile, std::ios::binary);
    std::ofstream outStream(outputFile, std::ios::binary);
    outStream.write(reinterpret_cast<char*>(iv), AES::BLOCKSIZE);
    FileSource(inStream, true, new StreamTransformationFilter(encryptor, new FileSink(outStream)));
}

void FileEncryptor::DecryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& password)
{
    std::ifstream inStream(inputFile, std::ios::binary);
    std::ofstream outStream(outputFile, std::ios::binary);

    byte iv[AES::BLOCKSIZE];
    inStream.read(reinterpret_cast<char*>(iv), AES::BLOCKSIZE);

    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    PKCS5_PBKDF2_HMAC<SHA256> pbkdf;
    pbkdf.DeriveKey(key, key.size(), 0, (byte*)password.data(), password.size(), (byte*)"", 0, 1000);

    CBC_Mode<AES>::Decryption decryptor;
    decryptor.SetKeyWithIV(key, key.size(), iv);

    FileSource(inStream, true, new StreamTransformationFilter(decryptor, new FileSink(outStream)));
}
