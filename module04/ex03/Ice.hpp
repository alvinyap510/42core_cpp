#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    // Constructor: default
    Ice();
    // Constructor: Copy Construction
    Ice(Ice const &anotherIce);
    // Method: clone self and return a copy
    AMateria *clone() const;
    // Method: apply self on a character target
    void use(ICharacter &target);
};

#endif