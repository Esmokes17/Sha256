#include <iostream>

#include "hash.h"

int main() {
    std::string input;
    std::cout << "input: ";
    char ch;
    //! input Cntrl-z and enter for end of string
    while ((ch = std::cin.get()) && !std::cin.eof()) {
        input += ch;
    }

    std::cout << input << std::endl;
    Sha256 * sh = new Sha256(input);
    std::cout << "\nresult: " << sh->encode()->getResult() << std::endl;
    return 0;
}