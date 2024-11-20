#ifndef SDES_H
#define SDES_H

#include <string>

namespace SDES {

    /**
     * @enum Op
     * @brief Represents the type of operation to be performed.
     */
    enum class Op {
        ENCRYPT, /**< Encryption operation */
        DECRYPT  /**< Decryption operation */
    };

    std::string logicalXor ( const std::string &a, const std::string &b );
    std::string s1Table ( const std::string &s1 );
    std::string s2Table ( const std::string &s2 );
    std::string sTable ( const std::string &s );
    std::string expand ( const std::string &x );
    std::string func ( const std::string &r, const std::string &k );
    void printOneRound ( const Op &op,
                         const std::string &text,
                         const std::string &key );

    void printTwoRounds ( const Op &op,
                          const std::string &text,
                          const std::string &key );

}  // namespace SDES

#endif  // S_DES_H
