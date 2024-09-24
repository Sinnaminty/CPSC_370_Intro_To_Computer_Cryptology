#pragma once

#include <cstdint>
#include <string>
#include <vector>
namespace Utility {
    enum class OpType { ENCRYPT, DECRYPT };

    struct CipherVector {
        std::vector< uint8_t > m_vec;
        OpType m_opType;
        CipherVector ( const std::vector< uint8_t > &vec,
                       const OpType &opType );
    };

    std::vector< uint8_t > toNumVector ( const std::string &text );
    std::string toString ( const CipherVector &vec );
}  // namespace Utility
