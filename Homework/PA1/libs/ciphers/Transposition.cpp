#include "include/ciphers/Transposition.h"

#include <algorithm>
#include <iterator>
#include <vector>

#include "include/ciphers/Utility.h"

namespace Transposition {
    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const std::vector< int16_t > &key,
                                        const Utility::OpType &opType ) {
        size_t numRows = ( vec.size ( ) + key.size ( ) - 1 ) / key.size ( );
        auto transpose =
            [ &key, &numRows, &opType ] (
                const std::vector< int16_t > &vec ) -> std::vector< int16_t > {
            std::vector< int16_t > outVec;
            if ( opType == Utility::OpType::ENCRYPT ) {
                for ( size_t i = 0; i < key.size ( ); i++ ) {
                    auto col = std::distance (
                        key.begin ( ),
                        std::find ( key.begin ( ), key.end ( ), i + 1 ) );
                    for ( size_t row = 0; row < numRows; row++ ) {
                        outVec.push_back ( vec[ row * key.size ( ) + col ] );
                    }
                }
                return outVec;
            } else {
                outVec.resize ( vec.size ( ) );
                for ( size_t i = 0; i < key.size ( ); i++ ) {
                    auto col = std::distance (
                        key.begin ( ),
                        std::find ( key.begin ( ), key.end ( ), i + 1 ) );
                    for ( size_t row = 0; row < numRows; row++ ) {
                        outVec[ row * key.size ( ) + col ]
                            = vec[ row + i * numRows ];
                    }
                }
                return outVec;
            }
        };
        return Utility::CipherVector ( transpose ( transpose ( vec ) ),
                                       opType );
    }
}  // namespace Transposition
