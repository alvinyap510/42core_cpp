#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    // Constructor: Default Without Arguments
    Cat();
    // Constructor: copy construction
    Cat(Cat const &anotherCat);
    // Overloading the "=" operator
    Cat &operator=(Cat const &anotherCat);
    void makeSound() const;
};

#endif