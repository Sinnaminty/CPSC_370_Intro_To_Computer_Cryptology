#include <ciphers/Affine.h>
#include <ciphers/Shift.h>
#include <ciphers/Utility.h>

#include <iostream>

void printAffine ( ) {
    std::cout << "1.) Encrypt the plain text message 'cleopatra' using the "
                 "affine function 7x + 8.\n";
    std::cout << Utility::toString (
        Affine::applyCipher ( Utility::toNumVector ( "cleopatra" ),
                              Affine::AffineFunction ( 7, 8 ),
                              Utility::OpType::ENCRYPT ) )
              << "\n\n";

    std::cout << "2.) The ciphertext 'MZDVEZC' was encrypted using the affine "
                 "function 5x + 12. Decrypt it.\n";
    std::cout << Utility::toString (
        Affine::applyCipher ( Utility::toNumVector ( "MZDVEZC" ),
                              Affine::AffineFunction ( 5, 12 ),
                              Utility::OpType::DECRYPT ) )
              << "\n\n";

    std::cout << "3.) The following ciphertext was encrypted by an affine "
                 "cipher using the function 3x + b for some "
                 "b:\nTCABTIQMFHEQQMRMVMTMAQ\nDecrypt it.\n";
    for ( const Utility::CipherVector &vec : Affine::bruteForceCipher (
              Utility::toNumVector ( "TCABTIQMFHEQQMRMVMTMAQ" ),
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
        Utility::toNumVector ( "EDSGICKXHUKLZVEQZVKXWKZUKCVUH" ),
        Affine::AffineFunction ( 9, 10 ),
        Utility::OpType::DECRYPT ) )
              << "\n\n";
}

void printTransposition ( ) {
    std::cout
        << "1.) The following ciphertext was the output of a shift "
           "cipher:\nLCLLEWLJAZLNNZMVYIYLHRMHZA\nBy performing a frequency "
           "count, guess the key used in the cipher. Use the computer to test "
           "your hypothesis. What is the decrypted plaintext?\n";
    std::cout << "Frequency Count:\n";
    std::cout << Utility::toString ( Shift::applyFrequencyCount (
        Utility::toNumVector ( "LCLLEWLJAZLNNZMVYIYLHRMHZA" ) ) );

    std::cout << "The most common letter is L, so a shift from E to L "
                 "indicates the shift cipher key is 7.\n";

    std::cout << Utility::toString ( Shift::applyCipher (
        Utility::toNumVector ( "LCLLEWLJAZLNNZMVYIYLHRMHZA" ),
        7,
        Utility::OpType::DECRYPT ) )
              << "\n\n";

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
