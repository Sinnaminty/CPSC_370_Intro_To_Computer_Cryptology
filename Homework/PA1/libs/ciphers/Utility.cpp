#include "include/ciphers/Utility.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <numeric>
#include <ranges>
namespace Utility {
    /*
     * MATRIX
     */
    Matrix::Matrix ( const size_t &size ) {
        matrix.resize ( size, std::vector< int16_t > ( size, 23 ) );
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

    size_t Matrix::size ( ) const { return matrix.size ( ); }
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

}  // namespace Utility
