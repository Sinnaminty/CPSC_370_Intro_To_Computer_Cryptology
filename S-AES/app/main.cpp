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

void debug ( ) {
    U::Matrix a = DCA::genRandomMatrix ( );
    U::Nyb diff = 0x0;
    U::Matrix b = DCA::createDifference ( a, diff );
    U::Matrix s1 = DCA::secretEncrypt ( a );
    U::Matrix s2 = DCA::secretEncrypt ( b );
    U::Matrix m = DCA::calcDifference ( s1, s2 );
    std::cout << "a: " << a.toString ( ) << "\n";
    std::cout << "b: " << b.toString ( ) << "\n";
    std::cout << "diff: " << diff.toString ( ) << "\n";
    std::cout << "m: " << m.toString ( ) << "\n";

    std::cout << "-----------------------------------------\n";

    diff = 0x1;
    b = DCA::createDifference ( a, diff );
    s1 = DCA::secretEncrypt ( a );
    s2 = DCA::secretEncrypt ( b );
    m = DCA::calcDifference ( s1, s2 );
    std::cout << "a: " << a.toString ( ) << "\n";
    std::cout << "b: " << b.toString ( ) << "\n";
    std::cout << "diff: " << diff.toString ( ) << "\n";
    std::cout << "m: " << m.toString ( ) << "\n";

    std::cout << "-----------------------------------------\n";

    diff = 0x2;
    b = DCA::createDifference ( a, diff );
    s1 = DCA::secretEncrypt ( a );
    s2 = DCA::secretEncrypt ( b );
    m = DCA::calcDifference ( s1, s2 );
    std::cout << "a: " << a.toString ( ) << "\n";
    std::cout << "b: " << b.toString ( ) << "\n";
    std::cout << "diff: " << diff.toString ( ) << "\n";
    std::cout << "m: " << m.toString ( ) << "\n";
    exit ( 1 );
}
int main ( const int argc, const char *argv[] ) {
    debug ( );
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
