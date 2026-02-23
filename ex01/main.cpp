#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    int N = 5;
    std::string name = "Bla bla bla";

    std::cout << "Creating a horde of " << N << " zombies..." << std::endl;
    Zombie* horde = zombieHorde(N, name);
    if (horde == NULL) 
    {
        std::cerr << "Failed to create horde" << std::endl;
        return (1);
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << i + 1 << ": ";
        horde[i].announce();
    }
    std::cout << "Destroying the horde..." << std::endl;
    delete[] horde;
    return 0;
}