#include "include/ciphers/Hill.h"

#include <algorithm>
#include <cstdint>
#include <vector>

#include "include/ciphers/Utility.h"

namespace Hill {
    std::vector< Utility::Matrix > toMatrixVector (
        const std::vector< int16_t > &vec,
        const size_t &n ) {
        std::vector< Utility::Matrix > matrices;
        size_t i = 0;

        while ( i + n * n - 1 < vec.size ( ) ) {
            Utility::Matrix mat ( n, n );
            for ( size_t row = 0; row < n; ++row ) {
                for ( size_t col = 0; col < n; ++col ) {
                    mat[ row ][ col ] = vec[ i++ ];
                }
            }
            matrices.push_back ( mat );
        }

        size_t remainingElements = vec.size ( ) - i;
        if ( remainingElements > 0 ) {
            size_t numRows = ( remainingElements + n - 1 ) / n;
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

    Utility::Matrix findKey ( const std::vector< int16_t > &plainText,
                              const std::vector< int16_t > &cipherText,
                              const size_t &n ) {
        std::vector< Utility::Matrix > plainTrix
            = toMatrixVector ( plainText, n );
        std::vector< Utility::Matrix > ciphTrix
            = toMatrixVector ( cipherText, n );
    }

    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const Utility::Matrix &key,
                                        const Utility::OpType &opType ) {
        std::vector< Utility::Matrix > matrixVector
            = toMatrixVector ( vec, key.n ( ) );
        std::vector< Utility::Matrix > cipherMatrixVector;
        for ( const Utility::Matrix &mat : matrixVector ) {
            opType == Utility::OpType::ENCRYPT
                ? cipherMatrixVector.push_back ( Utility::posModMatrix (
                      Utility::mulMatrix ( mat, key ) ) )
                : cipherMatrixVector.push_back ( Utility::posModMatrix (
                      Utility::mulMatrix ( mat,
                                           Utility::inverseMatrix ( key ) ) ) );
        }
        std::vector< int16_t > returnVec;
        for ( const Utility::Matrix &mat : cipherMatrixVector ) {
            std::for_each ( mat.begin ( ),
                            mat.end ( ),
                            [ & ] ( const std::vector< int16_t > &row ) {
                                returnVec.insert ( returnVec.end ( ),
                                                   row.begin ( ),
                                                   row.end ( ) );
                            } );
        }
        return Utility::CipherVector ( returnVec, opType );
    }
}  // namespace Hill
