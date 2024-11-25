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
            std::cout << "C1 = " << c1 << "\n";
            std::cout << "C2 = " << c2 << "\n";
            std::cout << "C = " << c1 + c2 << "\n";

            // Pi = C_{i-1} ^ Dk(C_i)
        } else if ( op == Op::DECRYPT ) {
            std::string c1 = t.substr ( 0, 12 );
            std::string c2 = t.substr ( 12, 12 );
            std::string p1 = logicalXor ( SDES::decrypt ( c1, k ), i );
            std::string p2 = logicalXor ( SDES::decrypt ( c2, k ), c1 );
            std::cout << "p1 = " << p1 << "\n";
            std::cout << "p2 = " << p2 << "\n";
            std::cout << "p = " << p1 + p2 << "\n";
        }
    }

    void printCBC2 ( const std::string &p1,
                     const std::string &p2,
                     const std::string &k,
                     const std::string &i ) {
        const std::string pp1 = p1.substr ( 0, 12 );
        const std::string pp2 = p1.substr ( 12, 12 );
        const std::string pp3 = p1.substr ( 24, 12 );
        const std::string pp4 = p1.substr ( 36, 12 );

        const std::string cc1 = SDES::encrypt ( logicalXor ( pp1, i ), k );
        const std::string cc2 = SDES::encrypt ( logicalXor ( pp2, cc1 ), k );
        const std::string cc3 = SDES::encrypt ( logicalXor ( pp3, cc2 ), k );
        const std::string cc4 = SDES::encrypt ( logicalXor ( pp4, cc3 ), k );

        std::cout << "C1 = " << cc1 << "\n";
        std::cout << "C2 = " << cc2 << "\n";
        std::cout << "C3 = " << cc3 << "\n";
        std::cout << "C4 = " << cc4 << "\n";
        std::cout << "Ciphertext of p2 = " << cc1 << cc2 << cc3 << cc4
                  << "\n\n";

        const std::string ppp1 = p2.substr ( 0, 12 );
        const std::string ppp2 = p2.substr ( 12, 12 );
        const std::string ppp3 = p2.substr ( 24, 12 );
        const std::string ppp4 = p2.substr ( 36, 12 );

        const std::string ccc1 = SDES::encrypt ( logicalXor ( ppp1, i ), k );
        const std::string ccc2 = SDES::encrypt ( logicalXor ( ppp2, ccc1 ), k );
        const std::string ccc3 = SDES::encrypt ( logicalXor ( ppp3, ccc2 ), k );
        const std::string ccc4 = SDES::encrypt ( logicalXor ( ppp4, ccc3 ), k );

        std::cout << "C1 = " << ccc1 << "\n";
        std::cout << "C2 = " << ccc2 << "\n";
        std::cout << "C3 = " << ccc3 << "\n";
        std::cout << "C4 = " << ccc4 << "\n";
        std::cout << "Ciphertext of p3 = " << ccc1 << ccc2 << ccc3 << ccc4
                  << "\n\n";
    }
}  // namespace CBC
