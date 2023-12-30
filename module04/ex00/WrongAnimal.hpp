#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    // Constructor: Default
    WrongAnimal();
    // Constructor: With Arguments
    WrongAnimal(std::string animal);
    // Constructor: copy construction => construct as a copy of an existing object of same class
    WrongAnimal(WrongAnimal const &another);
    // Overloading the "=" operator
    WrongAnimal &operator=(WrongAnimal const &another);
    // Declaring destructor as virtual ensures that derived child classes' destructor works properly
    virtual ~WrongAnimal();
    // Virtual ensures that getType is correctly overriden in child classes, const make sures that this method does not modify members of the class
    std::string getType() const;
    void makeSound() const;
};

#endif