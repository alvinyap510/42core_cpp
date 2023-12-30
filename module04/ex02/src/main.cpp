#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // AAnimal *abstractAnimal = new AAnimal(); // Error cant compule as AAnimal is an abstract class
    AAnimal *cat = new Cat();
    AAnimal *dog = new Dog();

    cat->makeSound();
    dog->makeSound();
}
