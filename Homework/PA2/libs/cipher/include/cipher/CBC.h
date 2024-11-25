#ifndef CBC_H
#define CBC_H
#include <string>

#include "U.h"

namespace CBC {
    void printCBC ( const std::string &t,
                    const std::string &k,
                    const std::string &i,
                    const U::Op &op );

    void printCBC2 ( const std::string &p1,
                     const std::string &p2,
                     const std::string &k,
                     const std::string &i );
}  // namespace CBC

#endif  // CBC_H
