#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>

class AAnimal
{
protected:
    std::string type;

public:
    // Constructor: Default
    AAnimal();
    // Constructor: With Arguments
    AAnimal(std::string AAnimal);
    // Constructor: copy construction => construct as a copy of an existing object of same class
    AAnimal(AAnimal const &another);
    // Overloading the "=" operator
    AAnimal &operator=(AAnimal const &another);
    // Declaring destructor as virtual ensures that derived child classes' destructor works properly
    virtual ~AAnimal();
    // Virtual ensures that getType is correctly overriden in child classes, const make sures that this method does not modify members of the class
    virtual std::string getType() const;
    virtual void makeSound() const = 0;
};

#endif