#include <cipher/SDES.h>
#include <cipher/U.h>

#include <iostream>

#include "cipher/CBC.h"
using namespace U;
void printPartOne ( ) {
    std::cout << "---------------------------------------\n";
    std::cout << "PART I: S-DES\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Item 1.) 1 Round Encryption and Decryption.\n\n";

    std::cout << "Encrypt:\n";
    SDES::printOneRound ( Op::ENCRYPT, "100010110101", "111000111" );
    std::cout << "Decrypt:\n";
    SDES::printOneRound ( Op::DECRYPT, "001010110101", "111000111" );
    std::cout << "Item 2.) 2 Rounds Encryption and Decryption.\n\n";

    std::cout << "Encrypt:\n";
    SDES::printTwoRounds ( Op::ENCRYPT, "011100100110", "111000111" );

    std::cout << "Decrypt:\n";
    SDES::printTwoRounds ( Op::DECRYPT, "001000000111", "111000111" );
}

void printPartTwo ( ) {
    std::cout << "---------------------------------------\n";
    std::cout << "PART 2: CBC MODE\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Item 3.) CBC Encrypt and Decrypt.\n\n";

    std::cout << "Encrypt:\n";
    const std::string p = "100010110101011100100110";
    const std::string k = "111000111";
    const std::string i = "111111111111";
    std::cout << "p = " << p << "\n";
    CBC::printCBC ( p, k, i, Op::ENCRYPT );

    std::cout << "Decrypt:\n";

    const std::string c = "100110000100100011000010";
    std::cout << "C = " << c << "\n";
    CBC::printCBC ( c, k, i, Op::DECRYPT );

    std::cout << "Item 4.) One bit difference.\n\n";

    const std::string p2 = "110011001100110011001100110011001100110011001100";
    const std::string p3 = "110011001100100011001100110011001100110011001100";
    std::cout << "p2 = " << p2 << "\n";
    std::cout << "p3 = " << p3 << "\n";

    CBC::printCBC2 ( p2, p3, k, i );
}

int main ( const int argc, const char *argv[] ) {
    printPartOne ( );
    printPartTwo ( );
    return 0;
}
