# S-AES & Differential Cryptanalysis

> Final project for my CPSC 370 : Introduction to Cryptology class

---

## Assignment
1. Create software that can encrypt and decrypt using S-AES. Test data: A binary plaintext of 0110 1111 0110 1011 encrypted with a binary key of 1010 0111 0011 1011 should give a binary ciphertext of 0000 0111 0011 1000. Decryption should work correspondingly. 

2. ~~Implement a differential cryptanalysis attack on 1-round S-AES.~~
2. Implement a Brute Force attack on 2-round S-AES.

---

## Building the Project 
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

---

## Usage
```bash
    ./app -p <plaintext> -c <ciphertext> -k <key matrix> --<encrypt/decrypt> --bruteForce
```
Options:
        -p, --plaintext  <value>  Plaintext input matrix
        -c, --ciphertext <value>  Ciphertext input matrix
        -k, --key        <value>  Key matrix
        --encrypt                 Perform encryption (requires -p and -k)
        --decrypt                 Perform decryption (requires -c and -k)
        --bruteForce              Perform brute force (requires any two of -p, -c, -k)
---

###### Powered by caffeine and lambda functions.
