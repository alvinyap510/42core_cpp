#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>

class AMateria;

class ICharacter
{
public:
    // Destructor
    virtual ~ICharacter() {}
    // Method: getName()
    virtual std::string const &getName() const = 0;
    // Method: equip a materia
    virtual void equip(AMateria *m) = 0;
    // Method: unequip a materia
    virtual void unequip(int idx) = 0;
    // Method: use a materia on someone
    virtual void use(int idx, ICharacter &target) = 0;
};

#endif