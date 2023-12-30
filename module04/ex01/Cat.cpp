#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->brain_ = new Brain();
    for (int i = 0; i < 100; i++)
    {
        this->brain_->ideas[i] = "Cat idea " + std::to_string(i);
    }
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

Cat::~Cat()
{
    std::cout << "Destroyed " << this->type << std::endl;
    delete this->brain_;
}

void Cat::makeSound() const
{
    std::cout << "Meow!!" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->brain_;
}