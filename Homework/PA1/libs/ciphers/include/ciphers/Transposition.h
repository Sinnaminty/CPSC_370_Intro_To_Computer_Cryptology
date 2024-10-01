#ifndef TRANSPOSITION_H
#define TRANSPOSITION_H
#include "Utility.h"

namespace Transposition {
    Utility::CipherVector du ( const std::vector< int16_t > &vec,
                               const std::vector< int16_t > &key,
                               const Utility::OpType &opType );
    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const std::vector< int16_t > &key,
                                        const Utility::OpType &opType );
    std::vector< size_t > generateColumnOrder (
        const std::vector< int16_t > &key );

}  // namespace Transposition
#endif
