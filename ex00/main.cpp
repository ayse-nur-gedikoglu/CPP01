#include "Zombie.hpp"

int main(void)
{
    Zombie* z = newZombie("Heap Zombie");
    z->announce();
    delete z;

    randomChump("Stack Zombie");

    return 0;
}