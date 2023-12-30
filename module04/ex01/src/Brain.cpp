#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Created brain" << std::endl;
}

Brain::Brain(Brain const &anotherBrain)
{
    std::cout << "Created brain with copy constructor" << std::endl;
    *this = anotherBrain;
}

Brain &Brain::operator=(Brain const &anotherBrain)
{
    if (this != &anotherBrain)
    {
        std::cout << "Copy assigning with \"=\" " << std::endl;
        for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = anotherBrain.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destroyed brain" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
    // Guard Clause
    if (index < 0 || index >= 100)
    {
        std::cout << "Set idea index out of bound" << std::endl;
        return;
    }
    this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    // Guard Clause
    if (index < 0 || index >= 100)
    {
        std::cout << "Get idea index out of bound" << std::endl;
        return "";
    }
    return this->ideas[index];
}