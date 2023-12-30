#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    // Constructor: default
    Cure();
    // Constructor: Copy Construction
    Cure(Cure const &anotherCure);
    // Overloading assignment operator "="
    Cure &operator=(Cure const &anotherCure);
    // Destructor
    ~Cure();
    // Method: clone self and return a copy
    AMateria *clone() const;
    // Method: apply self on a character target
    void use(ICharacter &target);
};

#endif