#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
    AMateria *inventory_[4];
    std::string name_;

public:
    // Constructor: with argument
    Character(std::string name);
    // Constructor: Copy Construction
    Character(Character const &anotherCharacter);
    // Overloading assignment operator "="
    Character &operator=(Character const &anotherCharacter);
    // Destructor
    ~Character();
    // Method: getName()
    std::string const &getName() const;
    // Method: equip a materia
    void equip(AMateria *m);
    // Method: unequip a materia
    void unequip(int idx);
    // Method: use a materia on someone
    void use(int idx, ICharacter &target);
};

#endif