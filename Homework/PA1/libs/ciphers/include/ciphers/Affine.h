#ifndef AFFINE_H
#define AFFINE_H
#include <cstdint>
#include <vector>

#include "Utility.h"

namespace Affine {

    /**
     * @struct AffineFunction
     * @brief Represents the affine function \( f(x) = ax + b \), used in the
     * Affine cipher.
     */
    struct AffineFunction {
        int16_t
            m_a; /**< The multiplier coefficient 'a' in the affine function */
        int16_t m_b; /**< The shift coefficient 'b' in the affine function */

        /**
         * @brief Constructs an AffineFunction with given coefficients.
         * @param a The multiplier coefficient.
         * @param b The shift coefficient.
         */
        AffineFunction ( const int16_t &a, const int16_t &b );
    };

    /**
     * @brief Applies the affine cipher to a vector of int16_t values using the
     * given affine function.
     *
     * @param vec The input vector of int16_t values representing the plain text
     * or cipher text.
     * @param func The affine function \( f(x) = ax + b \) to apply to each
     * element in the vector.
     * @param opType The operation type (either ENCRYPT or DECRYPT).
     * @return Utility::CipherVector The result of applying the affine function,
     * either encrypted or decrypted text.
     */
    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const AffineFunction &func,
                                        const Utility::OpType &opType );

    /**
     * @brief Calculates the modular inverse of a number for use in affine
     * decryption.
     *
     * @param num The number to find the modular inverse for.
     * @return int16_t The modular inverse of the given number.
     */
    int16_t inverse ( const int16_t &num );

    /**
     * @brief Performs a brute-force search over all possible affine cipher
     * functions by iterating over different values of 'b'.
     *
     * @param vec The input vector of int16_t values representing the cipher
     * text.
     * @param func The affine function with a fixed 'a' value. The brute-force
     * process varies the 'b' value.
     * @return std::vector<Utility::CipherVector> A vector of CipherVectors
     * representing all possible decrypted results.
     */
    std::vector< Utility::CipherVector > bruteForceCipher (
        const std::vector< int16_t > &vec,
        const AffineFunction &func );

};  // namespace Affine

#endif  // AFFINE_H
