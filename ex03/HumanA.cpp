#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{

}

void HumanA::attack(void)
{

}

//referanslar sınıf oluşturulurken bağlanmak zorundadır, sonradan atama ile degistirilemezler
//bu yüzden bağlama constructor içinde yapılır