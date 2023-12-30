#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    // Constructor: Default Without Arguments
    WrongCat();
    // Constructor: copy construction
    WrongCat(WrongCat const &anotherWrongCat);
    // Overloading the "=" operator
    WrongCat &operator=(WrongCat const &anotherWrongCat);
    void makeSound() const;
};

#endif