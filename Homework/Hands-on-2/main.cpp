#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

char shiftCharacter ( const char &c, const int &key, const bool &encrypt ) {
    if ( ! std::isalpha ( c ) ) return c;

    const char base = std::islower ( c ) ? 'a' : 'A';
    return encrypt ? static_cast< char > (
                         toupper ( base + ( c - base + key + 26 ) % 26 ) )
                   : static_cast< char > (
                         tolower ( base + ( c - base - key + 26 ) % 26 ) );
}

std::string shiftCipher ( const std::string &text,
                          const int &key,
                          const bool &encrypt ) {
    return std::accumulate (
        text.begin ( ),
        text.end ( ),
        std::string { },
        [ key, encrypt ] ( const std::string &acc, char c ) {
            return acc + shiftCharacter ( c, key, encrypt );
        } );
}

std::vector< std::string > shiftCipherBruteForce (
    const std::string &cipherText ) {
    return std::views::iota ( 1, 26 )
           | std::ranges::views::transform ( [ &cipherText ] ( int key ) {
                 return shiftCipher ( cipherText, key, false );
             } )
           | std::ranges::to< std::vector< std::string > > ( );
}

void displayBruteForceResults ( const std::string &cipherText ) {
    const std::vector< std::string > results
        = shiftCipherBruteForce ( cipherText );
    std::ranges::for_each ( results,
                            [ i = 1 ] ( const std::string &result ) mutable {
                                std::cout << "Key " << i++ << ": " << result
                                          << "\n";
                            } );
}

int main ( ) {
    std::string plainText = "attack";
    int key = 10;

    std::string cipherText = shiftCipher ( plainText, key, true );
    std::cout << "1. Encryption of the plaintext: " << plainText << "\n";
    std::cout << "Key: " << key << "\n";
    std::cout << "Ciphertext: " << cipherText << "\n\n";

    plainText = shiftCipher ( cipherText, key, false );
    cipherText = "KDDKMU";
    std::cout << "2. Decryption of the ciphertext: " << cipherText << "\n";
    std::cout << "Key: " << key << "\n";
    std::cout << "Plaintext: " << plainText << "\n\n";

    cipherText = "YCVEJQWVHQTDTWVWU";
    std::cout << "3. Brute force decrypt with shift cipher" << "\n";
    std::cout << "Decryption of the ciphertext: " << cipherText << "\n";
    displayBruteForceResults ( cipherText );
}
