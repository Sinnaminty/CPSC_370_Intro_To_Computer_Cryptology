#ifndef DCA_H
#define DCA_H

#include <utility>
#include <vector>

#include "U.h"

namespace DCA {
    U::Matrix differentialAttack (
        const std::vector< std::pair< U::Matrix, U::Matrix > > &pairs,
        const U::Matrix &targetDiff );

    std::vector< std::pair< U::Matrix, U::Matrix > > generatePlaintextPairs (
        const U::Matrix &base,
        const U::Matrix &diff,
        const size_t &numPairs );

    U::Matrix encryptToLastRound ( const U::Matrix &p, const U::Matrix &k );

    U::Matrix calculateDifference ( const U::Matrix &c1, const U::Matrix &c2 );

    std::vector< U::Matrix > getCiphertextDifferences (
        const std::vector< std::pair< U::Matrix, U::Matrix > > &pairs,
        const U::Matrix &key );

    U::Matrix findMostCommonDifference (
        const std::vector< U::Matrix > &diffs );

};  // namespace DCA

#endif  // DCA_H
