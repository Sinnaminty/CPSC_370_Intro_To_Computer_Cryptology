#include <cipher/SDES.h>

#include <iostream>

void printPartOne ( ) {
    std::cout << "---------------------------------------\n";
    std::cout << "PART I: S-DES\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Item 1.) 1 Round Encryption and Decryption.\n\n";
    std::cout << "Encrypt:\n";
    SDES::printOneRound ( SDES::Op::ENCRYPT, "100010110101", "111000111" );

    std::cout << "Decrypt:\n";
    SDES::printOneRound ( SDES::Op::DECRYPT, "001010110101", "111000111" );
}
int main ( const int argc, const char *argv[] ) {
    printPartOne ( );
    return 0;
}
