#include <cstring>
#include <iostream>

int main ( const int argc, const char *argv[] ) {
    if ( strcmp ( argv[ 1 ], "pass" ) == 0 ) {
        std::cout << "We passed the test!\n";
        return 0;
    } else if ( strcmp ( argv[ 1 ], "fail" ) == 0 ) {
        std::cerr << "We failed the test!\n";
        return 1;
    } else {
        return 1;
    }
}
