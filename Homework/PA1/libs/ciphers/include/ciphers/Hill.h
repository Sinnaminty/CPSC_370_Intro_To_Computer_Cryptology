#ifndef HILL_H
#define HILL_H

#include <cstdint>

#include "Utility.h"

namespace Hill {

    std::vector< int16_t > multiplyMatrixVector (
        const Utility::Matrix &matrix,
        const std::vector< int16_t > &vec );

    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const Utility::Matrix &key,
                                        const Utility::OpType &opType );
}  // namespace Hill
#endif
