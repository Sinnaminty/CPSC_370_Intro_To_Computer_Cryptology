#ifndef U_H
#define U_H
#include <string>
namespace U {

    /**
     * @enum Op
     * @brief Represents the type of operation to be performed.
     */
    enum class Op {
        ENCRYPT, /**< Encryption operation */
        DECRYPT  /**< Decryption operation */
    };

    std::string logicalXor ( const std::string &a, const std::string &b );
}  // namespace U

#endif  // U_H
