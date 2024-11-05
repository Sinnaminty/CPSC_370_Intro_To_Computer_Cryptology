#include <cipher/DCA.h>
#include <cipher/SAES.h>
#include <cipher/U.h>

#include <cstring>
#include <iostream>
void printHelp ( ) {
    std::cout << "-----------------------------------------------------\n";
    std::cout << "S-AES IMPLEMENTATION\n";
    std::cout << "By: Aiden Rivera\n";
    std::cout << "-----------------------------------------------------\n";
    std::cout << "USAGE: \n";
    std::cout << "First arg is our input matrix, in bits or hex\n";
    std::cout << "Second arg is our key matrix, in bits or hex\n";
    std::cout << "Third arg is our operation, either E for encrypt or D for "
                 "decrypt\n";
}
int main ( const int argc, const char *argv[] ) {
    if ( argc < 4 ) {
        printHelp ( );
        return 1;
    }
    const U::Matrix i ( argv[ 1 ] );
    const U::Matrix k ( argv[ 2 ] );
    U::Op op;
    if ( std::strcmp ( argv[ 3 ], "E" ) ) {
        op = U::Op::ENCRYPT;
    } else if ( std::strcmp ( argv[ 3 ], "D" ) ) {
        op = U::Op::DECRYPT;
    } else {
        std::cerr << argv[ 3 ] << " Not Valid operation!\n";
        return 1;
    }
    std::cout << SAES::applyCipher ( i, k, op ).toString ( ) << "\n";
    return 0;
}
