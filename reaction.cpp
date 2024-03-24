#include "reaction.h"

Reaction::Reaction() = default;

Reaction::Reaction(const std::vector<Compound> &reactants, const std::vector<Compound> &products) : reactants(
        reactants), products(products) {}

Reaction::~Reaction() = default;

std::vector<int> Reaction::balanceReaction() const {
    // simple reactions like A + B -> C, otherwise not working
    int balance1, balance2, balance3;
    std::vector<int> reactantsBalance;
    std::vector<int> productsBalance;

    for (const auto &reactant: reactants) {
        for (const auto &it: reactant.atomsNumber()) {
            reactantsBalance.push_back(it);
        }
    }

    for (const auto &product: products) {
        for (const auto &it: product.atomsNumber()) {
            productsBalance.push_back(it);
        }
    }

    if (productsBalance[0] % reactantsBalance[0] == 0 && productsBalance[1] % reactantsBalance[1] == 0) {
        balance1 = productsBalance[0] / reactantsBalance[0];
        balance2 = productsBalance[1] / reactantsBalance[1];
        balance3 = 1;
    } else {
        productsBalance[0] = productsBalance[0] * reactantsBalance[1];
        productsBalance[1] = productsBalance[1] * reactantsBalance[0];
        balance3 = reactantsBalance[0] * reactantsBalance[1];
        int aux = gcd(productsBalance[0], gcd(productsBalance[1], balance3));

        balance1 = productsBalance[0] / aux;
        balance2 = productsBalance[1] / aux;
        balance3 = balance3 / aux;
    }
    return {balance1, balance2, balance3};
}

void Reaction::displayReaction() const {
    std::vector<int> balance = balanceReaction();
    std::cout << balance[0] << reactants[0].calculateFormula() << " + " << balance[1] << reactants[1].calculateFormula()
              << " -> " << balance[2] << products[0].calculateFormula() << "\n";
}

int Reaction::gcd(int x, int y) const {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}