#include "cipher/SAES.h"

#include <iostream>

#include "cipher/U.h"

namespace SAES {
    using namespace U;

    void keyGenDebug ( ) {
        const Matrix k0 ( "A73B" );
        std::cout << "K0 = A73B" << "\n";

        const std::array< Word, 2 > RC { Word ( Nyb ( 0x8 ), Nyb ( 0x0 ) ),
                                         Word ( Nyb ( 0x3 ), Nyb ( 0x0 ) ) };
        const Word w0 = k0[ 0 ];
        std::cout << "w0 should be A7: " << w0.toString ( ) << "\n";
        const Word w1 = k0[ 1 ];

        std::cout << "w1 should be 3B: " << w1.toString ( ) << "\n";

        const Word rW = rotateWord ( w1 );
        std::cout << "rW should be B3: " << rW.toString ( ) << "\n";

        const Word sW = subWord ( rW );
        std::cout << "sW should be 3B: " << sW.toString ( ) << "\n";
        std::cout << "RC[0] should be 80: " << RC[ 0 ].toString ( ) << "\n";

        const Word t2 = sW ^ RC[ 0 ];

        std::cout << "t2 should be BB: " << t2.toString ( ) << "\n";

        const Word w2 = w0 ^ t2;
        std::cout << "w2 should be 1C: " << w2.toString ( ) << "\n";

        const Word w3 = w2 ^ w1;
        std::cout << "w3 should be 27: " << w3.toString ( ) << "\n";

        const Matrix k1 ( w2, w3 );
        std::cout << "k1 should be 1C27: " << k1.toString ( ) << "\n";
    }
    void debug ( ) {
        const Matrix p ( "6F6B" );
        std::cout << "P = 6F6B" << "\n";

        const Matrix k0 ( "A73B" );
        std::cout << "K0 = A73B" << "\n";

        const Matrix k1 = computeKey ( k0, 1 );
        std::cout << "K1 should be: 1C27" << "\n";
        std::cout << "K1: " << k1.toString ( ) << "\n";

        const Matrix k2 = computeKey ( k0, 2 );
        std::cout << "K2 should be: 7651" << "\n";
        std::cout << "K2: " << k2.toString ( ) << "\n";

        const Matrix aRK = addRoundKey ( p, k0 );
        std::cout << "addRoundKey should be: C850" << "\n";
        std::cout << "addRoundKey: " << aRK.toString ( ) << "\n";

        std::cout << "---------------------------------------------------------"
                     "-------\n";
        std::cout << "Round 1:" << "\n";

        const Matrix sM = subMatrix ( aRK );
        std::cout << "subMatrix should be: C619" << "\n";
        std::cout << "subMatrix: " << sM.toString ( ) << "\n";

        const Matrix sR = shiftRows ( sM );
        std::cout << "shiftRows should be: C916" << "\n";
        std::cout << "shiftRows: " << sR.toString ( ) << "\n";

        const Matrix mC = mixColumns ( sR );
        std::cout << "mixColumns should be: ECA2" << "\n";
        std::cout << "mixColumns: " << mC.toString ( ) << "\n";

        const Matrix aRK2 = addRoundKey ( mC, k1 );
        std::cout << "addRoundKey2 should be: F085" << "\n";
        std::cout << "addRoundKey2: " << aRK2.toString ( ) << "\n";

        std::cout << "---------------------------------------------------------"
                     "-------\n";
        std::cout << "Round 2:" << "\n";

        const Matrix sM2 = subMatrix ( aRK2 );
        std::cout << "subMatrix2 should be: 7961" << "\n";
        std::cout << "subMatrix2: " << sM2.toString ( ) << "\n";

        const Matrix sR2 = shiftRows ( sM2 );
        std::cout << "shiftRows2 should be: 7169" << "\n";
        std::cout << "shiftRows2: " << sR2.toString ( ) << "\n";

        const Matrix aRK3 = addRoundKey ( sR2, k2 );
        std::cout << "addRoundKey3 should be: 0738" << "\n";
        std::cout << "addRoundKey3: " << aRK3.toString ( ) << "\n";
    }

    Matrix applyCipher ( const Matrix &p, const Matrix &k, const Op &op ) {
        const Matrix k1 = computeKey ( k, 1 );
        const Matrix k2 = computeKey ( k, 2 );
        if ( op == Op::ENCRYPT ) {
            const Matrix s = addRoundKey ( p, k );

            // Round 1
            const Matrix r1
                = addRoundKey ( mixColumns ( shiftRows ( subMatrix ( s ) ) ),
                                k1 );

            // Round 2
            const Matrix r2
                = addRoundKey ( shiftRows ( subMatrix ( r1 ) ), k2 );

            return r2;
        } else {
            const Matrix s = addRoundKey ( p, k2 );

            // Round 1
            const Matrix r1

                // Round 2
                const Matrix r2
                = addRoundKey ( shiftRows ( subMatrix ( r1 ) ), k2 );

            return r2;
        }
    }

    Matrix addRoundKey ( const Matrix &s, const Matrix &k ) { return s ^ k; }

    Matrix subMatrix ( const Matrix &s ) {
        return Matrix ( subWord ( s[ 0 ] ), subWord ( s[ 1 ] ) );
    }

    Matrix shiftRows ( const Matrix &s ) {
        const Word w0 = Word ( s[ 0 ][ 0 ], s[ 1 ][ 1 ] );
        const Word w1 = Word ( s[ 1 ][ 0 ], s[ 0 ][ 1 ] );
        return Matrix ( w0, w1 );
    }

    Matrix mixColumns ( const Matrix &s ) {
        const Matrix C ( "1441" );
        return C * s;
    }

    Matrix computeKey ( const Matrix &k, const uint16_t &round ) {
        const std::array< Word, 2 > RC { Word ( Nyb ( 0x8 ), Nyb ( 0x0 ) ),
                                         Word ( Nyb ( 0x3 ), Nyb ( 0x0 ) ) };
        const Word w0 = k[ 0 ];
        const Word w1 = k[ 1 ];

        const Word t2 = subWord ( rotateWord ( w1 ) ) ^ RC[ 0 ];

        const Word w2 = w0 ^ t2;
        const Word w3 = w2 ^ w1;
        const Word t4 = subWord ( rotateWord ( w3 ) ) ^ RC[ 1 ];

        const Word w4 = w2 ^ t4;
        const Word w5 = w4 ^ w3;

        if ( round == 1 ) {
            return Matrix ( w2, w3 );

        } else {
            return Matrix ( w4, w5 );
        }
    }

    Word subWord ( const Word &w ) {
        return Word ( subNyb ( w[ 0 ] ), subNyb ( w[ 1 ] ) );
    }

    Nyb subNyb ( const Nyb &n ) {
        const std::array< Nyb, 16 > lookUp {
            Nyb ( 0x9 ), Nyb ( 0x4 ), Nyb ( 0xA ), Nyb ( 0xB ),
            Nyb ( 0xD ), Nyb ( 0x1 ), Nyb ( 0x8 ), Nyb ( 0x5 ),
            Nyb ( 0x6 ), Nyb ( 0x2 ), Nyb ( 0 ),   Nyb ( 0x3 ),
            Nyb ( 0xC ), Nyb ( 0xE ), Nyb ( 0xF ), Nyb ( 0x7 )
        };

        return lookUp[ n.toUInt ( ) ];
    }

    Word rotateWord ( const Word &w ) { return Word ( w[ 1 ], w[ 0 ] ); }
}  // namespace SAES
