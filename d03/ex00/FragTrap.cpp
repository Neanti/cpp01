#include "FragTrap.hpp"

FragTrap::FragTrap(std::string n) : name(n){
    hp = 100;
    mhp = 100;
    ep = 100;
    mep = 100;
    lvl = 1;
    mdmg = 30;
    rdmg = 20;
    armor = 5;
    std::cout << "He is born !" << std::endl;
    return;
}

FragTrap::~FragTrap() {
    std::cout << "FR4G-TP " << name << " is dead !" << std::endl;
    return;
}

void FragTrap::meleeAttack(const std::string &target) {
    std::cout << "FR4G-TP " << name << " attacks " << target << " for " << mdmg <<  "DMG with a melee attack !" << std::endl;
    return;
}

void FragTrap::rangedAttack(const std::string &target) {
    std::cout << "FR4G-TP " << name << " attacks " << target << " for " << rdmg <<  "DMG with a ranged attack !" << std::endl;
    return;
}

void FragTrap::takeDamage(unsigned int amount) {
    if(amount + hp - armor < 0)
    {
        std::cout << "FR4G-TP " << name << " take nearly deadly " << amount - armor <<  "HP instead of" << amount << "HP thanks to his armor !" << std::endl;
        hp = 0;
    }
    else {
        std::cout << "FR4G-TP " << name << " take " << amount - armor << "HP instead of " << amount
                  << "HP thanks to his armor !" << std::endl;
        hp = hp + armor - amount;
    }
    return;
}

void FragTrap::beRepaired(unsigned int amount) {
    if ( amount > (unsigned int) (mhp - hp))
    {
        std::cout << "FR4G-TP " << name << " is healed for " <<
        mhp - hp <<  "HP instead of " << amount << "HP to full HP !" << std::endl;
        hp = mhp;
    }
    else
    {
        std::cout << "FR4G-TP " << name << " is healed for " <<
                  amount <<  "HP" << " to " << amount + hp <<"HP !" << std::endl;
        hp +=amount;
    }
    return;
}

void FragTrap::vaulthunter_dot_exe(const std::string &target) {
    int r,i;
    std::string atk;
    std::ifstream choose("specialAttacks.atk");

    if (ep < 25)
    {
        std::cout << "FR4G-TP " << name << " has only " << ep << "EP, he can not use his special attack !" << std::endl;
        return;
    }
    ep -= 25;
    i = 0;
    r = rand() % 5;
    while(i <= r) {
        getline(choose, atk);
        i++;
    }
        std::cout << "FR4G-TP " << name << " attacks " << target << " for 1000DMG with "<< atk << " !" << std::endl;
    choose.close();
}