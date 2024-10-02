#include <ciphers/Affine.h>
#include <ciphers/Shift.h>
#include <ciphers/Transposition.h>
#include <ciphers/Utility.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#include "ciphers/Hill.h"

void printAffine ( ) {
    /*
     * QUESTION 1
     */
    std::cout << "1.) Encrypt the plain text message 'cleopatra' using the "
                 "affine function 7x + 8.\n";
    std::cout << Utility::toString (
        Affine::applyCipher ( Utility::toNumVector ( "cleopatra" ),
                              Affine::AffineFunction ( 7, 8 ),
                              Utility::OpType::ENCRYPT ) )
              << "\n\n";

    /*
     * QUESTION 2
     */

    std::cout << "2.) The ciphertext 'MZDVEZC' was encrypted using the affine "
                 "function 5x + 12. Decrypt it.\n";
    std::cout << Utility::toString (
        Affine::applyCipher ( Utility::toNumVector ( "MZDVEZC" ),
                              Affine::AffineFunction ( 5, 12 ),
                              Utility::OpType::DECRYPT ) )
              << "\n\n";

    /*
     * QUESTION 3
     */

    std::cout << "3.) The following ciphertext was encrypted by an affine "
                 "cipher using the function 3x + b for some "
                 "b:\nTCABTIQMFHEQQMRMVMTMAQ\nDecrypt it.\n";
    auto cipherVectors = Affine::bruteForceCipher (
        Utility::toNumVector ( "TCABTIQMFHEQQMRMVMTMAQ" ),
        Affine::AffineFunction ( 3, 0 ) );
    std::for_each ( cipherVectors.begin ( ),
                    cipherVectors.end ( ),
                    [ index = 0 ] ( const Utility::CipherVector &vec ) mutable {
                        std::cout << "b = " << index++ << ": "
                                  << Utility::toString ( vec ) << "\n";
                    } );
    std::cout << "\n";

    /*
     * QUESTION 4
     */

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
    /*
     * QUESTION 1
     */

    std::cout << "1.) The following ciphertext was the output of a shift "
                 "cipher:\nLCLLEWLJAZLNNZMVYIYLHRMHZA\n";
    std::cout << "By performing a frequency count, guess the key used in the "
                 "cipher.\n";
    std::cout << "Use the computer to test your hypothesis. What is the "
                 "decrypted plaintext?\n";

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

    /*
     * QUESTION 2
     */

    std::cout
        << "2.) The following was encrypted using by row transposition method. "
           "Implement functions to perform encryption/decryption.\n";
    std::cout
        << "\ta.) Encrypt the plaintext 'attack postponed until two am' using "
           "double transposition with the key (4, 3, 1, 2, 5, 6, 7)\n";

    std::cout << Utility::toString ( Transposition::applyCipher (
        Utility::toNumVector ( "attackpostponeduntiltwoam" ),
        std::vector< int16_t > { 4, 3, 1, 2, 5, 6, 7 },
        Utility::OpType::ENCRYPT ) )
              << "\n";

    std::cout << "b.) Decrypt the ciphertext 'AMRT MOEP EAEG RTFY TZTY XAWE'"
                 "using double transposition with the key (3, 5, 1, 6, 2, "
                 "4)\n";

    std::cout << Utility::toString ( Transposition::applyCipher (
        Utility::toNumVector ( "AMRTMOEPEAEGRTFYTZTYXAWE" ),
        std::vector< int16_t > { 3, 5, 1, 6, 2, 4 },
        Utility::OpType::DECRYPT ) )
              << "\n";
}

void printHill ( ) {
    /*
     * QUESTION 1
     */
    std::cout
        << "Implement functions to perform encryption/decryption with 2x2 Hill "
           "Cipher. The key should be an invertible matrix over the integers "
           "mod 26.\n";

    std::cout << "\ta.) Encrypt 'Meet me at the usual place at ten rather than "
                 "eight oclock' with K = {{9,4},{5,7}}\n";
    std::cout << Utility::toString ( Hill::applyCipher (
        Utility::toNumVector (
            "meetmeattheusualplaceattenratherthaneightoclock" ),
        Utility::Matrix (
            std::vector< std::vector< int16_t > > { { 9, 4 }, { 5, 7 } } ),
        Utility::OpType::ENCRYPT ) )
              << "\n";

    std::cout << "\tb.) Decrypt 'YIFZMA' with K = {{9,13},{2,3}}\n";
    std::cout << Utility::toString ( Hill::applyCipher (
        Utility::toNumVector ( "YIFZMA" ),
        Utility::Matrix (
            std::vector< std::vector< int16_t > > { { 9, 13 }, { 2, 3 } } ),
        Utility::OpType::DECRYPT ) )
              << "\n";

    /*
     * QUESTION 2
     */
    std::cout << "Implement a known plaintext attack on the hill cipher. "
                 "Plaintext = 'how are you today' and ciphertext = "
                 "'ZWESENIUSPLJVEU'. Deduce the key matrix with dimension 2.\n";
}

int main ( ) {
    std::cout
        << "--------------------------------------------------------------\n";
    std::cout << "AFFINE\n";
    printAffine ( );

    std::cout
        << "--------------------------------------------------------------\n";
    std::cout << "TRANSPOSITION\n";
    printTransposition ( );

    std::cout
        << "--------------------------------------------------------------\n";
    std::cout << "HILL\n";
    printHill ( );

    return 0;
}
