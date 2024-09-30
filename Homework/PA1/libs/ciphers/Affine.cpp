#include "include/ciphers/Affine.h"

#include <cstdint>
#include <map>
#include <numeric>
#include <vector>

#include "include/ciphers/Utility.h"
namespace Affine {
    AffineFunction::AffineFunction ( const int16_t &a, const int16_t &b )
        : m_a ( a )
        , m_b ( b ) {}

    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const AffineFunction &func,
                                        const Utility::OpType &opType ) {
        auto applyFunc = [ &func, &opType ] ( const int16_t &num ) -> int16_t {
            return opType == Utility::OpType::ENCRYPT
                       ? Utility::posMod ( ( func.m_a * num ) + func.m_b )
                       : Utility::posMod ( inverse ( func.m_a )
                                           * ( num - func.m_b ) );
        };

        return Utility::CipherVector (
            std::accumulate ( vec.begin ( ),
                              vec.end ( ),
                              std::vector< int16_t > { },
                              [ &applyFunc ] ( std::vector< int16_t > acc,
                                               const int16_t &num ) {
                                  acc.push_back ( applyFunc ( num ) );
                                  return acc;
                              } ),
            opType );
    }

    int16_t inverse ( const int16_t &num ) {
        const std::map< int16_t, int16_t > inverseMap {
            { 1, 3 },   { 3, 9 },   { 5, 21 },  { 7, 15 },
            { 9, 3 },   { 11, 19 }, { 15, 7 },  { 17, 23 },
            { 19, 11 }, { 21, 5 },  { 23, 17 }, { 25, 25 }
        };
        return inverseMap.find ( num )->second;
    }

    std::vector< Utility::CipherVector > bruteForceCipher (
        const std::vector< int16_t > &vec,
        const AffineFunction &func ) {
        std::vector< Utility::CipherVector > returnVec;
        for ( int b = 0; b < 26; b++ ) {
            returnVec.push_back ( applyCipher ( vec,
                                                AffineFunction ( func.m_a, b ),
                                                Utility::OpType::DECRYPT ) );
        }
        return returnVec;
    }
}  // namespace Affine
