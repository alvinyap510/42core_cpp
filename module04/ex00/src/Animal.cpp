#include "Animal.hpp"

// Constructor: Default
Animal::Animal()
{
    this->type = "Generic Animal";
    std::cout << "Constructed " << this->type << std::endl;
}

// Constructor: With Arguments
Animal::Animal(std::string animal)
{
    this->type = animal;
    std::cout << "Constructed " << this->type << std::endl;
}

// Constructor: copy construction => construct as a copy of an existing object of same class
Animal::Animal(Animal const &blueprint)
{
    *this = blueprint;
}

// Overloading the "=" operator
Animal &Animal::operator=(Animal const &another)
{
    if (this != &another)
    {
        this->type = another.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destroyed " << this->type << std::endl;
}

std::string Animal::getType(void) const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Animal generic sound" << std::endl;
}