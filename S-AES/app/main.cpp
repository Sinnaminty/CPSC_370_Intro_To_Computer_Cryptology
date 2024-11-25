#include <cipher/SAES.h>
#include <cipher/U.h>
#include <getopt.h>  // For getopt_long

#include <iostream>
#include <string>

void printHelp ( ) {
    std::cout << "-----------------------------------------------------\n";
    std::cout << "S-AES IMPLEMENTATION\n";
    std::cout << "By: Aiden Rivera\n";
    std::cout << "-----------------------------------------------------\n";
    std::cout << "USAGE:\n";
    std::cout << "./app -p <plaintext> -c <ciphertext> -k <key matrix> "
                 "--<encrypt/decrypt> --bruteForce\n";
    std::cout << "\nOPTIONS:\n";
    std::cout
        << "  -p, --plaintext <value>       Specify plaintext input matrix\n";
    std::cout
        << "  -c, --ciphertext <value>      Specify ciphertext input matrix\n";
    std::cout << "  -k, --key <value>             Specify key matrix\n";
    std::cout << "  --encrypt                    Perform encryption (requires "
                 "-p and -k)\n";
    std::cout << "  --decrypt                    Perform decryption (requires "
                 "-c and -k)\n";
    std::cout << "  --bruteForce                 Perform brute force (requires "
                 "any two of -p, -c, -k)\n";
}

int main ( const int argc, char *argv[] ) {
    std::string plaintext, ciphertext, key;
    bool encrypt = false, decrypt = false, bruteForce = false;

    static struct option long_options[] = {
        { "plaintext", required_argument, 0, 'p' },
        { "ciphertext", required_argument, 0, 'c' },
        { "key", required_argument, 0, 'k' },
        { "encrypt", no_argument, 0, 0 },
        { "decrypt", no_argument, 0, 0 },
        { "bruteForce", no_argument, 0, 0 },
        { 0, 0, 0, 0 }  // End of options
    };

    int option_index = 0;
    int opt;
    while (
        ( opt
          = getopt_long ( argc, argv, "p:c:k:", long_options, &option_index ) )
        != -1 ) {
        switch ( opt ) {
            case 'p': plaintext = optarg; break;
            case 'c': ciphertext = optarg; break;
            case 'k': key = optarg; break;
            case 0:  // Long options
                if ( std::string ( long_options[ option_index ].name )
                     == "encrypt" ) {
                    encrypt = true;
                } else if ( std::string ( long_options[ option_index ].name )
                            == "decrypt" ) {
                    decrypt = true;
                } else if ( std::string ( long_options[ option_index ].name )
                            == "bruteForce" ) {
                    bruteForce = true;
                }
                break;
            default: printHelp ( ); return 1;
        }
    }

    // Validate arguments
    if ( encrypt + decrypt + bruteForce != 1 ) {
        std::cerr << "Error: Specify exactly one operation: --encrypt, "
                     "--decrypt, or --bruteForce.\n";
        printHelp ( );
        return 1;
    }

    if ( encrypt ) {
        if ( plaintext.empty ( ) || key.empty ( ) ) {
            std::cerr
                << "Error: --encrypt requires -p (plaintext) and -k (key).\n";
            return 1;
        }
        if ( plaintext.size ( ) != 4 || key.size ( ) != 4 ) {
            std::cerr
                << "Error: -p (plaintext) and -k (key) must be of size 4.\n";
            return 1;
        }
        U::Matrix input ( plaintext );
        U::Matrix keyMatrix ( key );
        std::cout << "Encrypted output: "
                  << SAES::applyCipher ( input, keyMatrix, U::Op::ENCRYPT )
                         .toString ( )
                  << "\n";
    } else if ( decrypt ) {
        if ( ciphertext.empty ( ) || key.empty ( ) ) {
            std::cerr
                << "Error: --decrypt requires -c (ciphertext) and -k (key).\n";
            return 1;
        }
        if ( ciphertext.size ( ) != 4 || key.size ( ) != 4 ) {
            std::cerr
                << "Error: -c (ciphertext) and -k (key) must be of size 4.\n";
            return 1;
        }
        U::Matrix input ( ciphertext );
        U::Matrix keyMatrix ( key );
        std::cout << "Decrypted output: "
                  << SAES::applyCipher ( input, keyMatrix, U::Op::DECRYPT )
                         .toString ( )
                  << "\n";
    } else if ( bruteForce ) {
        int count
            = ! plaintext.empty ( ) + ! ciphertext.empty ( ) + ! key.empty ( );
        if ( count < 2 ) {
            std::cerr << "Error: --bruteForce requires any two of -p "
                         "(plaintext), -c (ciphertext), or -k (key).\n";
            return 1;
        }
        // Implement brute force logic here
        std::cout << "Brute force operation not yet implemented.\n";
    }

    return 0;
}
