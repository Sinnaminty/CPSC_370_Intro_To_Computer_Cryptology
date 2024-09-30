#include "include/ciphers/Utility.h"

#include <cstdint>
#include <numeric>
#include <ranges>
namespace Utility {
    CipherVector::CipherVector ( const std::vector< int16_t > &vec,
                                 const OpType &opType )
        : m_vec ( vec )
        , m_opType ( opType ) {}

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
        switch ( vec.m_opType ) {
            case OpType::ENCRYPT: {
                return std::accumulate (
                    vec.m_vec.begin ( ),
                    vec.m_vec.end ( ),
                    std::string { },
                    [] ( const std::string &acc, const int16_t &num ) {
                        return acc + char ( num + 'A' );
                    } );
            }

            case OpType::DECRYPT: {
                return std::accumulate (
                    vec.m_vec.begin ( ),
                    vec.m_vec.end ( ),
                    std::string { },
                    [] ( const std::string &acc, const int16_t &num ) {
                        return acc + char ( num + 'a' );
                    } );
            }
            case OpType::FREQUENCY: {
                auto frequencyStrings
                    = std::views::iota ( 0, 26 )
                      | std::views::transform ( [ &vec ] ( const int &index ) {
                            if ( vec.m_vec[ index ] > 0 ) {
                                return std::string (
                                           1,
                                           static_cast< char > ( 'a' + index ) )
                                       + "->"
                                       + std::to_string ( vec.m_vec[ index ] )
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
