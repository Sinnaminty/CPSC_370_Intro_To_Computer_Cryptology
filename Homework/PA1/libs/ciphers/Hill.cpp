#include "include/ciphers/Hill.h"

#include <cstdint>

#include "include/ciphers/Utility.h"

namespace Hill {
    std::vector< int16_t > multiplyMatrixVector (
        const Utility::Matrix &matrix,
        const std::vector< int16_t > &vec ) {
        size_t matrixSize = matrix.size ( );
        std::vector< int16_t > result ( matrixSize, 0 );

        for ( size_t row = 0; row < matrixSize; ++row ) {
            for ( size_t col = 0; col < matrixSize; ++col ) {
                result[ row ] += matrix[ row ][ col ] * vec[ col ];
            }
            result[ row ] = Utility::posMod (
                result[ row ] );  // Apply mod 26 to each result
        }
        return result;
    }

    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const Utility::Matrix &key,
                                        const Utility::OpType &opType ) {
        std::vector< int16_t > outVec;
        size_t blockSize
            = key.size ( );  // Block size is the dimension of the key matrix

        // Ensure input is divisible by blockSize, padding with zeros if
        // necessary
        std::vector< int16_t > paddedVec = vec;
        while ( paddedVec.size ( ) % blockSize != 0 ) {
            paddedVec.push_back ( 0 );  // Pad with zeros
        }

        // Process the input in blocks of 'blockSize'
        for ( size_t i = 0; i < paddedVec.size ( ); i += blockSize ) {
            std::vector< int16_t > block (
                paddedVec.begin ( ) + i,
                paddedVec.begin ( ) + i + blockSize );

            // ENCRYPT: Multiply the block by the key matrix
            if ( opType == Utility::OpType::ENCRYPT ) {
                std::vector< int16_t > encryptedBlock
                    = multiplyMatrixVector ( key, block );
                outVec.insert ( outVec.end ( ),
                                encryptedBlock.begin ( ),
                                encryptedBlock.end ( ) );
            }
            // DECRYPT: Multiply the block by the inverse key matrix
            else if ( opType == Utility::OpType::DECRYPT ) {
                // For decryption, you need to pass in the inverse key matrix
                // Assuming `key` is already the inverse for decryption
                std::vector< int16_t > decryptedBlock
                    = multiplyMatrixVector ( key, block );
                outVec.insert ( outVec.end ( ),
                                decryptedBlock.begin ( ),
                                decryptedBlock.end ( ) );
            }
        }

        return Utility::CipherVector ( outVec, opType );
    }
}  // namespace Hill
