#ifndef DCA_H
#define DCA_H

#include <utility>
#include <vector>

#include "U.h"

namespace DCA {
    U::Matrix genRandomMatrix ( );

    U::Matrix createDifference ( const U::Matrix &s, const U::Nyb &diff );

    U::Matrix calcDifference ( const U::Matrix &a, const U::Matrix &b );

    U::Matrix secretEncrypt ( const U::Matrix &p );

    std::array< std::array< U::Nyb, 16 >, 16 > genDifferenceDistributionTable (
        const U::Matrix &p );

};  // namespace DCA

#endif  // DCA_H
