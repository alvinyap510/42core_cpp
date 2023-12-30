#include "AAnimal.hpp"

// Constructor: Default
AAnimal::AAnimal()
{
    this->type = "Generic Animal";
    std::cout << "Constructed " << this->type << std::endl;
}

// Constructor: With Arguments
AAnimal::AAnimal(std::string animal)
{
    this->type = animal;
    std::cout << "Constructed " << this->type << std::endl;
}

// Constructor: copy construction => construct as a copy of an existing object of same class
AAnimal::AAnimal(AAnimal const &blueprint)
{
    *this = blueprint;
}

// Overloading the "=" operator
AAnimal &AAnimal::operator=(AAnimal const &another)
{
    std::cout << "Copy assigning " << this->type << std::endl;
    if (this != &another)
    {
        this->type = another.type;
    }
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Destroyed " << this->type << std::endl;
}

std::string AAnimal::getType(void) const
{
    return this->type;
}