#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    // Constructor: default
    Ice();
    // Constructor: Copy Construction
    Ice(Ice const &anotherIce);
    // Overloading assignment operator "="
    Ice &operator=(Ice const &anotherIce);
    // Destructor
    ~Ice();
    // Method: clone self and return a copy
    AMateria *clone() const;
    // Method: apply self on a character target
    void use(ICharacter &target);
};

#endif