#ifndef AFFINE_H
#define AFFINE_H
#include <cstdint>

#include "Utility.h"
namespace Affine {
    struct AffineFunction {
        uint32_t m_a;
        uint32_t m_b;
        AffineFunction ( const uint32_t &a, const uint32_t &b );
    };

    Utility::CipherVector applyCipher ( const Utility::CipherVector &vec,
                                        const AffineFunction &func );
    uint8_t applyFunc ( const uint8_t &num,
                        const AffineFunction &func,
                        const Utility::OpType &opType );
    uint8_t inverse ( const uint8_t &num );

};  // namespace Affine
#endif
