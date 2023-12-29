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
  - C++14: Incremental update on top of C++11, adding features like return type deduction, binary literals, improved cinstexpr support, and various library improvement
  - C++17: Introduced features like structured bindings, if constexpr, inline variables, and several new library components
  - C++20: A major update introducing concepts, coroutines, ranges, calendar, and timezone library, feature test macros etc.

## Syntax

### Namespace

- Used to organize code into logical groups and to prevent name collisions between libraries
- Similar idea to JavaScript modules
- Declaring a namespace

```C++

namespace MyNamespace {
    void myFunction() {
        // Do something
    }
}

int main() {
    // Call the function using the namespace
    MyNamespace::myFunction();

    return 0;
}

```

- "using" directive to avoid writing the namespace

```C++
using namespace MyNamespace;

int main() {
    // Directly call the function without the namespace prefix
    myFunction();
    return 0;
}

```

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

### "auto" keyword

- Modern C++ (not available in C++98)
- Tell the compiler to automatically deduce the type of variable from its initilizer

```C++
auto x = 5;                 // x is int
auto y = 3.14;              // y is double
auto ptr = &x;              // ptr is int*
auto lambda = []{ return 1; }; // lambda is a lambda function type

std::vector<int> vec;
auto iter = vec.begin();    // iter is std::vector<int>::iterator

```

### Lambda Expressions

- Modern C++ (not available in C++98)
- Inline, anonymous functions
- Example:

```C++
int x = 4;
auto addX = [x](int y) { return x + y; };
std::cout << addX(3);  // Output: 7

```

```C++
auto divide = [](double a, double b) -> double {
    if(b == 0) return 0;
    return a / b;
};
std::cout << divide(10, 2);  // Output: 5

```

- Explaination

  - [] What variables from the enclosing scope is available inside the lambda

    - [x] by value
    - [&x] by reference
    - [=, &x] or [&, x] capture both value and reference

  - () parameters
  - -> return type
  - {} function body
