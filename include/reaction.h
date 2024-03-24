#ifndef CHEMISTRY_ENGINE_REACTION_H
#define CHEMISTRY_ENGINE_REACTION_H

#include <iostream>
#include "include/compound.h"

class Reaction {
    std::vector<Compound> reactants;
    std::vector<Compound> products;

public:
    Reaction();

    Reaction(const std::vector<Compound> &reactants, const std::vector<Compound> &products);

    ~Reaction();

    void displayReaction() const;

    std::vector<int> balanceReaction() const;

    int gcd(int x, int y) const;
};

#endif //CHEMISTRY_ENGINE_REACTION_H
