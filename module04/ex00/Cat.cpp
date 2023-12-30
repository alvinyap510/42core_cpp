#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
}

Cat::Cat(Cat const &anotherCat) : Animal(anotherCat)
{
}

// Calls the base class's copy assignment operator
Cat &Cat::operator=(Cat const &anotherCat)
{
    Animal::operator=(anotherCat);
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow!!" << std::endl;
}