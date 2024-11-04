#include <cipher/SAES.h>
#include <cipher/U.h>

#include <cstring>
#include <iostream>

int main ( const int argc, const char *argv[] ) {
    if ( strcmp ( argv[ 1 ], "encrypt" ) == 0 ) {
        const U::Matrix a ( "0738" );
        const U::Matrix b = SAES::applyCipher ( U::Matrix ( "6F6B" ),
                                                U::Matrix ( "A73B" ),
                                                U::Op::ENCRYPT );
        if ( a == b ) {
            return 0;
        } else {
            std::cerr << "a != b. a: " << a.toString ( )
                      << " b: " << b.toString ( ) << "\n";
            return 1;
        }
    } else if ( strcmp ( argv[ 1 ], "decrypt" ) == 0 ) {
        const U::Matrix a ( "6F6B" );
        const U::Matrix b = SAES::applyCipher ( U::Matrix ( "0738" ),
                                                U::Matrix ( "A73B" ),
                                                U::Op::DECRYPT );
        if ( a == b ) {
            return 0;
        } else {
            std::cerr << "a != b. a: " << a.toString ( )
                      << " b: " << b.toString ( ) << "\n";
            return 1;
        }
    }
}
