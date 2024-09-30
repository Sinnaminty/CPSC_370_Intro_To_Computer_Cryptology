#ifndef SHIFT_H
#define SHIFT_H
#include "Utility.h"

namespace Shift {
    Utility::CipherVector applyFrequencyCount (
        const std::vector< int16_t > &vec );

    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const int16_t &key,
                                        const Utility::OpType &opType );
}  // namespace Shift
#endif
