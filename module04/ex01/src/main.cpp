#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "====== ANIMAL ARRAY ======" << std::endl;
    Animal *animalArray[10];

    std::cout << "====== OBJECT CONSTRUCTION ======" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            animalArray[i] = new Dog();
        else
            animalArray[i] = new Cat();
    }

    std::cout << "====== OBJECT DESTRUCTION ======" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        delete animalArray[i];
    }
    system("leaks ex01_polymorphism_brain");
}
