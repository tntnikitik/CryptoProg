#include "fhash.h"
#include <iostream>

int main()
{
    std::string filename = "sus.txt";

    std::string hashValue = FileHashCalculator::calculateFileHash(filename);
    if (!hashValue.empty()) {
        std::cout << "Хэш-значение файла " << filename << ": " << hashValue << std::endl;
    }

    return 0;
}
