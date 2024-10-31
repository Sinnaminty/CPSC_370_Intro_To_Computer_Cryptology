#ifndef SAES_H
#define SAES_H

#include "U.h"

namespace SAES {
    U::Matrix applyCipher ( const U::Matrix &p,
                            const U::Matrix &k,
                            const U::Op &op );

    void addRoundKey ( U::Matrix &s, const U::Matrix &k );

    void subNibbles ( U::Matrix &s );

    void shiftRows ( U::Matrix &s );

    void mixColumns ( U::Matrix &s );

    U::Matrix computeKey ( const U::Matrix &k, const uint16_t &round );

};  // namespace SAES

#endif  // SAES_H
