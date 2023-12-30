#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
private:
    std::string ideas[100];

public:
    // Constructor: Default
    Brain();
    // Constructor: copy construction => construct as a copy of an existing object of same class
    Brain(Brain const &anotherBrain);
    // Overloading the "=" operator
    Brain &operator=(Brain const &anotherBrain);
    ~Brain();
    void setIdea(int index, std::string idea);
    std::string getIdea(int index) const;
};

#endif