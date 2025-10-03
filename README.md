# Modern C++ Programming with TDD

This repository contains code and exercises following the book [*Modern C++ Programming with Test-Driven Development, Second Edition*](https://pragprog.com/titles/lotdd/modern-c-programming-with-test-driven-development/) by Jeff Langr.
It is intended as a reference for learners and  practitioners of modern C++ and TDD techniques.

[comment]: #cover
![Cover image](https://www.oreilly.com/covers/urn:orm:book:9781941222423/400w/)


## Requirements

- GCC 6.0 or above (or any modern C++ compiler)
- CMake 3.10 or above
- Google Test (gtest)

## Contents

- [Chapter 1. Introduction]
- [Chapter 2. Test-Driven Development: A First Example](./Chapter_02)
- [Chapter 3. Test-Driven Development Foundations](./Chapter_03)
- [Chapter 4. Test Construction](./Chapter_04)
- [Chapter 5. Test Doubles](./Chapter_05)
- [Chapter 6. Incremental Design](./Chapter_06)
- [Chapter 7. Quality Tests](./Chapter_07)
- [Chapter 8. Legacy Challenges](./Chapter_08)
- [Chapter 9. TDD and Threading](./Chapter_09)
- [Chapter 10. Additional TDD Concepts and Discussions](./Chapter_10)
- [Chapter 10.  Growing and Sustaining TDD](./Chapter_10)

## How to Build and Run Tests

1. Navigate to the desired version directory, e.g.:
   ```bash
   cd Chapter_02/Version_01
   ```
2. Create and enter a build directory:
   ```bash
   mkdir -p build && cd build
   ```
3. Run CMake and build:
   ```bash
   cmake .. && make
   ```
4. Run the tests:
   ```bash
   ./SoundexTest
   ```

## How to Use

- Browse each chapter’s folder for code and TDD steps.
- Each version demonstrates incremental development and refactoring.
- Code is written for clarity and learning, following modern C++ and TDD best practices.

## License

This repository is for educational purposes. All code is based on exercises from "Modern C++ Programming with Test-Driven Development" by Jeff Langr.

---

For questions or suggestions, feel free to open an issue or pull request.
