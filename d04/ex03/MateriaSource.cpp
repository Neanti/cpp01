#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *m) {
    if (m == 0 || n > 3)
        return;
    int i;

    i = 0;
    while(i < 4)
    {
        if (list[i] == 0) {
            list[i] = m->clone();
            n++;
            return;
        }
        i++;
    }
    return;
}

AMateria * MateriaSource::createMateria(const std::string &type) {
    if (n == 0)
        return 0;
    int i;

    i = 0;
    while(i < 4)
    {
        if (list[i]->getType() == type)
            return list[i]->clone();
        i++;
    }
    return 0;
}

MateriaSource::~MateriaSource() {
    int i = 0;

    while(i < 4)
    {
        if (list[i] != 0)
            delete list[i];
        i++;
    }
    return;
}

MateriaSource::MateriaSource() {
    int i;

    i = 0;
    while(i < 4)
        list[i++] = 0;
    return;
}
