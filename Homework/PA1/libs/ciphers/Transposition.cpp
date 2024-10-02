#include "include/ciphers/Transposition.h"

#include <vector>

#include "include/ciphers/Utility.h"

namespace Transposition {
    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const std::vector< int16_t > &key,
                                        const Utility::OpType &opType ) {
        // Lambda to transpose the matrix
        auto transpose
            = [ &key ] ( const Utility::Matrix &matrix ) -> Utility::Matrix {
            Utility::Matrix transposedMatrix ( matrix );

            // Perform transposition based on key values
            for ( int i = 0; i < key.size ( ); ++i ) {
                int k = key[ i ];
                for ( int j = 0; j < matrix.size ( ); ++j ) {
                    transposedMatrix[ j ][ k ] = matrix[ j ][ i ];
                }
            }
            return transposedMatrix;
        };

        return Utility::CipherVector (
            transpose ( Utility::Matrix ( vec, key.size ( ) ) ),
            opType );
    }
}  // namespace Transposition
