#include "include/cipher/SAES.h"

namespace SAES {
    Utility::CipherVector applyCipher ( const std::vector< int16_t > &p,
                                        const std::vector< int16_t > &k ) {}

    Utility::Matrix addRoundKey ( const Utility::Matrix &p,
                                  const Utility::Matrix &k ) {}
    Utility::Matrix subNibbles ( const Utility::Matrix &s ) {}
    Utility::Matrix shiftRows ( const Utility::Matrix &s ) {}
    Utility::Matrix mixColumns ( const Utility::Matrix &s ) {}
}  // namespace SAES
