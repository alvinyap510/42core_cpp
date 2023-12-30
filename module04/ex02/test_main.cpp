#include <iostream>
#include "Brain.hpp"
#include "Cat.hpp"

int main()
{
    // Brain *brain_a = new Brain();
    // Brain *brain_b = new Brain();

    // brain_a->setIdea(0, "Hello brain!");
    // std::cout << brain_a->getIdea(0) << std::endl;
    // *brain_b = *brain_a;
    // std::cout << brain_b->getIdea(0) << std::endl;
    // brain_a->setIdea(0, "Hello brain changed!");
    // std::cout << brain_a->getIdea(0) << std::endl;
    // std::cout << brain_b->getIdea(0) << std::endl;

    Cat *cat_a = new Cat();

    std::cout << cat_a->getType() << std::endl;
    std::cout << cat_a->getBrain()->getIdea(100) << std::endl;
    delete cat_a;
}