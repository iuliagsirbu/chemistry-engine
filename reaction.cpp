#include "reaction.h"

Reaction::Reaction() = default;

Reaction::Reaction(const std::vector<Compound> &reactants, const std::vector<Compound> &products) : reactants(
        reactants), products(products) {}

Reaction::~Reaction() {
    reactants.clear();
    products.clear();
}

Reaction::Reaction(const Reaction &other) {
    reactants = other.reactants;
    products = other.products;
}

Reaction &Reaction::operator=(const Reaction &other) {
    if (this != &other) {
        reactants = other.reactants;
        products = other.products;
    }
    return *this;
}

std::istream &operator>>(std::istream &in, Reaction &react) {
    int noReactants, noProducts;
    in >> noReactants >> noProducts;
    Compound compToRead;
    for (int i = 0; i < noReactants; i++) {
        compToRead = Compound();
        in >> compToRead;
        react.reactants.push_back(compToRead);
    }
    for (int i = 0; i < noProducts; i++) {
        compToRead = Compound();
        in >> compToRead;
        react.products.push_back(compToRead);
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Reaction &react) {
    out << "The reactants of this reaction are: \n";
    for (const auto &reactant: react.reactants) {
        out << "    -" << reactant << "\n";
    }
    out << "The products of this reaction are: \n";
    for (const auto &product: react.products) {
        out << "    -" << product << "\n";
    }
    return out;
}

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

