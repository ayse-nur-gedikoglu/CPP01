#include "HumanB.hpp"
#include <iostream>

//Member initializer list ile baslatıldı
HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL)
{
}
//Bu yöntem daha verimli çünkü bu şekilde _name direkt olarak olusturuluyor.
//Verimsiz yöntemde bir str oluşturuluyor ve buna atanıyor, fazladan hafıza kullanımı.

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack()
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon" << std::endl;
}