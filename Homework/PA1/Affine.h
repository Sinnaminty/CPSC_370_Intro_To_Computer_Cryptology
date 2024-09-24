#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "Utility.h"
namespace Affine {
    struct AffineFunction {
        int a;
        int b;
    };

    Utility::CipherVector applyCipher ( const Utility::CipherVector &vec,
                                        const AffineFunction &func );
    uint8_t applyFunc ( const uint8_t &num,
                        const AffineFunction &func,
                        const Utility::OpType &opType );
    uint8_t inverse ( const uint8_t &num );

};  // namespace Affine
