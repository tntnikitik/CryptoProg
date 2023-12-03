#pragma once
#include <string>

class FileHashCalculator
{
public:
    static std::string calculateFileHash(const std::string& filename);
};
