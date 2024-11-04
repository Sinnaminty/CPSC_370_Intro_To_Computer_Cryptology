#include "cipher/SAES.h"

#include "cipher/U.h"

namespace SAES {
    using namespace U;

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
            const Matrix r1 = invMixColumns (
                addRoundKey ( invSubMatrix ( shiftRows ( s ) ), k1 ) );

            // Round 2
            const Matrix r2
                = addRoundKey ( invSubMatrix ( shiftRows ( r1 ) ), k );

            return r2;
        }
    }

    Matrix addRoundKey ( const Matrix &s, const Matrix &k ) { return s ^ k; }

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

    Word rotateWord ( const Word &w ) { return Word ( w[ 1 ], w[ 0 ] ); }

    ///////////
    /// ENCRYPT
    ///////////

    Matrix subMatrix ( const Matrix &s ) {
        return Matrix ( subWord ( s[ 0 ] ), subWord ( s[ 1 ] ) );
    }

    Word subWord ( const Word &w ) {
        return Word ( subNyb ( w[ 0 ] ), subNyb ( w[ 1 ] ) );
    }

    Nyb subNyb ( const Nyb &n ) {
        const std::array< Nyb, 16 > lookUp {
            Nyb ( 0x9 ), Nyb ( 0x4 ), Nyb ( 0xA ), Nyb ( 0xB ),
            Nyb ( 0xD ), Nyb ( 0x1 ), Nyb ( 0x8 ), Nyb ( 0x5 ),
            Nyb ( 0x6 ), Nyb ( 0x2 ), Nyb ( 0x0 ), Nyb ( 0x3 ),
            Nyb ( 0xC ), Nyb ( 0xE ), Nyb ( 0xF ), Nyb ( 0x7 )
        };

        return lookUp[ n.toUInt ( ) ];
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

    ///////////
    /// DECRYPT
    ///////////

    U::Matrix invSubMatrix ( const U::Matrix &s ) {
        return Matrix ( invSubWord ( s[ 0 ] ), invSubWord ( s[ 1 ] ) );
    }

    U::Word invSubWord ( const U::Word &w ) {
        return Word ( invSubNyb ( w[ 0 ] ), invSubNyb ( w[ 1 ] ) );
    }

    U::Nyb invSubNyb ( const U::Nyb &n ) {
        const std::array< Nyb, 16 > lookUp {
            Nyb ( 0xA ), Nyb ( 0x5 ), Nyb ( 0x9 ), Nyb ( 0xB ),
            Nyb ( 0x1 ), Nyb ( 0x7 ), Nyb ( 0x8 ), Nyb ( 0xF ),
            Nyb ( 0x6 ), Nyb ( 0x0 ), Nyb ( 0x2 ), Nyb ( 0x3 ),
            Nyb ( 0xC ), Nyb ( 0x4 ), Nyb ( 0xD ), Nyb ( 0xE )
        };

        return lookUp[ n.toUInt ( ) ];
    }

    U::Matrix invMixColumns ( const U::Matrix &s ) {
        const Matrix C ( "9229" );
        return C * s;
    }

}  // namespace SAES
