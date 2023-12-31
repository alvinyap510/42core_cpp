#include "Character.hpp"

// Constructor: arguments
Character::Character(std::string name)
{
    this->name_ = name;
    std::cout << "Constructed character of name " << this->name_ << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->inventory_[i] = NULL;
    }
}

// Constructor: copy construction
Character::Character(const Character &anotherCharacter)
{
    std::cout << "Copy constructed character of name " << anotherCharacter.getName() << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->inventory_[i] = anotherCharacter.inventory_[i];
    }
}

// Overloading assignment operator
Character &Character::operator=(Character const &anotherCharacter)
{
    std::cout << "Copy assigning character of name " << anotherCharacter.getName() << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory_[i])
            delete this->inventory_[i];
        if (anotherCharacter.inventory_[i])
            this->inventory_[i] = anotherCharacter.inventory_[i]->clone();
    }
    return *this;
}

// Destructor: Delete inventory before destruction
Character::~Character()
{
    std::cout << "Destructing character of name " << this->name_ << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory_[i])
            delete this->inventory_[i];
    }
}

// Method: get name of character
std::string const &Character::getName(void) const
{
    return this->name_;
}

// Method: equip AMateria on character
void Character::equip(AMateria *m)
{
    // Guard clause
    if (!m)
    {
        std::cout << "Trying to equip invalid Materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory_[i])
        {
            this->inventory_[i] = m;
            std::cout << "Successfully equiped Materia of type "
                      << this->inventory_[i]->getType()
                      << " at index "
                      << i
                      << std::endl;
            return;
        }
    }
    std::cout << this->name_
              << "'s Inventory full. Failed to equip Materia of type "
              << m->getType()
              << std::endl;
}

// Method: remove an AMateria from character
void Character::unequip(int idx)
{
    // Guard clause
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index to unequip" << std::endl;
        return;
    }

    // If inventory exists
    if (this->inventory_[idx])
    {
        std::cout << "Successfully removed Materia of type "
                  << this->inventory_[idx]->getType()
                  << "at index "
                  << idx
                  << std::endl;
        this->inventory_[idx] = NULL;
        return;
    }
    else
        std::cout << "AMateria was not equiped on index " << idx << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    // Guard clause
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index to use" << std::endl;
        return;
    }

    if (this->inventory_[idx])
    {
        std::cout << this->name_
                  << " is trying to use "
                  << this->inventory_[idx]->getType()
                  << " on "
                  << target.getName()
                  << std::endl;
        this->inventory_[idx]->use(target);
    }
    else
        std::cout << "Inventory at index "
                  << idx
                  << " is empty"
                  << std::endl;
}