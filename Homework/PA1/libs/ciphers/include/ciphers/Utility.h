#ifndef UTILITY_H
#define UTILITY_H
#include <cstdint>
#include <string>
#include <vector>
namespace Utility {
    enum class OpType { ENCRYPT, DECRYPT };

    struct CipherVector {
        std::vector< int16_t > m_vec;
        OpType m_opType;
        CipherVector ( const std::vector< int16_t > &vec,
                       const OpType &opType );
    };

    std::vector< int16_t > toNumVector ( const std::string &text );
    std::string toString ( const CipherVector &vec );
    int16_t posMod ( const int16_t &num );
};  // namespace Utility
#endif
