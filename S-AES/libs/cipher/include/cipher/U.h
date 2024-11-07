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
        bool operator< ( const Nyb &other ) const;
        bool operator> ( const Nyb &other ) const;
        bool operator== ( const Nyb &other ) const;
        Nyb operator++ ( int i );

        /**
         * @brief Accesses a specific bit of this Nyb (const version).
         * @param index The row index.
         * @return A const reference to the row vector.
         */
        const bool operator[] ( const size_t &index ) const;

        // Struct Functions

        uint8_t toUInt ( ) const;

        /**
         * @brief Converts this Nyb to a string representation.
         * @return A string that represents this Nyb.
         */
        std::string toString ( ) const;
    };

    /**
     * @struct Word
     * @brief An Array of 2 Nybs.
     */
    struct Word {
        using Data = std::array< Nyb, 2 >;
        Data word;

        /**
         * @brief Constructs an empty Word filled with zeros.
         */
        Word ( );

        /**
         * @brief Constructs a Word from a uint8_t.
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

        bool operator< ( const Word &other ) const;
        bool operator> ( const Word &other ) const;
        bool operator== ( const Word &other ) const;

        Word operator++ ( int i );

        /**
         * @brief Accesses a specific row of this Word.
         * @param index The row index.
         * @return A reference to the row vector.
         */
        Nyb &operator[] ( const size_t &index );

        /**
         * @brief Accesses a specific row of this Word (const version).
         * @param index The row index.
         * @return A const reference to the row vector.
         */
        const Nyb &operator[] ( const size_t &index ) const;

        // Iterators

        /**
         * @brief Returns an iterator to the beginning of this Word.
         * @return An iterator to the first row of this Word.
         */
        Data::iterator begin ( );

        /**
         * @brief Returns a const iterator to the beginning of this Word.
         * @return A const iterator to the first row of this Word.
         */
        Data::const_iterator begin ( ) const;

        /**
         * @brief Returns an iterator to the end of this Word.
         * @return An iterator to the row past the last row of this Word.
         */
        Data::iterator end ( );

        /**
         * @brief Returns a const iterator to the end of this Word.
         * @return A const iterator to the row past the last row of this Word.
         */
        Data::const_iterator end ( ) const;

        uint8_t toUInt ( ) const;

        /**
         * @brief Converts this Word to a string representation.
         * @return A string that represents this Word.
         */
        std::string toString ( ) const;
    };

    /**
     * @struct Matrix
     * @brief A Matrix of 4 Nybs organized in a 2x2 grid.
     */
    struct Matrix {
        using Data = std::array< Word, 2 >;
        Data matrix;

        /**
         * @brief Constructs a 2x2 matrix filled with zeros.
         */
        Matrix ( );

        /**
         * @brief Constructs a 2x2 matrix from a uint16_t.
         * @param value The value to initialize this Matrix with.
         */
        Matrix ( const uint16_t &value );

        /**
         * @brief Constructs a 2x2 matrix from individual Nyb values.
         * @param n00 The top-left Nyb of this matrix.
         * @param n10 The bottom-left Nyb of this matrix.
         * @param n01 The top-right Nyb of this matrix.
         * @param n11 The bottom-right Nyb of this matrix.
         */
        Matrix ( const Nyb &n00,
                 const Nyb &n10,
                 const Nyb &n01,
                 const Nyb &n11 );

        /**
         * @brief Constructs a 2x2 matrix from two Word values.
         * @param w0 The left column Word.
         * @param w1 The right column Word.
         */
        Matrix ( const Word &w0, const Word &w1 );

        /**
         * @brief Constructs a 2x2 matrix from a string representation.
         * @param s A string to initialize this Matrix with. Throws an exception
         * if the string is invalid.
         */
        Matrix ( const std::string &s );

        // Bitwise Operators
        Matrix operator& ( const Matrix &other ) const;
        Matrix operator| ( const Matrix &other ) const;
        Matrix operator~( ) const;
        Matrix operator^ ( const Matrix &other ) const;

        Matrix &operator&= ( const Matrix &other );
        Matrix &operator|= ( const Matrix &other );
        Matrix &operator^= ( const Matrix &other );

        // Other operators

        Matrix operator* ( const Matrix &other ) const;
        bool operator< ( const Matrix &other ) const;
        bool operator> ( const Matrix &other ) const;
        bool operator== ( const Matrix &other ) const;
        Matrix operator++ ( int i );
        Matrix operator+ ( const int &i ) const;

        /**
         * @brief Accesses a specific row of this matrix.
         * @param index The row index.
         * @return A reference to the Word at the specified row.
         */
        Word &operator[] ( const size_t &index );

        /**
         * @brief Accesses a specific row of this matrix (const version).
         * @param index The row index.
         * @return A const reference to the Word at the specified row.
         */
        const Word &operator[] ( const size_t &index ) const;

        // Iterators

        /**
         * @brief Returns an iterator to the beginning of this matrix.
         * @return An iterator to the first row of this matrix.
         */
        Data::iterator begin ( );

        /**
         * @brief Returns a const iterator to the beginning of this matrix.
         * @return A const iterator to the first row of this matrix.
         */
        Data::const_iterator begin ( ) const;

        /**
         * @brief Returns an iterator to the end of this matrix.
         * @return An iterator to the row past the last row of this matrix.
         */
        Data::iterator end ( );

        /**
         * @brief Returns a const iterator to the end of this matrix.
         * @return A const iterator to the row past the last row of this matrix.
         */
        Data::const_iterator end ( ) const;

        /**
         * @brief Converts the matrix to a string representation.
         * @return A string that represents this matrix.
         */
        std::string toString ( ) const;
    };

};  // namespace U

#endif  // U_H
