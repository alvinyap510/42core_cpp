#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
protected:
    AMateria *materiaMemory[4];

public:
    // Constructor: default
    MateriaSource();
    // Constructor: Copy Construction
    MateriaSource(const MateriaSource &anotherMateriaSource);
    // Overloading assignment operator "="
    MateriaSource &operator=(MateriaSource const &anotherMateriaSource);
    // Destructor
    ~MateriaSource();
    // Method: store an AMateria object object in materiaMemory
    void learnMateria(AMateria *m);
    // Method: return a copy of a learned materia
    AMateria *createMateria(std::string const &type);
};

#endif