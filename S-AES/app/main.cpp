#include <cipher/DCA.h>
#include <cipher/SAES.h>
#include <cipher/U.h>

#include <iostream>

int main ( const int argc, const char *argv[] ) {
    using namespace U;
    using namespace SAES;

    Matrix base = 0x6F6B;
    Matrix difference = 0x6F9B;
    int numPairs = 100;

    auto pairs = DCA::generatePlaintextPairs ( base, difference, numPairs );
    Matrix targetDiff = 0x00F0;  // This would be determined experimentally
    Matrix keyGuess = DCA::differentialAttack ( pairs, targetDiff );

    if ( ! ( keyGuess == Matrix ( 0xFFFF ) ) ) {
        std::cout << "Key candidate found: " << keyGuess.toString ( ) << "\n";
    } else {
        std::cout << "No valid key found." << "\n";
    }

    return 0;
    return 0;
}
