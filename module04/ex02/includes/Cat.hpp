#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain *brain_;

public:
    // Constructor: Default Without Arguments
    Cat();
    // Constructor: copy construction
    Cat(Cat const &anotherCat);
    // Overloading the "=" operator
    Cat &operator=(Cat const &anotherCat);
    // Create new implementation of destructor
    ~Cat();
    void makeSound() const;
    Brain *getBrain() const;
};

#endif