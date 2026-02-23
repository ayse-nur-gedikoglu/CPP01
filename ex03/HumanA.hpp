#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA{
    private:
        std::string _name;
        Weapon& _weapon; 
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack();
};

//humanA destructarda silahı alıyor. yani ref ile çalışıyor
//humanB almıyor yani pointer ile çalışıyor

#endif