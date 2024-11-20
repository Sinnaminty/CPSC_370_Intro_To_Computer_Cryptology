#include "cipher/SDES.h"

#include <iostream>
#include <map>

namespace SDES {

    // Logical XOR of two strings
    std::string logicalXor ( const std::string &a, const std::string &b ) {
        std::string result;
        for ( size_t i = 0; i < a.length ( ); i++ ) {
            ( a[ i ] == b[ i ] ) ? result += "0" : result += "1";
        }
        return result;
    }

    // S1 Table
    std::string s1Table ( const std::string &s1 ) {
        const std::map< std::string, std::string > s1map {
            { "0000", "101" }, { "0001", "010" }, { "0010", "001" },
            { "0011", "110" }, { "0100", "011" }, { "0101", "100" },
            { "0110", "111" }, { "0111", "000" }, { "1000", "001" },
            { "1001", "100" }, { "1010", "110" }, { "1011", "010" },
            { "1100", "000" }, { "1101", "111" }, { "1110", "101" },
            { "1111", "011" }
        };
        return s1map.find ( s1 )->second;
    }

    // S2 Table
    std::string s2Table ( const std::string &s2 ) {
        const std::map< std::string, std::string > s2map {
            { "0000", "100" }, { "0001", "000" }, { "0010", "110" },
            { "0011", "101" }, { "0100", "111" }, { "0101", "001" },
            { "0110", "011" }, { "0111", "010" }, { "1000", "101" },
            { "1001", "011" }, { "1010", "000" }, { "1011", "111" },
            { "1100", "110" }, { "1101", "010" }, { "1110", "001" },
            { "1111", "100" }
        };
        return s2map.find ( s2 )->second;
    }

    // Combine S1 and S2 tables
    std::string sTable ( const std::string &s ) {
        return s1Table ( s.substr ( 0, 4 ) ) + s2Table ( s.substr ( 4, 4 ) );
    }

    // Expands the input string
    std::string expand ( const std::string &x ) {
        return x.substr ( 0, 1 ) + x.substr ( 1, 1 ) + x.substr ( 3, 1 )
               + x.substr ( 2, 1 ) + x.substr ( 3, 1 ) + x.substr ( 2, 1 )
               + x.substr ( 4, 1 ) + x.substr ( 5, 1 );
    }

    // Function to apply S-DES operations
    std::string func ( const std::string &r, const std::string &k ) {
        return sTable ( logicalXor ( expand ( r ), k ) );
    }

    // Print the result of encryption or decryption
    void printOneRound ( const SDES::Op &op,
                         const std::string &text,
                         const std::string &key ) {
        std::string result;
        if ( op == SDES::Op::ENCRYPT ) {
            std::string l0 = text.substr ( 0, 6 );
            std::string r0 = text.substr ( 6, 6 );
            std::string k0 = key.substr ( 0, 8 );
            std::string l1 = r0;
            std::string r1 = logicalXor ( l0, func ( r0, k0 ) );

            std::cout << "P = " + text + "\n";
            std::cout << "K = " + key + "\n";
            std::cout << "\n";

            std::cout << "k0 = " + k0 + "\n";
            std::cout << "\n";

            std::cout << "l1 = " + l1 + "\n";
            std::cout << "r1 = " + r1 + "\n";
            std::cout << "\n";

            std::cout << "C = " + r1 + l1 + "\n";
            std::cout << "\n";

        } else if ( op == SDES::Op::DECRYPT ) {
            std::string l1 = text.substr ( 6, 6 );
            std::string r1 = text.substr ( 0, 6 );
            std::string k0 = key.substr ( 0, 8 );
            std::string r0 = l1;
            std::string l0 = logicalXor ( r1, func ( r0, k0 ) );

            std::cout << "C = " + text + "\n";
            std::cout << "K = " + key + "\n";
            std::cout << "\n";

            std::cout << "k0 = " + k0 + "\n";
            std::cout << "\n";

            std::cout << "l1 = " + l1 + "\n";
            std::cout << "r1 = " + r1 + "\n";
            std::cout << "\n";

            std::cout << "l0 = " + l0 + "\n";
            std::cout << "r0 = " + r0 + "\n";
            std::cout << "\n";

            std::cout << "P = " + l0 + r0 + "\n";
            std::cout << "\n";
        }
    }

    void printTwoRounds ( const SDES::Op &op,
                          const std::string &text,
                          const std::string &key ) {
        std::string result;
        if ( op == SDES::Op::ENCRYPT ) {
            std::string l0 = text.substr ( 0, 6 );
            std::string r0 = text.substr ( 6, 6 );
            std::string k0 = key.substr ( 0, 8 );

            std::string l1 = r0;
            std::string r1 = logicalXor ( l0, func ( r0, k0 ) );

            std::string k1 = key.substr ( 1, 8 );
            std::string l2 = r1;
            std::string r2 = logicalXor ( l1, func ( r1, k1 ) );

            std::cout << "P = " + text + "\n";
            std::cout << "K = " + key + "\n";
            std::cout << "\n";

            std::cout << "k0 = " + k0 + "\n";
            std::cout << "l1 = " + l1 + "\n";
            std::cout << "r1 = " + r1 + "\n";
            std::cout << "\n";

            std::cout << "k1 = " + k1 + "\n";
            std::cout << "l2 = " + l2 + "\n";
            std::cout << "r2 = " + r2 + "\n";
            std::cout << "\n";

            std::cout << "C = " + r2 + l2 + "\n";
            std::cout << "\n";

        } else if ( op == SDES::Op::DECRYPT ) {
            std::string l2 = text.substr ( 6, 6 );
            std::string r2 = text.substr ( 0, 6 );
            std::string k1 = key.substr ( 1, 8 );

            std::string r1 = l2;
            std::string l1 = logicalXor ( r2, func ( r1, k1 ) );

            std::string k0 = key.substr ( 0, 8 );
            std::string r0 = l1;
            std::string l0 = logicalXor ( r1, func ( r0, k0 ) );

            std::cout << "C = " + text + "\n";
            std::cout << "K = " + key + "\n";
            std::cout << "\n";

            std::cout << "k1 = " + k1 + "\n";
            std::cout << "l1 = " + l1 + "\n";
            std::cout << "r1 = " + r1 + "\n";
            std::cout << "\n";

            std::cout << "k0 = " + k0 + "\n";
            std::cout << "l0 = " + l0 + "\n";
            std::cout << "r0 = " + r0 + "\n";
            std::cout << "\n";

            std::cout << "P = " + l0 + r0 + "\n";
            std::cout << "\n";
        }
    }

}  // namespace SDES
