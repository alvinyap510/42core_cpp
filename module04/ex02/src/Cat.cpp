#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    this->brain_ = new Brain();
    for (int i = 0; i < 100; i++)
    {
        this->brain_->setIdea(i, "Cat idea " + std::to_string(i));
    }
}

Cat::Cat(Cat const &anotherCat) : AAnimal(anotherCat)
{
    if (anotherCat.brain_)
        this->brain_ = new Brain(*(anotherCat.brain_));
    else
    {
        this->brain_ = new Brain();
        for (int i = 0; i < 100; i++)
        {
            this->brain_->setIdea(i, "Cat idea " + std::to_string(i));
        }
    }
}

// Calls the base class's copy assignment operator
Cat &Cat::operator=(Cat const &anotherCat)
{
    if (this != &anotherCat)
    {
        std::cout << "Copy assigning " << this->type << " with \"=\"" << std::endl;
        AAnimal::operator=(anotherCat);
        *(this->brain_) = *(anotherCat.brain_);
    }
    return *this;
}

// Ensure brain is deleted upon destruction
Cat::~Cat()
{
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