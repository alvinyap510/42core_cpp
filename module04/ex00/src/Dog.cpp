#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::Dog(Dog const &anotherDog) : Animal(anotherDog)
{
}

// Calls the base class's copy assignment operator
Dog &Dog::operator=(Dog const &anotherDog)
{
    Animal::operator=(anotherDog);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof!!" << std::endl;
}