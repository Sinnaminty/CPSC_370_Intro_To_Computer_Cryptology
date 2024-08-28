# Chapter 3-1 Classical Encryption Techniques 

| Table of Contents | Slide Number |
| ------- | ------- |
| | |


## Cryptography

Cryptographic systems are charactierized by:
- Type of operations used
  - substitution
  - transposition
  - product
- Number of keys used
  - single-key or private
  - two-key or public
- Way in which plaintext is processed
  - block
    - chunks of plaintext
  - stream

## Cryptanalysis
Recover the key and message
- Approaches
  - cryptanalytic attack
  - brute-force

## Cryptanalytic Attacks

Ciphertext only
- only know algo & Ciphertext

Known plaintext
- known plaintext & ciphertext

Chosen plaintext
- select plaintext and obtain ciphertext

## More Definitions
- Unconditionally secure
  - Impossible to break

- Computationally secure
  - Takes too long to break

## Brute Force Search
- Try everything!!!
- Proportional to keysize


# 3.2 Classical Substitution Ciphers

## 3.2.1 Shift Cipher (Aka Caesar Cipher)

a=0; b=1; etc..

C is Ciphertext
p is plaintext
k is key
E = Encryption algorithm
D = Decryption algorithm

For some key k, shift each letter by:
C = E(p) = (p+k)(mod 26)
p = D(C) = (C-k)(mod 26)

Ex:
p = meet me = 12 4 4 19 12 4
k = 3
C = E(p) = E(12 4 4 19 12 4) = (15 7 7 22 15 7) = PHHW PH

Ex2: 
p = party = 15 0 17 19 24
k = 3
C = E(p) = E(15 0 17 19 24) = (18 3 20 22 1) = SDUWB

Ex3:
p = theraininspain = 19 7 4 17 0 8 13 8 13 18 15 0 8 13 
k = 2
C = E(p) = E(19 7 4 17 0 8 13 8 13 18 15 0 8 13) = (21 9 6 19 2 10 15 10 15 20 17 2 10 15) = VJGTCKPKPURCKP

## Cryptanalysis of Shift Cipher
Only 26 possible Ciphers
Bad :c
TODO: Break ciphertext "GCUA VQ DTGCM"


## CryptAnalysis Attack

Ciphertext only
- Exhaustive Search
- Do a frequency count for letters

Known plaintext
- if you know just one letter of the plaintext, you can get teh key

Chosen plaintext
- Chose the letter "a" as the plaintext. If the ciphertext is "h", then the key is 7

Chosen ciphertext
- Chose the letter "A" as ciphertext. If the plaintext is "h", the key is -7

## 3.2.2 Affine Ciphers
Generalized and strengthened the shift ciphers
Chose two intgers alpha abd beta with gcd(alpha, 26) = 1
Consider the function C = (alpha * p + beta) mod 26

Ex: 
alpha = 9
beta = 2
p = h = 7
(9*7 + 2) mod 26 =

## Z_26

An element x of Z_\26 has an inverse in Z_\26 if there is an element y in Z_\26 such that xy === 1 mod 26

The key for affine encryption method is the pair of (, )

Ex: 
p = "if"
C = "PQ"

C = E(p) = (alpha * p + beta) mod 26 

15 = alpha * 8 + beta
16 = alpha * 5 + beta

-1 = 3 * alpha 
3 * alpha = -1
alpha = (1/3)(25)
alpha = (9)(25) = 17 mod 26
alpha = 17

16 = (17 * 5 + beta) mod 26
