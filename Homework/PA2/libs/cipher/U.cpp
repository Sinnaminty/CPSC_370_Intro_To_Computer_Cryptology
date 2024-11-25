#include "cipher/U.h"

namespace U {
    // Logical XOR of two strings
    std::string logicalXor ( const std::string &a, const std::string &b ) {
        std::string result;
        for ( size_t i = 0; i < a.length ( ); i++ ) {
            ( a[ i ] == b[ i ] ) ? result += "0" : result += "1";
        }
        return result;
    }
}  // namespace U
