#ifndef SDES_H
#define SDES_H

#include <string>

#include "U.h"

namespace SDES {
    std::string s1Table ( const std::string &s1 );
    std::string s2Table ( const std::string &s2 );
    std::string sTable ( const std::string &s );
    std::string expand ( const std::string &x );
    std::string func ( const std::string &r, const std::string &k );
    std::string encrypt ( const std::string &p, const std::string &k );
    std::string decrypt ( const std::string &c, const std::string &k );
    void printOneRound ( const U::Op &op,
                         const std::string &text,
                         const std::string &key );

    void printTwoRounds ( const U::Op &op,
                          const std::string &text,
                          const std::string &key );

}  // namespace SDES

#endif  // S_DES_H
