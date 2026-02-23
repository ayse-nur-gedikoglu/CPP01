#include "Zombie.hpp"

//heapte bir zombie oluşturup adresini döndürüyoruz
Zombie* newZombie(std::string name)
{
    Zombie* zombie = new Zombie(name);
    return zombie;
}