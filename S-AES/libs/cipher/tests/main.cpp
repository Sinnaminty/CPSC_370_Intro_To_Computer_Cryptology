#include <cipher/SAES.h>
#include <cipher/U.h>

#include <iostream>

int main ( const int argc, const char *argv[] ) {
    std::cout << "Running tests...\n";
    const U::Matrix a ( "0738" );
    const U::Matrix b = SAES::applyCipher ( U::Matrix ( "6F6B" ),
                                            U::Matrix ( "A738" ),
                                            U::Op::ENCRYPT );
    return a == b ? 1 : 0;
}
