#ifndef CBC_H
#define CBC_H
#include <string>

#include "U.h"

namespace CBC {
    void printCBC ( const std::string &t,
                    const std::string &k,
                    const std::string &i,
                    const U::Op &op );
}  // namespace CBC

#endif  // CBC_H
