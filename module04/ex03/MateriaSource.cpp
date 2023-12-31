#include "MateriaSource.hpp"

// Constructor: Default
MateriaSource::MateriaSource()
{
    std::cout << "Constructed MateriaSource" << std::endl;
    // Initialize all materia memory as NULL
    for (int i = 0; i < 4; i++)
    {
        this->materiaMemory[i] = NULL;
    }
}

// Constructor: Copy Construction
MateriaSource::MateriaSource(const MateriaSource &anotherMateriaSource)
{
    std::cout << "Constructed MateriaSource via copy constructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (anotherMateriaSource.materiaMemory[i])
            this->materiaMemory[i] = anotherMateriaSource.materiaMemory[i]->clone();
        else
            this->materiaMemory[i] = NULL;
    }
}

// Overloading assignment operator
MateriaSource &MateriaSource::operator=(const MateriaSource &anotherMateriaSource)
{
    std::cout << "Copy assigning MateriaSource via \"=\" operator" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->materiaMemory[i])
            delete this->materiaMemory[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if (anotherMateriaSource.materiaMemory[i])
            this->materiaMemory[i] = anotherMateriaSource.materiaMemory[i]->clone();
    }
    return (*this);
}

// Destructor: Delete AMateria if exist
MateriaSource::~MateriaSource()
{
    std::cout << "Destructing MateriaSource" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->materiaMemory[i])
            delete this->materiaMemory[i];
    }
}

// Method: Learn a new materia if there are empty slots available
void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->materiaMemory[i])
        {
            this->materiaMemory[i] = m;
            std::cout << "Learned new materia "
                      << m->getType()
                      << " at index "
                      << i
                      << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource memories are full" << std::endl;
    std::cout << "Failed to learn" << m->getType() << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materiaMemory[i]->getType() == type)
        {
            std::cout << "Created "
                      << type
                      << " from MateriaSource" << std::endl;
            return this->materiaMemory[i]->clone();
        }
    }
    std::cout << "Unknown type " << type << std::endl;
    std::cout << "Materia creation failed" << type << std::endl;
    return (0);
}
