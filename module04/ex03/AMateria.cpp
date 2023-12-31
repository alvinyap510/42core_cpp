#include "AMateria.hpp"

// Constructor: Arguments
AMateria::AMateria(std::string const &type)
{
    this->_type = type;
    std::cout << "Constructed Materia of type " << this->_type << std::endl;
}

// Constructor: Copy Construction
AMateria::AMateria(AMateria const &anotherAMateria)
{
    *this = anotherAMateria;
    std::cout << "Copy constructed Materia of type " << this->_type << std::endl;
}

// Overloading assignment operator "="
AMateria &AMateria::operator=(AMateria const &anotherAMateria)
{
    this->_type = anotherAMateria._type;
    std::cout << "Copy assigned Materia of type " << this->_type << std::endl;
    return *this;
}

// Destructor
AMateria::~AMateria()
{
    std::cout << "Destructing Materia of type "
              << this->_type
              << std::endl;
}

// Method: return type
std::string const &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* Applied unkndown Materia on "
              << target.getName() << " *"
              << std::endl;
}
