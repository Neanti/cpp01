#include "PlasmaRifle.hpp"

void PlasmaRifle::attack() const {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
    return;
}

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21){
    return;
}

PlasmaRifle::~PlasmaRifle() {
    return;
}