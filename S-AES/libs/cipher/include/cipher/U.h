#ifndef U_H
#define U_H

#include <array>
#include <bitset>
#include <cstdint>

namespace U {
    /**
     * @enum Op
     * @brief Represents the type of operation to be performed.
     */
    enum class Op {
        ENCRYPT, /**< Encryption operation */
        DECRYPT  /**< Decryption operation */
    };

    /**
     * @struct Nyb
     * @brief An Array of 4 Bits.
     */
    struct Nyb {
        using Data = std::bitset< 4 >;
        Data nyb;

        /**
         * @brief Constructs a Nyb filled with zeros.
         */
        Nyb ( );

        /**
         * @brief Constructs a Nyb.
         * @param value The value to set this Nyb to.
         */
        Nyb ( const uint8_t &value );

        /**
         * @brief Constructs an empty Nyb from a String.
         * @param value The value to set this Nyb to. Will throw an exception if
         * the string is invalid.
         */
        Nyb ( const std::string &s );

        // Bit wise Operators
        Nyb operator& ( const Nyb &other ) const;
        Nyb operator| ( const Nyb &other ) const;
        Nyb operator~( ) const;
        Nyb operator^ ( const Nyb &other ) const;

        Nyb &operator&= ( const Nyb &other );
        Nyb &operator|= ( const Nyb &other );
        Nyb &operator^= ( const Nyb &other );

        // Shift Operators
        Nyb &operator<<= ( const int &shift );
        Nyb &operator>>= ( const int &shift );

        // Other Operators
        Nyb operator* ( const Nyb &other ) const;

        uint8_t toUInt ( ) const;
        std::string toString ( ) const;
    };

    struct Word {
        using Data = std::array< Nyb, 2 >;
        Data word;

        /**
         * @brief Constructs an empty Word filled with zeros.
         */
        Word ( );

        /**
         * @brief Constructs an Word from a uint8_t.
         * @param value The value to set this Word to.
         */
        Word ( const uint8_t &value );

        /**
         * @brief Constructs an empty Word from two Nybs.
         * @param value The value to set this Word to.
         */
        Word ( const Nyb &n0, const Nyb &n1 );

        /**
         * @brief Constructs an empty Word from a string.
         * @param value The value to set this Word to. Will throw an exception
         * if string isn't valid.
         */
        Word ( const std::string &s );

        // Bit wise Operators
        Word operator& ( const Word &other ) const;
        Word operator| ( const Word &other ) const;
        Word operator~( ) const;
        Word operator^ ( const Word &other ) const;

        Word &operator&= ( const Word &other );
        Word &operator|= ( const Word &other );
        Word &operator^= ( const Word &other );

        // Shift Operators
        Word &operator<<= ( const int &shift );
        Word &operator>>= ( const int &shift );

        // Other operators

        /**
         * @brief Accesses a specific row of the Word.
         * @param index The row index.
         * @return A reference to the row vector.
         */
        Nyb &operator[] ( const size_t &index );

        /**
         * @brief Accesses a specific row of the Word (const version).
         * @param index The row index.
         * @return A const reference to the row vector.
         */
        const Nyb &operator[] ( const size_t &index ) const;

        // Iterators

        /**
         * @brief Returns an iterator to the beginning of the Word.
         * @return An iterator to the first row of the Word.
         */
        Data::iterator begin ( );

        /**
         * @brief Returns a const iterator to the beginning of the Word.
         * @return A const iterator to the first row of the Word.
         */
        Data::const_iterator begin ( ) const;

        /**
         * @brief Returns an iterator to the end of the Word.
         * @return An iterator to the row past the last row of the Word.
         */
        Data::iterator end ( );

        /**
         * @brief Returns a const iterator to the end of the Word.
         * @return A const iterator to the row past the last row of the Word.
         */
        Data::const_iterator end ( ) const;

        uint8_t toUInt ( ) const;

        std::string toString ( ) const;
    };

    /**
     * @struct Matrix
     * @brief A Matrix of 4 Nybs.
     */
    struct Matrix {
        using Data = std::array< Word, 2 >;
        Data matrix;

        /**
         * @brief Constructor for a 2x2 matrix. Creates an empty Matrix filled
         * with zeros.
         */
        Matrix ( );

        /**
         * @brief Constructor for a 2x2 matrix.
         * @param w0 The Word on the left of this Matrix.
         * @param w1 The Word on the right of this Matrix.
         */
        Matrix ( const Word &w0, const Word &w1 );

        /**
         * @brief Constructor for a 2x2 matrix.
         * @param n00 The Nyb in the top left corner of this Matrix.
         * @param n10 The Nyb in the bottom left corner of this Matrix.
         * @param n01 The Nyb in the top right corner of this Matrix.
         * @param n11 The Nyb in the bottom right corner of this Matrix.
         */
        Matrix ( const Nyb &n00,
                 const Nyb &n10,
                 const Nyb &n01,
                 const Nyb &n11 );

        /**
         * @brief Constructor for a 2x2 matrix.
         * @param s The string containing Nybs for this Matrix. Will throw an
         * exception if the string is not valid.
         */
        Matrix ( const std::string &s );

        // Bit wise Operators
        Matrix operator& ( const Matrix &other ) const;
        Matrix operator| ( const Matrix &other ) const;
        Matrix operator~( ) const;
        Matrix operator^ ( const Matrix &other ) const;

        Matrix &operator&= ( const Matrix &other );
        Matrix &operator|= ( const Matrix &other );
        Matrix &operator^= ( const Matrix &other );

        // Other operators

        Matrix operator* ( const Matrix &other ) const;

        /**
         * @brief Accesses a specific row of the matrix.
         * @param index The row index.
         * @return A reference to the row vector.
         */
        Word &operator[] ( const size_t &index );

        /**
         * @brief Accesses a specific row of the matrix (const version).
         * @param index The row index.
         * @return A const reference to the row vector.
         */
        const Word &operator[] ( const size_t &index ) const;

        // Iterators

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
         * @brief Returns a string representation of this Matrix.
         * @return A string representation of this Matrix.
         */
        std::string toString ( ) const;
    };

};  // namespace U

#endif  // U_H
