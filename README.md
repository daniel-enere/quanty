# Quanty: C++ Quant CLI & Engine

`quanty` is a modular, high-performance C++17 quant tool designed for option pricing and analytics. It features a standalone static library (`quant_engine`) for mathematical models, a command-line interface (CLI) for rapid calculations, and a robust CTest unit-testing suite.

---

## Features

- **Black-Scholes Pricing Model**: Calculates theoretical option prices and sensitivities (Greeks like Delta) for both European Calls and Puts.
- **Modular Architecture**: Clean separation between core quantitative engine logic (`quant_engine` static library) and user-facing utilities (`quanty` CLI).
- **Automated Unit Testing**: Integrated CTest suite verifying pricing accuracy and mathematical robustness against benchmark values.
- **Modern C++17**: Built using modern C++ standards, clean header/source separation, and standard build configurations.

---

## Project Structure

```text
quanty/
├── CMakeLists.txt         # Root CMake configuration
├── include/               # Public header files (.hpp)
│   ├── Option.hpp
│   └── BlackScholesPricer.hpp
├── src/                   # Implementation files (.cpp)
│   ├── Option.cpp
│   ├── BlackScholesPricer.cpp
│   └── main.cpp           # CLI entry point
├── tests/                 # Unit test suite
│   └── test_quant.cpp
└── .gitignore             # Git exclusion rules
