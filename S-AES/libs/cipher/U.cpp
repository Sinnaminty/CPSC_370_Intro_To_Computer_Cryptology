#include "include/cipher/U.h"

#include <cstdint>
#include <sstream>
#include <stdexcept>

namespace U {
    ///////
    /// NYB
    ///////

    Nyb::Nyb ( const uint8_t &value )
        : nyb ( value & 0x0F ) {}

    //////////////////////////
    /// NYB BITWISE OPERATIONS
    //////////////////////////

    Nyb Nyb::operator& ( const Nyb &other ) const {
        return Nyb ( this->toUInt ( ) & other.toUInt ( ) );
    }
    Nyb Nyb::operator| ( const Nyb &other ) const {
        return Nyb ( this->toUInt ( ) | other.toUInt ( ) );
    }
    Nyb Nyb::operator~( ) const { return Nyb ( ~this->toUInt ( ) & 0x0F ); }
    Nyb Nyb::operator^ ( const Nyb &other ) const {
        return Nyb ( this->toUInt ( ) ^ other.toUInt ( ) );
    }

    Nyb &Nyb::operator&= ( const Nyb &other ) {
        this->nyb &= other.nyb;
        return *this;
    }
    Nyb &Nyb::operator|= ( const Nyb &other ) {
        this->nyb |= other.nyb;
        return *this;
    }

    Nyb &Nyb::operator^= ( const Nyb &other ) {
        this->nyb ^= other.nyb;
        return *this;
    }

    //////////////////
    // SHIFT OPERATORS
    //////////////////

    Nyb &Nyb::operator<<= ( const int &shift ) {
        this->nyb <<= shift;
        this->nyb &= 0x0F;
        return *this;
    }
    Nyb &Nyb::operator>>= ( const int &shift ) {
        this->nyb >>= shift;
        return *this;
    }

    uint8_t Nyb::toUInt ( ) const {
        return static_cast< uint8_t > ( this->nyb.to_ulong ( ) );
    }
    std::string Nyb::toString ( ) const {
        std::stringstream ss;
        ss << std::hex << this->toUInt ( );
        return ss.str ( );
    }

    ////////////////
    /// MATRIX
    ////////////////

    Matrix::Matrix ( const Nyb &n00,
                     const Nyb &n10,
                     const Nyb &n01,
                     const Nyb &n11 ) {
        matrix[ 0 ][ 0 ] = n00;
        matrix[ 1 ][ 0 ] = n10;
        matrix[ 0 ][ 1 ] = n01;
        matrix[ 1 ][ 1 ] = n11;
    }

    Matrix::Matrix ( const std::string &s ) {
        if ( s.size ( ) != 4 ) {
            throw std::invalid_argument (
                "Matrix string must be exactly 4 characters long. s.size() = "
                + std::to_string ( s.size ( ) ) );
        }
        matrix[ 0 ][ 0 ] = Nyb ( std::stoi ( s.substr ( 0, 1 ), nullptr, 16 ) );
        matrix[ 1 ][ 0 ] = Nyb ( std::stoi ( s.substr ( 1, 1 ), nullptr, 16 ) );
        matrix[ 0 ][ 1 ] = Nyb ( std::stoi ( s.substr ( 2, 1 ), nullptr, 16 ) );
        matrix[ 1 ][ 1 ] = Nyb ( std::stoi ( s.substr ( 3, 1 ), nullptr, 16 ) );
    }

    // Bit wise Operators
    Matrix Matrix::operator& ( const Matrix &other ) const {
        Nyb n00 ( this->matrix[ 0 ][ 0 ] & other.matrix[ 0 ][ 0 ] );
        Nyb n10 ( this->matrix[ 1 ][ 0 ] & other.matrix[ 1 ][ 0 ] );
        Nyb n01 ( this->matrix[ 0 ][ 1 ] & other.matrix[ 0 ][ 1 ] );
        Nyb n11 ( this->matrix[ 1 ][ 1 ] & other.matrix[ 1 ][ 1 ] );
        return Matrix ( n00, n10, n01, n11 );
    }
    Matrix Matrix::operator| ( const Matrix &other ) const {
        Nyb n00 ( this->matrix[ 0 ][ 0 ] | other.matrix[ 0 ][ 0 ] );
        Nyb n10 ( this->matrix[ 1 ][ 0 ] | other.matrix[ 1 ][ 0 ] );
        Nyb n01 ( this->matrix[ 0 ][ 1 ] | other.matrix[ 0 ][ 1 ] );
        Nyb n11 ( this->matrix[ 1 ][ 1 ] | other.matrix[ 1 ][ 1 ] );
        return Matrix ( n00, n10, n01, n11 );
    }
    Matrix Matrix::operator~( ) const {
        Nyb n00 ( ~this->matrix[ 0 ][ 0 ] );
        Nyb n10 ( ~this->matrix[ 1 ][ 0 ] );
        Nyb n01 ( ~this->matrix[ 0 ][ 1 ] );
        Nyb n11 ( ~this->matrix[ 1 ][ 1 ] );
        return Matrix ( n00, n10, n01, n11 );
    }
    Matrix Matrix::operator^ ( const Matrix &other ) const {
        Nyb n00 ( this->matrix[ 0 ][ 0 ] ^ other.matrix[ 0 ][ 0 ] );
        Nyb n10 ( this->matrix[ 1 ][ 0 ] ^ other.matrix[ 1 ][ 0 ] );
        Nyb n01 ( this->matrix[ 0 ][ 1 ] ^ other.matrix[ 0 ][ 1 ] );
        Nyb n11 ( this->matrix[ 1 ][ 1 ] ^ other.matrix[ 1 ][ 1 ] );
        return Matrix ( n00, n10, n01, n11 );
    }

    Matrix &Matrix::operator&= ( const Matrix &other ) {
        this->matrix[ 0 ][ 0 ] &= other.matrix[ 0 ][ 0 ];
        this->matrix[ 1 ][ 0 ] &= other.matrix[ 1 ][ 0 ];
        this->matrix[ 0 ][ 1 ] &= other.matrix[ 0 ][ 1 ];
        this->matrix[ 1 ][ 1 ] &= other.matrix[ 1 ][ 1 ];
        return *this;
    }
    Matrix &Matrix::operator|= ( const Matrix &other ) {
        this->matrix[ 0 ][ 0 ] |= other.matrix[ 0 ][ 0 ];
        this->matrix[ 1 ][ 0 ] |= other.matrix[ 1 ][ 0 ];
        this->matrix[ 0 ][ 1 ] |= other.matrix[ 0 ][ 1 ];
        this->matrix[ 1 ][ 1 ] |= other.matrix[ 1 ][ 1 ];
        return *this;
    }
    Matrix &Matrix::operator^= ( const Matrix &other ) {
        this->matrix[ 0 ][ 0 ] ^= other.matrix[ 0 ][ 0 ];
        this->matrix[ 1 ][ 0 ] ^= other.matrix[ 1 ][ 0 ];
        this->matrix[ 0 ][ 1 ] ^= other.matrix[ 0 ][ 1 ];
        this->matrix[ 1 ][ 1 ] ^= other.matrix[ 1 ][ 1 ];
        return *this;
    }

    // Other Operators

    std::array< Nyb, 2 > &Matrix::operator[] ( const size_t &index ) {
        return matrix[ index ];
    }

    const std::array< Nyb, 2 > &Matrix::operator[] (
        const size_t &index ) const {
        return matrix[ index ];
    }

    Matrix::Data::iterator Matrix::begin ( ) { return matrix.begin ( ); }

    Matrix::Data::iterator Matrix::end ( ) { return matrix.end ( ); }

    Matrix::Data::const_iterator Matrix::begin ( ) const {
        return matrix.begin ( );
    }
    Matrix::Data::const_iterator Matrix::end ( ) const {
        return matrix.end ( );
    }

    std::string Matrix::toString ( ) const {
        std::stringstream ss;
        ss << matrix[ 0 ][ 0 ].toString ( ) << " "
           << matrix[ 1 ][ 0 ].toString ( ) << " "
           << matrix[ 0 ][ 1 ].toString ( ) << " "
           << matrix[ 1 ][ 1 ].toString ( );
        return ss.str ( );
    }

    Nyb nybGFMultiply ( const Nyb &n1, const Nyb &n2 ) {
        uint8_t a = n1.toUInt ( );
        uint8_t b = n2.toUInt ( );
        uint8_t p = 0x00;
        const uint8_t m = 0x13;

        for ( size_t i = 0; i < 4; i++ ) {
            // If the LSB of b is 1, add a to p
            if ( b & 0x01 ) p ^= a;
            // If the MSB of a is 1, a = shift a + mod
            if ( a & 0x08 ) {
                a = ( a << 1 ) ^ m;
            } else { /** else just do the shift */
                a <<= 1;
            }
            b >>= 1;
        }

        return Nyb ( p );
    }

    Matrix matrixGFMultiply ( const Matrix &m1, const Matrix &m2 ) {
        Nyb n00 = nybGFMultiply ( m1[ 0 ][ 0 ], m2[ 0 ][ 0 ] )
                  ^ nybGFMultiply ( m1[ 0 ][ 1 ], m2[ 1 ][ 0 ] );

        Nyb n10 = nybGFMultiply ( m1[ 1 ][ 0 ], m2[ 0 ][ 0 ] )
                  ^ nybGFMultiply ( m1[ 1 ][ 1 ], m2[ 1 ][ 0 ] );

        Nyb n01 = nybGFMultiply ( m1[ 0 ][ 0 ], m2[ 0 ][ 1 ] )
                  ^ nybGFMultiply ( m1[ 0 ][ 1 ], m2[ 1 ][ 1 ] );

        Nyb n11 = nybGFMultiply ( m1[ 1 ][ 0 ], m2[ 0 ][ 1 ] )
                  ^ nybGFMultiply ( m1[ 1 ][ 1 ], m2[ 1 ][ 1 ] );

        return Matrix ( n00, n10, n01, n11 );
    }

}  // namespace U
