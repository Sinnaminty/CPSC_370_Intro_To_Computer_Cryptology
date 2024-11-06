#include "cipher/DCA.h"

#include <algorithm>
#include <iostream>
#include <random>

#include "cipher/SAES.h"
#include "cipher/U.h"

namespace DCA {
    using namespace U;
    Matrix genRandomMatrix ( ) {
        std::random_device rd;
        auto seed_data = std::array< int, std::mt19937::state_size > { };
        std::generate ( std::begin ( seed_data ),
                        std::end ( seed_data ),
                        std::ref ( rd ) );
        std::seed_seq seq ( std::begin ( seed_data ), std::end ( seed_data ) );
        std::mt19937 generator ( seq );
        std::uniform_int_distribution< uint16_t > dis (
            std::numeric_limits< uint16_t >::min ( ),
            std::numeric_limits< uint16_t >::max ( ) );

        uint16_t n = dis ( generator );

        return Matrix ( n );
    }

    Matrix createDifference ( const U::Matrix &s, const U::Nyb &diff ) {
        U::Matrix ret = s;
        for ( size_t i = 0; i < 4; i++ ) {
            if ( diff[ i ] ) {
                if ( i == 0 ) {
                    ret[ 1 ][ 1 ] ^= 0x1;
                } else if ( i == 1 ) {
                    ret[ 1 ][ 0 ] ^= 0x1;
                } else if ( i == 2 ) {
                    ret[ 0 ][ 1 ] ^= 0x1;
                } else if ( i == 3 ) {
                    ret[ 0 ][ 0 ] ^= 0x1;
                }
            }
        }
        return ret;
    }

    Matrix calcDifference ( const U::Matrix &a, const U::Matrix &b ) {
        return a ^ b;
    }

    Matrix secretEncrypt ( const U::Matrix &p ) {
        const Matrix k ( 0xF2AB );
        const Matrix s = SAES::addRoundKey ( p, k );
        return SAES::mixColumns ( SAES::shiftRows ( SAES::subMatrix ( s ) ) );
    }
}  // namespace DCA
