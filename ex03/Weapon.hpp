#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include "HumanA.hpp"
# include "HumanB.hpp"

class Weapon{
    private:
        std::string type;
    public:
        Weapon(std::string type);
        const std::string& getType(void);
        void setType(std::string type);
};

#endif