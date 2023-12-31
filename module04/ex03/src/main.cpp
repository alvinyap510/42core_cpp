#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "====== MATERIA ======" << std::endl;
    IMateriaSource *src = new MateriaSource();
    std::cout << std::endl;
    src->learnMateria(new Ice());
    std::cout << std::endl;
    src->learnMateria(new Cure());
    std::cout << std::endl;

    std::cout << "====== COPY CONSTRUCTING MATERIA ======" << std::endl;
    std::cout << std::endl;
    src->learnMateria(src->createMateria("ice"));
    std::cout << std::endl;
    src->learnMateria(src->createMateria("cure"));
    std::cout << std::endl;
    // src->learnMateria(src->createMateria("cure")); // Demonstrate memory full
    // std::cout << std::endl;

    std::cout << "====== CHARACTERS ======" << std::endl;
    ICharacter *me = new Character("me");
    std::cout << std::endl;
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;
    // tmp = src->createMateria("ice"); // Demonstrate inventory full
    // me->equip(tmp);
    // std::cout << std::endl;
    ICharacter *bob = new Character("bob");
    std::cout << std::endl;
    me->use(0, *bob);
    std::cout << std::endl;
    me->use(1, *bob);
    std::cout << std::endl;

    std::cout << "====== DELETION ======" << std::endl;
    std::cout << std::endl;
    delete bob;
    std::cout << std::endl;
    delete me;
    std::cout << std::endl;
    delete src;
    std::cout << std::endl;

    system("leaks ex03_interface_game");
    return 0;
}