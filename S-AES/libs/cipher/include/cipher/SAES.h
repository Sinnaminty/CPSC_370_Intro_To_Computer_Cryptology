#ifndef SAES_H
#define SAES_H

#include "U.h"

namespace SAES {
    U::Matrix applyCipher ( const U::Matrix &p,
                            const U::Matrix &k,
                            const U::Op &op );

    U::Matrix addRoundKey ( const U::Matrix &s, const U::Matrix &k );

    U::Matrix computeKey ( const U::Matrix &k, const uint16_t &round );

    U::Word rotateWord ( const U::Word &w );

    ///////////
    /// ENCRYPT
    ///////////

    U::Matrix subMatrix ( const U::Matrix &s );
    U::Word subWord ( const U::Word &w );
    U::Nyb subNyb ( const U::Nyb &n );

    U::Matrix shiftRows ( const U::Matrix &s );

    U::Matrix mixColumns ( const U::Matrix &s );

    ///////////
    /// DECRYPT
    ///////////

    U::Matrix invSubMatrix ( const U::Matrix &s );
    U::Word invSubWord ( const U::Word &w );
    U::Nyb invSubNyb ( const U::Nyb &n );

    U::Matrix invMixColumns ( const U::Matrix &s );
};  // namespace SAES

#endif  // SAES_H
