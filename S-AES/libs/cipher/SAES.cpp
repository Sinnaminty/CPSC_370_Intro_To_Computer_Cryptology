#include "include/cipher/SAES.h"

#include "cipher/U.h"

namespace SAES {

    using Nyb = U::Nyb;
    using Matrix = U::Matrix;
    using Op = U::Op;
    Matrix applyCipher ( const Matrix &p, const Matrix &k, const Op &op ) {
        Matrix s = p;
        Matrix k1 = computeKey ( k, 1 );
        Matrix k2 = computeKey ( k, 2 );

        // Round 1
        addRoundKey ( s, k );
        subNibbles ( s );
        shiftRows ( s );
        mixColumns ( s );
        addRoundKey ( s, k1 );

        // Round 2
        subNibbles ( s );
        shiftRows ( s );
        addRoundKey ( s, k2 );

        return s;
    }

    void addRoundKey ( Matrix &s, const Matrix &k ) { s ^= k; }

    void subNibbles ( Matrix &s ) {
        const std::array< Nyb, 16 > lookUp {
            Nyb ( 0x9 ), Nyb ( 0x4 ), Nyb ( 0xA ), Nyb ( 0xB ),
            Nyb ( 0xD ), Nyb ( 0x1 ), Nyb ( 0x8 ), Nyb ( 0x5 ),
            Nyb ( 0x6 ), Nyb ( 0x2 ), Nyb ( 0 ),   Nyb ( 0x3 ),
            Nyb ( 0xC ), Nyb ( 0xE ), Nyb ( 0xF ), Nyb ( 0x7 )
        };
        s[ 0 ][ 0 ] = lookUp[ s[ 0 ][ 0 ].toUInt ( ) ];
        s[ 1 ][ 0 ] = lookUp[ s[ 1 ][ 0 ].toUInt ( ) ];
        s[ 0 ][ 1 ] = lookUp[ s[ 0 ][ 1 ].toUInt ( ) ];
        s[ 1 ][ 1 ] = lookUp[ s[ 1 ][ 1 ].toUInt ( ) ];
    }

    void shiftRows ( U::Matrix &s ) {
        Nyb temp11 = s[ 1 ][ 1 ];
        s[ 1 ][ 1 ] = s[ 1 ][ 0 ];
        s[ 1 ][ 0 ] = temp11;
    }

    void mixColumns ( U::Matrix &s ) {
        const Matrix C ( "1441" );
        s = U::matrixGFMultiply ( C, s );
    }

    U::Matrix computeKey ( const U::Matrix &k, const uint16_t &round ) {
        if ( round == 1 ) {
            // K_1 = [w_2, w_3]
            // w_2 = t_2 ^ w_0 -> t_2 = SwRw(w_1)^RC[1]
            // w_3 = w_2 ^ w_1
        } else if ( round == 2 ) {
            // K_2 = [w_4, w_5]
            // w_4 = t_4 ^ w_2 -> t_4 = SwRw(w_3)^RC[2]
            // w_5 = w_4 ^ w_3
        }
    }
}  // namespace SAES
