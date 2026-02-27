# Modern C++ Programming with TDD

This repository contains code and exercises following the book [*Modern C++ Programming with Test-Driven Development, Second Edition*](https://pragprog.com/titles/lotdd/modern-c-programming-with-test-driven-development/) by Jeff Langr.
It is intended as a reference for learners and practitioners of modern C++ and TDD techniques.

[comment]: #cover
![Cover image](https://www.oreilly.com/covers/urn:orm:book:9781941222423/400w/)

## Requirements (without container)

If you prefer to build on your host machine directly:

- GCC 14+ or Clang 19+ (any modern C++ compiler)
- CMake 3.10+
- Google Test 1.15.2+ (gtest + gmock)
- Ninja (optional but recommended)


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
- [Chapter 11. Growing and Sustaining TDD](./Chapter_11)


## Dev Container

This repository includes a fully configured **Docker-based dev container** with all tools pre-installed. It is the recommended way to work with this project — no manual tool installation needed.

### Option 1 — VS Code Dev Container (Easiest)

Requires: [Docker](https://www.docker.com/) + [VS Code](https://code.visualstudio.com/) + [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)

1. Open the repository in VS Code
2. When prompted, click **"Reopen in Container"**
   *(or press `Ctrl+Shift+P` → "Dev Containers: Reopen in Container")*
3. VS Code will build the container and open the workspace inside it — all tools are ready

### Option 2 — Docker Compose (Manual)

```bash
# Run tje setEnv.sh script
./setEnv.sh

# Build and start the container
docker-compose up -d --build

# Attach a shell
docker exec -it dev-cpp-tdd bash
```


## How to Build and Run Tests

### Build All Chapters from Root

```bash
cmake -S . -B build_root
cmake --build build_root
```

### Build a Single Version in Isolation

Each `Version_*` directory is a self-contained CMake project:

```bash
cd Chapter_02/Version_01
cmake -S . -B build
cmake --build build
./build/Chapter_02_Version_01_Test
```

## License

This repository is for educational purposes. All code is based on exercises from "Modern C++ Programming with Test-Driven Development" by Jeff Langr.


For questions or suggestions, feel free to open an issue or pull request.
