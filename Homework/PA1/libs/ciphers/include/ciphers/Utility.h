#ifndef UTILITY_H
#define UTILITY_H
#include <cstdint>
#include <string>
#include <vector>

namespace Utility {

    /**
     * @enum OpType
     * @brief Represents the type of operation to be performed.
     */
    enum class OpType {
        ENCRYPT,  /**< Encryption operation */
        DECRYPT,  /**< Decryption operation */
        FREQUENCY /**< Frequency analysis operation */
    };

    /**
     * @struct Matrix
     * @brief A 2D matrix of int16_t values, representing either plain text or
     * cipher text.
     */
    struct Matrix {
        using Data = std::vector< std::vector< int16_t > >;
        Data matrix; /**< The underlying 2D vector holding the matrix data */

        /**
         * @brief Constructs an empty square matrix of the given size.
         * @param size The size of the matrix (n x n).
         */
        Matrix ( const size_t &size );

        /**
         * @brief Constructs a matrix from a flat vector, with the specified row
         * width. Fills any left over spaces with the value 24 (x).
         * @param vec The flat vector of int16_t values.
         * @param width The width of each row in the matrix.
         */
        Matrix ( const std::vector< int16_t > &vec, const size_t &width );

        /**
         * @brief Accesses a specific row of the matrix.
         * @param index The row index.
         * @return A reference to the row vector.
         */
        std::vector< int16_t > &operator[] ( const size_t &index );

        /**
         * @brief Accesses a specific row of the matrix (const version).
         * @param index The row index.
         * @return A const reference to the row vector.
         */
        const std::vector< int16_t > &operator[] ( const size_t &index ) const;

        /**
         * @brief Returns an iterator to the beginning of the matrix.
         * @return An iterator to the first row of the matrix.
         */
        Data::iterator begin ( );

        /**
         * @brief Returns a const iterator to the beginning of the matrix.
         * @return A const iterator to the first row of the matrix.
         */
        Data::const_iterator begin ( ) const;

        /**
         * @brief Returns an iterator to the end of the matrix.
         * @return An iterator to the row past the last row of the matrix.
         */
        Data::iterator end ( );

        /**
         * @brief Returns a const iterator to the end of the matrix.
         * @return A const iterator to the row past the last row of the matrix.
         */
        Data::const_iterator end ( ) const;

        /**
         * @brief Returns the size of the matrix (number of rows).
         * @return The number of rows in the matrix.
         */
        size_t size ( ) const;
    };

    /**
     * @struct CipherVector
     * @brief A vector of int16_t values representing ciphered or plain text,
     * along with the operation type.
     */
    struct CipherVector {
        using Data = std::vector< int16_t >;
        Data cipherVector; /**< The vector holding the ciphered or plain text */
        OpType opType; /**< The operation type (encrypt, decrypt, or frequency
                          analysis) */

        /**
         * @brief Constructs a CipherVector from a vector of int16_t values.
         * @param vec The vector of int16_t values.
         * @param opType The operation type.
         */
        CipherVector ( const std::vector< int16_t > &vec,
                       const OpType &opType );

        /**
         * @brief Constructs a CipherVector from a Matrix.
         * @param matrix The matrix to construct the CipherVector from.
         * @param opType The operation type.
         */
        CipherVector ( const Matrix &matrix, const OpType &opType );

        /**
         * @brief Accesses a specific element of the cipher vector.
         * @param index The index of the element.
         * @return A reference to the element.
         */
        int16_t &operator[] ( const size_t &index );

        /**
         * @brief Accesses a specific element of the cipher vector (const
         * version).
         * @param index The index of the element.
         * @return A const reference to the element.
         */
        const int16_t &operator[] ( const size_t &index ) const;

        /**
         * @brief Returns an iterator to the beginning of the cipher vector.
         * @return An iterator to the first element of the cipher vector.
         */
        Data::iterator begin ( );

        /**
         * @brief Returns a const iterator to the beginning of the cipher
         * vector.
         * @return A const iterator to the first element of the cipher vector.
         */
        Data::const_iterator begin ( ) const;

        /**
         * @brief Returns an iterator to the end of the cipher vector.
         * @return An iterator to the element past the last element of the
         * cipher vector.
         */
        Data::iterator end ( );

        /**
         * @brief Returns a const iterator to the end of the cipher vector.
         * @return A const iterator to the element past the last element of the
         * cipher vector.
         */
        Data::const_iterator end ( ) const;
    };

    /**
     * @brief Converts a string to a vector of int16_t values, representing the
     * positions of characters.
     * @param text The input string.
     * @return A vector of int16_t values corresponding to the positions of
     * characters.
     */
    std::vector< int16_t > toNumVector ( const std::string &text );

    /**
     * @brief Converts a CipherVector back into a string representation.
     * @param vec The CipherVector to convert.
     * @return A string representation of the CipherVector.
     */
    std::string toString ( const CipherVector &vec );

    /**
     * @brief Performs a positive modulo operation on an integer.
     * @param num The integer to perform modulo on.
     * @return The positive result of the modulo operation.
     */
    int16_t posMod ( const int16_t &num );

};  // namespace Utility

#endif  // UTILITY_H
