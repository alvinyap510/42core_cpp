#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    // Constructor: Default
    Animal();
    // Constructor: With Arguments
    Animal(std::string animal);
    // Constructor: copy construction => construct as a copy of an existing object of same class
    Animal(Animal const &another);
    // Overloading the "=" operator
    Animal &operator=(Animal const &another);
    // Declaring destructor as virtual ensures that derived child classes' destructor works properly
    virtual ~Animal();
    // Virtual ensures that getType is correctly overriden in child classes, const make sures that this method does not modify members of the class
    virtual std::string getType() const;
    virtual void makeSound() const;
};

#endif