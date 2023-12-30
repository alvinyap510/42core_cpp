#include "WrongAnimal.hpp"

// Constructor: Default
WrongAnimal::WrongAnimal()
{
    this->type = "Wrong Animal";
    std::cout << "Constructed " << this->type << std::endl;
}

// Constructor: With Arguments
WrongAnimal::WrongAnimal(std::string wrongAnimal)
{
    this->type = wrongAnimal;
    std::cout << "Constructed " << this->type << std::endl;
}

// Constructor: copy construction => construct as a copy of an existing object of same class
WrongAnimal::WrongAnimal(WrongAnimal const &blueprint)
{
    *this = blueprint;
}

// Overloading the "=" operator
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &another)
{
    if (this != &another)
    {
        this->type = another.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destroyed " << this->type << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong animal generic sound" << std::endl;
}