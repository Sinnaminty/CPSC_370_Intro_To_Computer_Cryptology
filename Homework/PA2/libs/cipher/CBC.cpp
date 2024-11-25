#include "cipher/CBC.h"

#include <iostream>

#include "cipher/SDES.h"
#include "cipher/U.h"

using namespace U;

namespace CBC {
    void printCBC ( const std::string &t,
                    const std::string &k,
                    const std::string &i,
                    const U::Op &op ) {
        // Ci = Ek(Pi ^ C_{i-1})
        // C0 = IV
        if ( op == Op::ENCRYPT ) {
            std::string p1 = t.substr ( 0, 12 );
            std::string p2 = t.substr ( 12, 12 );
            std::string c1 = SDES::encrypt ( logicalXor ( p1, i ), k );
            std::string c2 = SDES::encrypt ( logicalXor ( p2, c1 ), k );
            std::cout << "C1: " << c1 << "\n";
            std::cout << "C2: " << c2 << "\n";
            std::cout << "C: " << c1 + c2 << "\n";
        } else if ( op == Op::DECRYPT ) {
        }
    }
}  // namespace CBC
