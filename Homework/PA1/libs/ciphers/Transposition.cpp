#include "include/ciphers/Transposition.h"

#include <vector>

#include "include/ciphers/Utility.h"

namespace Transposition {

    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const std::vector< int16_t > &key,
                                        const Utility::OpType &opType ) {
        auto transpose
            = [ &key ] ( const Utility::Matrix &matrix ) -> Utility::Matrix {
            Utility::Matrix transposedMatrix ( matrix.size ( ) );
            for ( size_t row = 0; row < matrix.size ( ); ++row ) {
                for ( size_t col = 0; col < key.size ( ); ++col ) {
                    // Use the key to define the column reordering
                    size_t targetCol = key[ col ];
                    transposedMatrix[ row ][ col ] = matrix[ row ][ targetCol ];
                }
            }
            return transposedMatrix;
        };
        return Utility::CipherVector (
            transpose ( transpose ( Utility::Matrix ( vec, key.size ( ) ) ) ),
            opType );
    }
}  // namespace Transposition
