#include "fhash.h"
#include <iostream>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>

using namespace CryptoPP;

std::string FileHashCalculator::calculateFileHash(const std::string& filename)
{
    std::string result;

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return "";
    }
    SHA256 sha256;
    HashFilter hashFilter(sha256, new HexEncoder(new StringSink(result)));
    const int bufferSize = 4096;
    byte buffer[bufferSize];
    while (file.read(reinterpret_cast<char*>(buffer), bufferSize)) {
        hashFilter.Put(buffer, bufferSize);
    }
    size_t bytesRead = static_cast<size_t>(file.gcount());
    if (bytesRead > 0) {
        hashFilter.Put(buffer, bytesRead);
    }
    hashFilter.MessageEnd();
    return result;
}
