#ifndef CHEMISTRY_ENGINE_COMPOUND_H
#define CHEMISTRY_ENGINE_COMPOUND_H

#include <iostream>
#include "include/element.h"

class Compound {
    std::string name;
    std::vector<Element> elements;

public:
    Compound();

    Compound(const std::string &name, const std::vector<Element> &elements);

    ~Compound();

    const std::string getName() const;

    std::vector<Element> getElements() const;

    double calculateMass() const;

    std::string calculateFormula() const;

    std::vector<int> atomsNumber() const;

    friend std::ostream &operator<<(std::ostream &out, Compound &comp);
};

#endif //CHEMISTRY_ENGINE_COMPOUND_H
