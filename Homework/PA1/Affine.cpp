#include "Affine.h"

#include <cstdint>
#include <map>
#include <numeric>

#include "Utility.h"

using namespace Affine;

std::vector< uint8_t > applyCipher ( const Utility::CipherVector &vec,
                                     const AffineFunction &func ) {
    return std::accumulate (
        vec.m_vec.begin ( ),
        vec.m_vec.end ( ),
        std::vector< uint8_t > { },
        [ func, vec ] ( std::vector< uint8_t > acc, const uint8_t &num ) {
            acc.push_back ( applyFunc ( num, func, vec.m_opType ) );
            return acc;
        } );
}

uint8_t applyFunc ( const uint8_t &num,
                    const AffineFunction &func,
                    const Utility::OpType &opType ) {
    return opType == Utility::OpType::ENCRYPT
               ? ( ( func.a * num ) + func.b ) % 26
               : ( inverse ( func.a ) * ( num - func.b ) ) % 26;
}

uint8_t inverse ( const uint8_t &num ) {
    const std::map< uint8_t, uint8_t > inverseMap {
        { 1, 3 },  { 3, 9 },   { 5, 21 },  { 7, 15 }, { 9, 3 },   { 11, 19 },
        { 15, 7 }, { 17, 23 }, { 19, 11 }, { 21, 5 }, { 23, 17 }, { 25, 25 }
    };
    return inverseMap.find ( num )->second;
}
