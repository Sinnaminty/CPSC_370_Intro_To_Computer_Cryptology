#ifndef SAES_H
#define SAES_H

#include <optional>
#include <vector>

#include "U.h"

namespace SAES {

    /**
     * @brief Applies the S-AES cipher to a plaintext matrix with a given key.
     * @param p The plaintext matrix to encrypt or decrypt.
     * @param k The key matrix to be used in the encryption or decryption
     * process.
     * @param op The operation type (ENCRYPT or DECRYPT).
     * @return The resulting matrix after applying the cipher.
     */
    U::Matrix applyCipher ( const U::Matrix &p,
                            const U::Matrix &k,
                            const U::Op &op );

    /**
     * @brief Performs an AddRoundKey operation by XORing the state matrix with
     * the round key.
     * @param s The state matrix.
     * @param k The round key matrix.
     * @return The matrix resulting from XORing the state and key matrices.
     */
    U::Matrix addRoundKey ( const U::Matrix &s, const U::Matrix &k );

    /**
     * @brief Computes the round key based on the initial key and round number.
     * @param k The initial key matrix.
     * @param round The round number to compute the key for.
     * @return The matrix representing the computed round key.
     */
    U::Matrix computeKey ( const U::Matrix &k, const uint16_t &round );

    /**
     * @brief Rotates the elements of a Word for key expansion.
     * @param w The word to rotate.
     * @return A new Word with its elements rotated.
     */
    U::Word rotateWord ( const U::Word &w );

    ///////////
    /// ENCRYPT
    ///////////

    /**
     * @brief Substitutes all Nybs in a matrix using the S-box.
     * @param s The state matrix.
     * @return The matrix after substitution.
     */
    U::Matrix subMatrix ( const U::Matrix &s );

    /**
     * @brief Substitutes all Nybs in a Word using the S-box.
     * @param w The word to substitute.
     * @return The word after substitution.
     */
    U::Word subWord ( const U::Word &w );

    /**
     * @brief Substitutes a single Nyb using the S-box.
     * @param n The Nyb to substitute.
     * @return The Nyb after substitution.
     */
    U::Nyb subNyb ( const U::Nyb &n );

    /**
     * @brief Performs the ShiftRows operation on a matrix, shifting the second
     * row.
     * @param s The state matrix.
     * @return The matrix after the row shift.
     */
    U::Matrix shiftRows ( const U::Matrix &s );

    /**
     * @brief Mixes the columns of the matrix to add diffusion in the encryption
     * process.
     * @param s The state matrix.
     * @return The matrix after the MixColumns operation.
     */
    U::Matrix mixColumns ( const U::Matrix &s );

    ///////////
    /// DECRYPT
    ///////////

    /**
     * @brief Inverse substitution for all Nybs in a matrix using the inverse
     * S-box.
     * @param s The state matrix.
     * @return The matrix after inverse substitution.
     */
    U::Matrix invSubMatrix ( const U::Matrix &s );

    /**
     * @brief Inverse substitution for all Nybs in a Word using the inverse
     * S-box.
     * @param w The word to substitute inversely.
     * @return The word after inverse substitution.
     */
    U::Word invSubWord ( const U::Word &w );

    /**
     * @brief Inverse substitution for a single Nyb using the inverse S-box.
     * @param n The Nyb to substitute inversely.
     * @return The Nyb after inverse substitution.
     */
    U::Nyb invSubNyb ( const U::Nyb &n );

    /**
     * @brief Inverse MixColumns operation for decryption.
     * @param s The state matrix.
     * @return The matrix after the inverse MixColumns operation.
     */
    U::Matrix invMixColumns ( const U::Matrix &s );

    /**
     * @brief Function to Brute Force S-AES.
     * @param p Plaintext Matrix.
     * @param k Key Matrix.
     * @return The possible keys.
     */
    std::vector< U::Matrix > bruteForce ( const U::Matrix &p,
                                          const U::Matrix &c );
};  // namespace SAES

#endif  // SAES_H
