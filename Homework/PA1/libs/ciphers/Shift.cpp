#include "include/ciphers/Shift.h"

#include <array>
#include <cstdint>
#include <numeric>
#include <vector>

#include "include/ciphers/Utility.h"
namespace Shift {
    Utility::CipherVector applyFrequencyCount (
        const std::vector< int16_t > &vec ) {
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
    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const int16_t &key,
                                        const Utility::OpType &opType ) {
        auto shift = [ &key, &opType ] ( const int16_t &num ) -> int16_t {
            return opType == Utility::OpType::ENCRYPT
                       ? Utility::posMod ( num + key )
                       : Utility::posMod ( num - key );
        };
        return Utility::CipherVector (
            std::accumulate (
                vec.begin ( ),
                vec.end ( ),
                std::vector< int16_t > { },
                [ &shift ] ( std::vector< int16_t > acc, const int16_t &num ) {
                    acc.push_back ( shift ( num ) );
                    return acc;
                } ),
            opType );
    }
}  // namespace Shift
