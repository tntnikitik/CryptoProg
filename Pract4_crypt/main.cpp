#include "fcrypt.h"
#include <iostream>

int main() {
    std::string inputFile, outputFile, password;
    char mode;

    std::cout << "Enter mode (E: Encrypt, D: Decrypt): ";
    std::cin >> mode;

    std::cout << "Enter input file name: ";
    std::cin >> inputFile;

    std::cout << "Enter output file name: ";
    std::cin >> outputFile;

    std::cout << "Enter password: ";
    std::cin >> password;

    if (mode == 'E' || mode == 'e') {
        FileEncryptor::EncryptFile(inputFile, outputFile, password);
        std::cout << "Encryption complete.\n";
    } else if (mode == 'D' || mode == 'd') {
        FileEncryptor::DecryptFile(inputFile, outputFile, password);
        std::cout << "Decryption complete.\n";
    } else {
        std::cerr << "Invalid mode. Please enter 'E' for encrypt or 'D' for decrypt.\n";
        return 1;
    }

    return 0;
}
