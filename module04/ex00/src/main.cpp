#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Construct Objects
    std::cout << "====== OBJECT CONSTRUCTION ======" << std::endl;
    const Animal *animal = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    std::cout << std::endl;

    std::cout << "====== OBJECT METHODS ======" << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    dog->makeSound();
    cat->makeSound();
    animal->makeSound();
    std::cout << std::endl;

    std::cout << "====== CHECK POLYMORPHISM ======" << std::endl;
    dog->Animal::makeSound(); // Method of base class
    cat->Animal::makeSound(); // Method of base class
    std::cout << std::endl;

    std::cout << "====== WRONG INHERITENCE ======" << std::endl;
    const WrongAnimal *wrongAnimal = new WrongAnimal();
    const WrongAnimal *wrongCatA = new WrongCat();
    const WrongCat *wrongCatB = new WrongCat();
    std::cout << std::endl;

    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << wrongCatA->getType() << " " << std::endl;
    std::cout << wrongCatB->getType() << " " << std::endl;

    wrongAnimal->makeSound();
    wrongCatA->makeSound(); // Void wasnt used
    wrongCatB->makeSound();
    std::cout << std::endl;

    std::cout << "====== OBJECT DESTRUCTION ======" << std::endl;
    delete animal;
    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongCatA;
    delete wrongCatB;
}
