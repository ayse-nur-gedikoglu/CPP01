#include "Zombie.hpp"

//burada stackte bir zombie oluşturuyoruz
void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}
