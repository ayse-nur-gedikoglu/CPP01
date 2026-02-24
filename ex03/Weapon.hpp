#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon{
    private:
        std::string type;
    public:
        Weapon(std::string type);
        const std::string& getType(void) const;
        // sondaki const methodun kendisinin const oldugunu gosterir.
        // Yani bu method icerideki degiskenleri degistirmez.
        void setType(std::string type);
};

#endif