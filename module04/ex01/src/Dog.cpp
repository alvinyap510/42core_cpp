#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->brain_ = new Brain();
    for (int i = 0; i < 100; i++)
    {
        this->brain_->setIdea(i, "Dog idea " + std::to_string(i));
    }
}

Dog::Dog(Dog const &anotherDog) : Animal(anotherDog)
{
    if (anotherDog.brain_)
        this->brain_ = new Brain(*(anotherDog.brain_));
    else
    {
        this->brain_ = new Brain();
        for (int i = 0; i < 100; i++)
        {
            this->brain_->setIdea(i, "Dog idea " + std::to_string(i));
        }
    }
}

// Calls the base class's copy assignment operator
Dog &Dog::operator=(Dog const &anotherDog)
{
    if (this != &anotherDog)
    {
        std::cout << "Copy assigning " << this->type << " with \"=\"" << std::endl;
        Animal::operator=(anotherDog);
        *(this->brain_) = *(anotherDog.brain_);
    }
    return *this;
}

// Ensure brain is deleted upon destruction
Dog::~Dog()
{
    delete this->brain_;
}

void Dog::makeSound() const
{
    std::cout << "Woof!!" << std::endl;
}

Brain *Dog::getBrain() const
{
    return this->brain_;
}