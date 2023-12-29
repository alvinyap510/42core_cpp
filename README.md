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

## Variables

### Strings

- Strings are handled differently in C vs C++

#### A. C-Style Strings

- An array of characters terminated by '\0'
- Strings are an array of char
- String functions: strcpy, strlen, strcmp etc
- Programmer is responsible for managing memory

#### B. C++ std::string

- Comes with the Standard Template Library
- Dynamic sizing
- Safe and convenient
- Member functions such as "append", "replace", "find", "substr" and overloads for operators like "+" for concatenation, "===" for comparisoms etc
- No need to worry about null termination

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

### Templates

- Feature to write generic, type-independant code
- Known as generic programming
- Primarily used for creating functions and classes that can operate with any data type

#### A. Function Template

- Define a function without specifying the exact data type of its parameters
- When the function is called, the compiler automatically generates a version of the function witht the appropriate data types

```C++
template <typename T>
T functionName(T parameter) {
    // Function body
}
```

```C++
template <typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    int i = max(3, 7);             // Instantiates max<int>(int, int)
    double d = max(6.34, 3.12);    // Instantiates max<double>(double, double)
}

```

- Explicit Template Arguments

```C++
double result = max<double>(1, 2.8);
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

#### B. Class Templates

- Similar to function templates, but they allow you to define a class that can work with any data type

```C++
template <typename T>
class ClassName {
    // Class body
};
```

```C++
template <typename T>
class Box {
public:
    Box(T value) : value_(value) {}

    T getValue() const { return value_; }
    void setValue(T value) { value_ = value; }

private:
    T value_;
};

int main() {
    Box<int> intBox(123);
    Box<double> doubleBox(3.14);
}

```

#### C. Template Specialization

- Define a specific implementation of a template for a particular data type
- The below example shows how to use Template Speciaization to delcare a function named max to handle input in generic types, and specifically diffrent implementation to handle C-style strings "const char \*"

```C++
template <>
const char* max<const char*>(const char* x, const char* y) {
    return strcmp(x, y) > 0 ? x : y;
}
```

```C++
#include <iostream>
#include <cstring>  // For strcmp

// Generic template for max
template<typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}

// Template specialization for const char*
template<>
const char* max<const char*>(const char* x, const char* y) {
    return (std::strcmp(x, y) > 0) ? x : y;
}

int main() {
    // Using max with int
    int i = max(3, 7);
    std::cout << "Max int: " << i << std::endl;

    // Using max with double
    double d = max(3.5, 2.5);
    std::cout << "Max double: " << d << std::endl;

    // Using max with const char*
    const char* s1 = "apple";
    const char* s2 = "orange";
    const char* sMax = max(s1, s2);
    std::cout << "Max string: " << sMax << std::endl;

    return 0;
}

```

### "auto" keyword

#### A. Type Inference

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

#### B. Trailing Return Type in Functions

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

```

```
