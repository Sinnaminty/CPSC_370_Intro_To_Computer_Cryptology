#ifndef AFFINE_H
#define AFFINE_H
#include <cstdint>

#include "Utility.h"
namespace Affine {
    struct AffineFunction {
        int16_t m_a;
        int16_t m_b;
        AffineFunction ( const int16_t &a, const int16_t &b );
    };

    Utility::CipherVector applyCipher ( const Utility::CipherVector &vec,
                                        const AffineFunction &func );
    int16_t applyFunc ( const int16_t &num,
                        const AffineFunction &func,
                        const Utility::OpType &opType );
    int16_t inverse ( const int16_t &num );

};  // namespace Affine
#endif
