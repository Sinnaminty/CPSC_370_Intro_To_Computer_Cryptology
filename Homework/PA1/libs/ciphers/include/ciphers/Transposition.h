#ifndef TRANSPOSITION_H
#define TRANSPOSITION_H
#include <cstdint>

#include "Utility.h"

namespace Transposition {

    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const std::vector< int16_t > &key,
                                        const Utility::OpType &opType );
}  // namespace Transposition
#endif
