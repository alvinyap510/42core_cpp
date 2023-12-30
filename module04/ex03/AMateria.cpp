#include "AMateria.hpp"

// Constructor: Arguments
AMateria::AMateria(std::string const &type)
{
    this->_type = type;
    std::cout << "Constructed AMateria of type " << this->_type << std::endl;
}

// Constructor: Copy Construction
AMateria::AMateria(AMateria const &anotherAMateria)
{
    *this = anotherAMateria;
    std::cout << "Copy constructed AMateria of type " << this->_type << std::endl;
}

// Overloading assignment operator "="
AMateria &AMateria::operator=(AMateria const &anotherAMateria)
{
    this->_type = anotherAMateria._type;
    std::cout << "Copy assigned AMateria of type " << this->_type << std::endl;
}

// Destructor
AMateria::~AMateria()
{
    std::cout << "Destructing AMateria of type"
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
    std::cout << "* Applied unkndown AMateria on "
              << target.getName() << " *"
              << std::endl;
}
