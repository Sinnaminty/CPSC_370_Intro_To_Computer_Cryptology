# Programming Assignment 2: S-DES & CBC Mode

> assigned in my CPSC 370 : Introduction to Computer Cryptology class.

---
## Assignment 
**Part I: S-DES:**
The purpose of this assignment is to implement an algorithm for encryption with the simplified DES algorithm.
- Item #1. Write a program that performs one round of the simplified DES algorithm learned in the class. Test your code with a plaintext P1 = 100010110101 and K = 111000111.
- Item #2. Write a program that performs two rounds of the simplified DES algorithm. Test your code with a plaintext P2 = 011100100110 and K = 111000111.

**Part II: CBC Mode**
Using the implementation of EK(M) from Part I, implement the CBC mode of operation for this simplified DES algorithm with 2 rounds.
- Item #3.  We have a plaintext message consisting of 24 bits and show how it encrypts and decrypts using CBC Mode. Test your program with plaintext P = P1P2, where P1 = 100010110101, P2 = 011100100110, K = 111000111, and IV = 111111111111. Ci = EK(Pi ^ Ci-1), EK: S-DES.
- Item #4. Suppose that you have two plaintexts that differ in the 14th bit. Show the effect that this has on the corresponding ciphertexts. Test your program with the same key and initial vector in the Item #3 and the two plaintexts are 
plaintext2 = "110011001100110011001100110011001100110011001100" and 
plaintext3 = "110011001100100011001100110011001100110011001100".

---
## Usage

Create the `build` directory and configure the build system:

```bash
cmake -S . -B build # Or `cmake -D BUILD_TESTING=OFF -B build` to skip tests. 
```

Build the project:
```bash
cmake --build build
```
Inspect the `build` directory to find the application and the tests.

Optionally, run the tests with `ctest` by typing:
```bash
cmake -E chdir build ctest
```
Much love, Sin
