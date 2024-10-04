#include "include/ciphers/Hill.h"

#include <cstdint>
#include <vector>

#include "include/ciphers/Utility.h"

namespace Hill {
    std::vector< Utility::Matrix > toMatrixVector (
        const std::vector< int16_t > &vec,
        const size_t &n ) {
        std::vector< Utility::Matrix > matrices;
        size_t i = 0;

        // Process full n x n matrices
        while ( i + n * n - 1 < vec.size ( ) ) {
            Utility::Matrix mat ( n, n );
            for ( size_t row = 0; row < n; ++row ) {
                for ( size_t col = 0; col < n; ++col ) {
                    mat[ row ][ col ] = vec[ i++ ];
                }
            }
            matrices.push_back ( mat );
        }

        // Handle the remaining elements if any
        size_t remainingElements = vec.size ( ) - i;
        if ( remainingElements > 0 ) {
            size_t numRows = ( remainingElements + n - 1 )
                             / n;  // Calculate number of rows needed
            Utility::Matrix mat ( numRows, n );
            for ( size_t row = 0; row < numRows; ++row ) {
                for ( size_t col = 0; col < n; ++col ) {
                    if ( i < vec.size ( ) ) {
                        mat[ row ][ col ] = vec[ i++ ];
                    } else {
                        mat[ row ][ col ] = 0;
                    }
                }
            }
            matrices.push_back ( mat );
        }

        return matrices;
    }

    Utility::Matrix func ( const Utility::Matrix &mat,
                           const Utility::Matrix &key ) {}

    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const Utility::Matrix &key,
                                        const Utility::OpType &opType ) {
        std::vector< Utility::Matrix > matrixVector
            = toMatrixVector ( vec, key.n ( ) );
        std::vector< Utility::Matrix > cipherMatrixVector;
        for ( const Utility::Matrix &mat : matrixVector ) {
            cipherMatrixVector.push_back ( func ( mat, key ) );
        }
    }
}  // namespace Hill