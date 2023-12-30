#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    // Constructor: Default Without Arguments
    Dog();
    // Constructor: copy construction
    Dog(Dog const &anotherDog);
    // Overloading the "=" operator
    Dog &operator=(Dog const &anotherDog);
    virtual void makeSound() const;
};

#endif