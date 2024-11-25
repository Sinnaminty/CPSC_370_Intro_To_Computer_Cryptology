#include <cipher/SDES.h>
#include <cipher/U.h>

#include <iostream>
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
}
int main ( const int argc, const char *argv[] ) {
    printPartOne ( );
    printPartTwo ( );
    return 0;
}
