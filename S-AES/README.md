# S-AES

> S-AES Implementation in C++ for my CPSC 370 : Introduction to Cryptology class.

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
