#include "include/ciphers/Utility.h"

#include <cstdint>
#include <numeric>
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
        return std::accumulate (
            vec.m_vec.begin ( ),
            vec.m_vec.end ( ),
            std::string { },
            [ &vec ] ( const std::string acc, const int16_t num ) {
                return vec.m_opType == OpType::ENCRYPT
                           ? acc + char ( num + 'A' )
                           : acc + char ( num + 'a' );
            } );
    }

    int16_t posMod ( const int16_t &num ) { return ( num % 26 + 26 ) % 26; }

}  // namespace Utility
