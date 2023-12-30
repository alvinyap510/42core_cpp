#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Cat")
{
}

WrongCat::WrongCat(WrongCat const &anotherWrongCat) : WrongAnimal(anotherWrongCat)
{
}

// Calls the base class's copy assignment operator
WrongCat &WrongCat::operator=(WrongCat const &anotherWrongCat)
{
    WrongAnimal::operator=(anotherWrongCat);
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Meow!!" << std::endl;
}