#include <stdlib.h>

#include <cstddef>
#include <iostream>
#include <map>
#include <string>

void printHelp ( ) {
    std::cout << "\n-------------------------\n";
    std::cout << "S-DES Implementation\n";
    std::cout << "By Aiden Rivera\n";
    std::cout << "-------------------------\n";
    std::cout << "USAGE:\n";
    std::cout << "./SimpleDES (1=Encrypt/0=Decrypt) (text) (key)\n";
}

std::string logicalXor ( const std::string &a, const std::string &b ) {
    std::string result;
    for ( size_t i = 0; i < a.length ( ); i++ ) {
        ( a[ i ] == b[ i ] ) ? result += "0" : result += "1";
    }
    return result;
}

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

std::string sTable ( const std::string &s ) {
    return s1Table ( s.substr ( 0, 4 ) ) + s2Table ( s.substr ( 3, 4 ) );
}
std::string expand ( const std::string &x ) {
    return x.substr ( 0, 1 ) + x.substr ( 1, 1 ) + x.substr ( 3, 1 )
           + x.substr ( 2, 1 ) + x.substr ( 3, 1 ) + x.substr ( 2, 1 )
           + x.substr ( 4, 1 ) + x.substr ( 5, 1 );
}

std::string func ( const std::string &r, const std::string &k ) {
    return sTable ( logicalXor ( expand ( r ), k ) );
}

std::string encrypt ( const std::string &text, const std::string &key ) {
    std::string l = text.substr ( 0, 6 );
    std::string r = text.substr ( 5, 6 );
    std::string rnew = logicalXor ( l, func ( r, key ) );
    return r + rnew;
}

std::string decrypt ( const std::string &text, const std::string &key ) {
    std::string l = text.substr ( 0, 6 );
    std::string r = text.substr ( 5, 6 );
    std::string lold = logicalXor ( r, func ( l, key ) );
    return lold + l;
}

void printResult ( const bool &direction,
                   const std::string &text,
                   const std::string &key ) {
    std::string result;
    direction ? result = "P = " + text + "\nK = " + key.substr ( 0, 8 )
                         + "\nC = " + encrypt ( text, key.substr ( 0, 8 ) )
              : result = "C = " + text + "\nK = " + key.substr ( 1, 8 )
                         + "\nP = " + decrypt ( text, key.substr ( 1, 8 ) );
    std::cout << result << "\n";
}

int main ( int argc, const char *argv[] ) {
    if ( argc != 4 ) {
        printHelp ( );
        return 1;
    }

    const bool direction = std::atoi ( argv[ 1 ] );
    const std::string text = argv[ 2 ];
    const std::string key = argv[ 3 ];
    printResult ( direction, text, key );
    return 0;
}
