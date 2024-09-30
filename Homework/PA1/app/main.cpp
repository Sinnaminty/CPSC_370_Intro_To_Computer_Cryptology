#include <ciphers/Affine.h>
#include <ciphers/Utility.h>

#include <iostream>

void printAffine ( ) {
    std::cout << "1.) Encrypt the plain text message 'cleopatra' using the "
                 "affine function 7x + 8.\n";
    std::cout << Utility::toString ( Affine::applyCipher (
        Utility::CipherVector ( Utility::toNumVector ( "cleopatra" ),
                                Utility::OpType::ENCRYPT ),
        Affine::AffineFunction ( 7, 8 ) ) )
              << "\n\n";

    std::cout << "2.) The ciphertext 'MZDVEZC' was encrypted using the affine "
                 "function 5x + 12. Decrypt it.\n";
    std::cout << Utility::toString ( Affine::applyCipher (
        Utility::CipherVector ( Utility::toNumVector ( "MZDVEZC" ),
                                Utility::OpType::DECRYPT ),
        Affine::AffineFunction ( 5, 12 ) ) )
              << "\n\n";

    std::cout << "3.) The following ciphertext was encrypted by an affine "
                 "cipher using the function 3x + b for some "
                 "b:\nTCABTIQMFHEQQMRMVMTMAQ\nDecrypt it.\n";
    for ( const Utility::CipherVector &vec : Affine::bruteForceCipher (
              Utility::CipherVector (
                  Utility::toNumVector ( "TCABTIQMFHEQQMRMVMTMAQ" ),
                  Utility::OpType::DECRYPT ),
              Affine::AffineFunction ( 3, 0 ) ) ) {
        std::cout << Utility::toString ( vec ) << "\n";
    }
    std::cout << "\n";

    std::cout << "4.) The following cipher text was encrypted by an affine "
                 "cipher:\nEDSGICKXHUKLZVEQZVKXWKZUKCVUH\nThe first two "
                 "letters of the plaintext are 'if'. Find the key and then "
                 "decrypt the ciphertext.\n";
    std::cout << "K=(9,10)\n";
    std::cout << Utility::toString ( Affine::applyCipher (
        Utility::CipherVector (
            Utility::toNumVector ( "EDSGICKXHUKLZVEQZVKXWKZUKCVUH" ),
            Utility::OpType::DECRYPT ),
        Affine::AffineFunction ( 9, 10 ) ) )
              << "\n\n";
}

void printTransposition ( ) {
    std::cout
        << "1.) The following ciphertext was the output of a shift "
           "cipher:\nLCLLEWLJAZLNNZMVYIYLHRMHZA\nBy performing a frequency "
           "count, guess the key used in the cipher. Use the computer to test "
           "your hypothesis. What is the decrypted plaintext?\n";
    std::cout
        << "2.) The following was encrypted using by row transposition method. "
           "Implement functions to perform encryption/decryption.\n\ta.) "
           "Encrypt the plaintext 'attck postponed until two am' using "
           "double transposition with the key (4, 3, 1, 2, 5, 6, "
           "7)\n\tb.) Decrypt the ciphertext 'AMRT MOEP EAEG RTFY TZTY XAWE' "
           "using double transposition with the key (3, 5, 1, 6, 2, 4)\n";
}
void printVigenere ( ) {}
void printHill ( ) {}
int main ( int argc, const char *argv[] ) {
    printAffine ( );
    printTransposition ( );
    printVigenere ( );
    printHill ( );
    return 0;
}
