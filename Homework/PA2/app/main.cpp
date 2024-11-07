#include <cstring>
#include <iostream>
void printHelp ( ) {
    std::cout << "-----------------------------------------------------\n";
    std::cout << "PROGRAMMING ASSIGNMENT 2: S-DES & CBC\n";
    std::cout << "By: Aiden Rivera\n";
    std::cout << "-----------------------------------------------------\n";
    std::cout << "USAGE: \n";
    std::cout << "Working on it! \n";
}

int main ( const int argc, const char *argv[] ) {
    if ( argc < 2 ) {
        printHelp ( );
        return 1;
    }
    return 0;
}
