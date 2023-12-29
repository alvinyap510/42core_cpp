# 42Core_CPP

## Introduction

## Requirements

### 1. Compiler

### To use C++98 Standard

- C++ standards are set by the International Organization for Standardization (ISO), by the ISO/IEC JTC1/SC22/WG21 committee
- Defines syntax, semantics and the standard library
- C++98 is the first official standard of C++ in year 1998, hence the name
- Other C++ Standards:
  - C++03: bug fixing of C++98
  - C++11: significant update, ofthen known as "Modern C++". Introduced features like lambda expressions, auto keyword, nullptr, strong type checking, concurrency support etc
  -

## Syntax

### Namespace

### Try-Catch

- C++ 98 Standard

```C++
#include <iostream>
using namespace std;

int main() {
    try {
        // Code that may throw an exception
        throw "Some error occurred";
    }
    catch (const char* msg) {
        // Code to handle the exception
        cout << "Exception caught: " << msg << endl;
    }

    return 0;
}

```

- Modern C++ Standard

```C++
#include <iostream>
#include <stdexcept>  // for std::runtime_error

int main() {
    try {
        // Code that may throw an exception
        throw std::runtime_error("An error occurred");
    }
    catch (const std::runtime_error& e) {
        // Specific catch for std::runtime_error
        std::cout << "Runtime error caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        // General catch for all exceptions derived from std::exception
        std::cout << "Standard exception caught: " << e.what() << std::endl;
    }
    catch (...) {
        // Catch-all handler for any other exceptions
        std::cout << "Unknown exception caught" << std::endl;
    }

    return 0;
}

```
