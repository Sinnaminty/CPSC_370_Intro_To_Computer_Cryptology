#include "include/ciphers/Utility.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <numeric>
#include <ranges>

namespace Utility {
    /*
     * MATRIX
     */
    Matrix::Matrix ( const size_t &height, const size_t &width ) {
        matrix.resize ( height, std::vector< int16_t > ( width, 0 ) );
    }
    Matrix::Matrix ( const std::vector< int16_t > &vec, const size_t &width ) {
        size_t n = ( vec.size ( ) + width - 1 ) / width;

        matrix.resize ( n, std::vector< int16_t > ( width, 23 ) );
        for ( size_t i = 0; i < vec.size ( ); ++i ) {
            size_t row = i / width;
            size_t col = i % width;
            matrix[ row ][ col ] = vec[ i ];
        }
    }
    Matrix::Matrix ( const std::vector< std::vector< int16_t > > &mat ) {
        matrix = mat;
    }

    std::vector< int16_t > &Matrix::operator[] ( const size_t &index ) {
        return matrix[ index ];
    }
    const std::vector< int16_t > &Matrix::operator[] (
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

    size_t Matrix::height ( ) const { return matrix.size ( ); }
    size_t Matrix::width ( ) const { return matrix[ 0 ].size ( ); }
    size_t Matrix::n ( ) const {
        assert ( height ( ) == width ( ) && "Matrix is not square!" );
        return height ( );
    }

    /*
     * CIPHERVECTOR
     */
    CipherVector::CipherVector ( const std::vector< int16_t > &vec,
                                 const OpType &opType )
        : cipherVector ( vec )
        , opType ( opType ) {}
    CipherVector::CipherVector ( const Matrix &matrix, const OpType &opType )
        : opType ( opType ) {
        std::for_each ( matrix.begin ( ),
                        matrix.end ( ),
                        [ & ] ( const std::vector< int16_t > &row ) {
                            cipherVector.insert ( cipherVector.end ( ),
                                                  row.begin ( ),
                                                  row.end ( ) );
                        } );
    }

    int16_t &CipherVector::operator[] ( const size_t &index ) {
        return cipherVector[ index ];
    }
    const int16_t &CipherVector::operator[] ( const size_t &index ) const {
        return cipherVector[ index ];
    }

    CipherVector::Data::iterator CipherVector::begin ( ) {
        return cipherVector.begin ( );
    }
    CipherVector::Data::iterator CipherVector::end ( ) {
        return cipherVector.end ( );
    }

    CipherVector::Data::const_iterator CipherVector::begin ( ) const {
        return cipherVector.begin ( );
    }
    CipherVector::Data::const_iterator CipherVector::end ( ) const {
        return cipherVector.end ( );
    }

    /*
     * UTILITY FUNCTIONS
     */
    std::vector< int16_t > toNumVector ( const std::string &text ) {
        return std::accumulate (
            text.begin ( ),
            text.end ( ),
            std::vector< int16_t > { },
            [] ( std::vector< int16_t > acc, const char &c ) {
                acc.push_back (
                    ( static_cast< int16_t > ( tolower ( c ) - 'a' ) ) );
                return acc;
            } );
    }

    std::string toString ( const CipherVector &vec ) {
        switch ( vec.opType ) {
            case OpType::ENCRYPT: {
                return std::accumulate (
                    vec.begin ( ),
                    vec.end ( ),
                    std::string { },
                    [] ( const std::string &acc, const int16_t &num ) {
                        return acc + char ( num + 'A' );
                    } );
            }

            case OpType::DECRYPT: {
                return std::accumulate (
                    vec.begin ( ),
                    vec.end ( ),
                    std::string { },
                    [] ( const std::string &acc, const int16_t &num ) {
                        return acc + char ( num + 'a' );
                    } );
            }
            case OpType::FREQUENCY: {
                auto frequencyStrings
                    = std::views::iota ( 0, 26 )
                      | std::views::transform ( [ &vec ] ( const int &index ) {
                            if ( vec[ index ] > 0 ) {
                                return std::string (
                                           1,
                                           static_cast< char > ( 'a' + index ) )
                                       + "->" + std::to_string ( vec[ index ] )
                                       + "\n";
                            }
                            return std::string { };
                        } );

                return std::accumulate ( frequencyStrings.begin ( ),
                                         frequencyStrings.end ( ),
                                         std::string { } );
            }
            default: return std::string { };
        }
    }

    int16_t posMod ( const int16_t &num ) { return ( num % 26 + 26 ) % 26; }

    int16_t posModInverse ( const int16_t &num ) {}

    Utility::Matrix mulMatrix ( const Utility::Matrix &a,
                                const Utility::Matrix &b ) {
        assert ( a.height ( ) == b.width ( )
                 && "Matricies cannot be multiplied!" );
        Utility::Matrix retMat ( a.height ( ), b.width ( ) );
        for ( size_t i = 0; i < a.height ( ); i++ ) {
            for ( size_t j = 0; j < b.width ( ); j++ ) {
                for ( size_t k = 0; k < b.height ( ); k++ ) {
                    retMat[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];
                }
            }
        }
        return ( posModMatrix ( retMat ) );
    }

    Utility::Matrix posModMatrix ( const Utility::Matrix &mat ) {
        Utility::Matrix retMat ( mat );
        for ( std::vector< int16_t > &row : retMat ) {
            for ( int16_t &num : row ) { num = Utility::posMod ( num ); }
        }
        return retMat;
    }

    int16_t determinant ( const Utility::Matrix &mat ) {}

    Utility::Matrix getMinorMatrix ( const Utility::Matrix &mat,
                                     const size_t &row,
                                     const size_t &col ) {}

    Utility::Matrix cofactorMatrix ( const Utility::Matrix &mat ) {}

    Utility::Matrix transposeMatrix ( const Utility::Matrix &mat ) {}

    Utility::Matrix inverseMatrix ( const Utility::Matrix &mat ) {}
}  // namespace Utility
