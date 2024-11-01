#ifndef SAES_H
#define SAES_H

#include "U.h"

namespace SAES {
    void debug ( );
    void keyGenDebug ( );
    U::Matrix applyCipher ( const U::Matrix &p,
                            const U::Matrix &k,
                            const U::Op &op );

    U::Matrix addRoundKey ( const U::Matrix &s, const U::Matrix &k );

    U::Matrix subMatrix ( const U::Matrix &s );

    U::Matrix shiftRows ( const U::Matrix &s );

    U::Matrix mixColumns ( const U::Matrix &s );

    U::Matrix computeKey ( const U::Matrix &k, const uint16_t &round );

    U::Word subWord ( const U::Word &w );

    U::Word rotateWord ( const U::Word &w );

    U::Nyb subNyb ( const U::Nyb &n );
};  // namespace SAES

#endif  // SAES_H
