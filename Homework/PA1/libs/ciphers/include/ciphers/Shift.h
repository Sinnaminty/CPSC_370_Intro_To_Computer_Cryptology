#ifndef SHIFT_H
#define SHIFT_H
#include "Utility.h"

namespace Shift {

    /**
     * @brief Applies the shift cipher (also known as Caesar cipher) to a vector
     * of int16_t values using the given key.
     *
     * @param vec The input vector of int16_t values representing the plain text
     * or cipher text.
     * @param key The shift value to apply to each element in the vector.
     * @param opType The operation type (either ENCRYPT or DECRYPT).
     * @return Utility::CipherVector The result of applying the shift, either
     * encrypted or decrypted text.
     */
    Utility::CipherVector applyCipher ( const std::vector< int16_t > &vec,
                                        const int16_t &key,
                                        const Utility::OpType &opType );

    /**
     * @brief Analyzes the frequency of characters in the input vector,
     * returning the frequency count in a CipherVector.
     *
     * @param vec The input vector of int16_t values representing the text.
     * @return Utility::CipherVector A CipherVector containing the frequency of
     * each character in the input text.
     */
    Utility::CipherVector applyFrequencyCount (
        const std::vector< int16_t > &vec );

}  // namespace Shift

#endif  // SHIFT_H
