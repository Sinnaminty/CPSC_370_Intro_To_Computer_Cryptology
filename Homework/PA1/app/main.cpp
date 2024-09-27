#include <ciphers/Affine.h>
#include <ciphers/Utility.h>

#include <iostream>

void printAffine ( ) {
    std::cout << "1.) Encrypt the plain text message 'cleopatra' using the "
                 "affine function 7x + 8.\n";
    Utility::CipherVector vec ( Utility::toNumVector ( "cleopatra" ),
                                Utility::OpType::ENCRYPT );
    std::cout << Utility::toString ( Affine::applyCipher (
        Utility::CipherVector ( Utility::toNumVector ( "cleopatra" ),
                                Utility::OpType ( Utility::OpType::ENCRYPT ) ),
        Affine::AffineFunction ( 7, 8 ) ) )
              << "\n";

    std::cout << "2.) The ciphertext 'MZDVEZC' was encrypted using the affine "
                 "function 5x + 12. Decrypt it.\n";
    std::cout << Utility::toString ( Affine::applyCipher (
        Utility::CipherVector ( Utility::toNumVector ( "MZDVEZC" ),
                                Utility::OpType ( Utility::OpType::DECRYPT ) ),
        Affine::AffineFunction ( 5, 12 ) ) )
              << "\n";
}
void printTransposition ( ) {}
void printVigenere ( ) {}
void printHill ( ) {}
int main ( int argc, const char *argv[] ) {
    printAffine ( );
    printTransposition ( );
    printVigenere ( );
    printHill ( );
    return 0;
}
