#ifndef HILL_H
#define HILL_H

#include <cstdint>

#include "Utility.h"

namespace Hill {
    std::vector< Utility::Matrix > toMatrixVector (
        const std::vector< int16_t > &vec,
        const size_t &n );
    Utility::Matrix func ( const Utility::Matrix &mat,
                           const Utility::Matrix &key );
    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const Utility::Matrix &key,
                                        const Utility::OpType &opType );
}  // namespace Hill
#endif
