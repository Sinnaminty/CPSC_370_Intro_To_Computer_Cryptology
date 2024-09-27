#include "include/ciphers/Affine.h"

#include <cstdint>
#include <map>
#include <numeric>

#include "include/ciphers/Utility.h"
namespace Affine {
    AffineFunction::AffineFunction ( const int16_t &a, const int16_t &b )
        : m_a ( a )
        , m_b ( b ) {}

    Utility::CipherVector applyCipher ( const Utility::CipherVector &vec,
                                        const AffineFunction &func ) {
        return Utility::CipherVector (
            std::accumulate ( vec.m_vec.begin ( ),
                              vec.m_vec.end ( ),
                              std::vector< int16_t > { },
                              [ func, vec ] ( std::vector< int16_t > acc,
                                              const int16_t &num ) {
                                  acc.push_back (
                                      applyFunc ( num, func, vec.m_opType ) );
                                  return acc;
                              } ),
            vec.m_opType );
    }

    int16_t applyFunc ( const int16_t &num,
                        const AffineFunction &func,
                        const Utility::OpType &opType ) {
        return opType == Utility::OpType::ENCRYPT
                   ? Utility::posMod ( ( ( func.m_a * num ) + func.m_b ) )
                   : Utility::posMod ( inverse ( func.m_a )
                                       * ( num - func.m_b ) );
    }

    int16_t inverse ( const int16_t &num ) {
        const std::map< int16_t, int16_t > inverseMap {
            { 1, 3 },   { 3, 9 },   { 5, 21 },  { 7, 15 },
            { 9, 3 },   { 11, 19 }, { 15, 7 },  { 17, 23 },
            { 19, 11 }, { 21, 5 },  { 23, 17 }, { 25, 25 }
        };
        return inverseMap.find ( num )->second;
    }
}  // namespace Affine
