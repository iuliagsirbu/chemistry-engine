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

    std::string getName() const;

    std::vector<Element> getElements() const;

    Compound(const Compound &other);

    Compound &operator=(const Compound &other);

    friend std::istream &operator>>(std::istream &in, Compound &comp);

    friend std::ostream &operator<<(std::ostream &out, const Compound &comp);

    double calculateMass() const;

    std::string calculateFormula() const;

    std::vector<int> atomsNumber() const;
};

#endif //CHEMISTRY_ENGINE_COMPOUND_H
