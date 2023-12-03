#pragma once
#include <string>

class FileEncryptor
{
public:
    static void EncryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& password);
    static void DecryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& password);
};
