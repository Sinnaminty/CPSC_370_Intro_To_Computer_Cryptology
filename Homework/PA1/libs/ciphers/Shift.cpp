#include "include/ciphers/Shift.h"

#include <array>
#include <cstdint>
#include <numeric>
#include <vector>

#include "include/ciphers/Utility.h"
namespace Shift {
    Utility::CipherVector frequencyCount ( const std::vector< int16_t > &vec ) {
        auto freqArray = std::accumulate (
            vec.begin ( ),
            vec.end ( ),
            std::array< int16_t, 26 > { },
            [] ( std::array< int16_t, 26 > acc, const int16_t &num ) {
                acc[ num ]++;
                return acc;
            } );

        return Utility::CipherVector (
            std::vector< int16_t > ( freqArray.begin ( ), freqArray.end ( ) ),
            Utility::OpType::FREQUENCY );
    }
}  // namespace Shift
