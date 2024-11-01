#include <cipher/SAES.h>
#include <cipher/U.h>

#include <iostream>

int main ( ) {
    using namespace U;
    std::cout << "P = 6F6B" << "\n";
    std::cout << "K = A73B" << "\n";
    std::cout << "Answer should be: 0738" << "\n";

    const Matrix a = SAES::applyCipher ( U::Matrix ( "6F6B" ),
                                         U::Matrix ( "A73B" ),
                                         U::Op::ENCRYPT );
    std::cout << "Answer: " << a.toString ( ) << "\n";

    std::cout << "C = 0738" << "\n";
    std::cout << "K = A73B" << "\n";
    std::cout << "Answer should be: 6F6B" << "\n";

    const Matrix b = SAES::applyCipher ( U::Matrix ( "0738" ),
                                         U::Matrix ( "A73B" ),
                                         U::Op::DECRYPT );
    std::cout << "Answer: " << b.toString ( ) << "\n";
    return 0;
}
