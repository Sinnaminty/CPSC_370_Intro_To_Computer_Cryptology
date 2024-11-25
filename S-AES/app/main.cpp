#include <cipher/SAES.h>
#include <cipher/U.h>
#include <getopt.h>  // For getopt_long

#include <algorithm>
#include <iostream>
#include <string>

void printHelp ( ) {
    std::cout << "-----------------------------------------------------\n";
    std::cout << "S-AES IMPLEMENTATION\n";
    std::cout << "By: Aiden Rivera\n";
    std::cout << "-----------------------------------------------------\n";
    std::cout << "USAGE:\n";
    std::cout << "./app -p <plaintext> -c <ciphertext> -k <key matrix>\n";
    std::cout << "\nOPTIONS:\n";
    std::cout
        << "  -p, --plaintext <value>       Specify plaintext input matrix\n";
    std::cout
        << "  -c, --ciphertext <value>      Specify ciphertext input matrix\n";
    std::cout << "  -k, --key <value>             Specify key matrix\n";
}

int main ( const int argc, char *argv[] ) {
    std::string plaintext, ciphertext, key;
    static struct option long_options[] = {
        { "plaintext", required_argument, 0, 'p' },
        { "ciphertext", required_argument, 0, 'c' },
        { "key", required_argument, 0, 'k' },
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
            default: printHelp ( ); return 1;
        }
    }
    if ( argc < 3 ) {
        std::cerr << "Error: Not enough args. Specify at least 2 args: \n";
        printHelp ( );
        return 1;
    }
    // Validate arguments
    if ( ! plaintext.empty ( ) && ! ciphertext.empty ( ) && ! key.empty ( ) ) {
        std::cerr << "Error: Too many args. Specify no more than 2 args: \n";
        printHelp ( );
        return 1;
    }

    if ( ! plaintext.empty ( ) && ! key.empty ( ) ) {
        if ( plaintext.size ( ) != 4 || key.size ( ) != 4 ) {
            std::cerr
                << "Error: -p (plaintext) and -k (key) must be of size 4.\n";
            return 1;
        }
        U::Matrix p ( plaintext );
        U::Matrix k ( key );
        std::cout << "Encrypted output: "
                  << SAES::applyCipher ( p, k, U::Op::ENCRYPT ).toString ( )
                  << "\n";
    } else if ( ! ciphertext.empty ( ) && ! key.empty ( ) ) {
        if ( ciphertext.size ( ) != 4 || key.size ( ) != 4 ) {
            std::cerr
                << "Error: -c (ciphertext) and -k (key) must be of size 4.\n";
            return 1;
        }
        U::Matrix c ( ciphertext );
        U::Matrix k ( key );
        std::cout << "Decrypted output: "
                  << SAES::applyCipher ( c, k, U::Op::DECRYPT ).toString ( )
                  << "\n";
    } else if ( ! ciphertext.empty ( ) && ! plaintext.empty ( ) ) {
        if ( plaintext.size ( ) != 4 || ciphertext.size ( ) != 4 ) {
            std::cerr << "Error: -p (plaintext) and -c (ciphertext) must be of "
                         "size 4.\n";
            return 1;
        }
        U::Matrix p ( plaintext );
        U::Matrix c ( ciphertext );

        std::cout << "Possible Keys: " << "\n";
        auto vec = SAES::bruteForce ( p, c );
        std::for_each ( vec.begin ( ),
                        vec.end ( ),
                        [ index = 0 ] ( const U::Matrix &k ) mutable {
                            std::cout << "K" << index++ << ": "
                                      << k.toString ( ) << "\n";
                        } );
    }

    return 0;
}
