#include "cipher/DCA.h"

#include <map>

#include "cipher/SAES.h"
#include "cipher/U.h"
namespace DCA {
    using namespace U;

    Matrix differentialAttack (
        const std::vector< std::pair< Matrix, Matrix > > &pairs,
        const Matrix &targetDiff ) {
        for ( Matrix keyGuess = 0; keyGuess < 0xFFFF;
              keyGuess++ ) {  // 16-bit key space
            bool match = true;
            for ( const auto &pair : pairs ) {
                Matrix c1 = encryptToLastRound ( pair.first, keyGuess );
                Matrix c2 = encryptToLastRound ( pair.second, keyGuess );
                Matrix diff = calculateDifference ( c1, c2 );

                if ( diff != targetDiff ) {
                    match = false;
                    break;
                }
            }
            if ( match ) {
                return keyGuess;  // Candidate key found
            }
        }
        return 0xFFFF;  // No valid key found
    }

    std::vector< std::pair< Matrix, Matrix > > generatePlaintextPairs (
        const U::Matrix &base,
        const U::Matrix &diff,
        const size_t &numPairs ) {
        std::vector< std::pair< Matrix, Matrix > > pairs;
        for ( int i = 0; i < numPairs; ++i ) {
            Matrix p1 = base + i;   // Slightly vary base for each pair
            Matrix p2 = p1 ^ diff;  // Apply the difference to create P2
            pairs.emplace_back ( p1, p2 );
        }
        return pairs;
    }

    Matrix encryptToLastRound ( const Matrix &p, const Matrix &k ) {
        const Matrix k1 = SAES::computeKey ( k, 1 );

        const Matrix s = SAES::addRoundKey ( p, k );

        // Round 1
        const Matrix r1 = SAES::addRoundKey (
            SAES::mixColumns ( SAES::shiftRows ( SAES::subMatrix ( s ) ) ),
            k1 );

        // Round 2
        const Matrix r2 = SAES::shiftRows ( SAES::subMatrix ( r1 ) );

        return r2;
    }

    Matrix calculateDifference ( const Matrix &c1, const Matrix &c2 ) {
        return c1 ^ c2;
    }

    std::vector< Matrix > getCiphertextDifferences (
        const std::vector< std::pair< Matrix, Matrix > > &pairs,
        const Matrix &key ) {
        std::vector< Matrix > differences;
        for ( const auto &pair : pairs ) {
            Matrix c1 = encryptToLastRound ( pair.first, key );
            Matrix c2 = encryptToLastRound ( pair.second, key );
            differences.push_back ( calculateDifference ( c1, c2 ) );
        }
        return differences;
    }

    Matrix findMostCommonDifference (
        const std::vector< Matrix > &differences ) {
        std::map< Matrix, int > frequency;
        for ( Matrix diff : differences ) { frequency[ diff ]++; }

        Matrix mostCommonDiff = 0;
        int maxCount = 0;
        for ( const auto &[ diff, count ] : frequency ) {
            if ( count > maxCount ) {
                maxCount = count;
                mostCommonDiff = diff;
            }
        }
        return mostCommonDiff;
    }

}  // namespace DCA
