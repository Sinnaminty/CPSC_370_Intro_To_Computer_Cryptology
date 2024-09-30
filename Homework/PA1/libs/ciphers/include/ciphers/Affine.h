#ifndef AFFINE_H
#define AFFINE_H
#include <cstdint>
#include <vector>

#include "Utility.h"
namespace Affine {
    struct AffineFunction {
        int16_t m_a;
        int16_t m_b;
        AffineFunction ( const int16_t &a, const int16_t &b );
    };

    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const AffineFunction &func,
                                        const Utility::OpType &opType );

    int16_t inverse ( const int16_t &num );

    std::vector< Utility::CipherVector > bruteForceCipher (
        const std::vector< int16_t > &vec,
        const AffineFunction &func );
};  // namespace Affine
#endif
