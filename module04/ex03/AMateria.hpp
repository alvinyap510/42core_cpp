#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string _type;

public:
    // Constructor: with argument
    AMateria(std::string name);
    // Constructor: Copy Construction
    AMateria(std::string const &type);
    // Overloading assignment operator "="
    AMateria &operator=(AMateria const &anotherAMateria);
    // Destructor
    ~AMateria();
    // Method: getType
    std::string const &getType() const;
    // Method: clone self and return a copy
    virtual AMateria *clone() const = 0;
    // Method: apply self on a character target
    virtual void use(ICharacter &target);
};
#endif