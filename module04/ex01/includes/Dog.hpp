#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *brain_;

public:
    // Constructor: Default Without Arguments
    Dog();
    // Constructor: copy construction
    Dog(Dog const &anotherDog);
    // Overloading the "=" operator
    Dog &operator=(Dog const &anotherDog);
    // Create new implementation of destructor
    ~Dog();
    void makeSound() const;
    Brain *getBrain() const;
};

#endif