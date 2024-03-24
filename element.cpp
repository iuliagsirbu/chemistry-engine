#include "include/element.h"


Element::Element() {
    this->name = "None";
    this->atomicNumber = 0;
    this->atomicSymbol = "None";
    this->atomicMass = 0.0;
    this->electronConfiguration = "...";
}

Element::Element(const std::string &name, int atomicNumber, const std::string &atomicSymbol,
                 double atomicMass) {
    this->name = name;
    this->atomicNumber = atomicNumber;
    this->atomicSymbol = atomicSymbol;
    this->atomicMass = atomicMass;
}

Element::~Element() = default;

const std::string Element::getName() const {
    return name;
}

const std::string Element::getAtomicSymbol() const {
    return atomicSymbol;
}

int Element::getAtomicNumber() const {
    return atomicNumber;
}

double Element::getAtomicMass() const {
    return atomicMass;
}

Element::Element(const Element &other) {
    this->name = other.name;
    this->atomicNumber = other.atomicNumber;
    this->atomicSymbol = other.atomicSymbol;
    this->atomicMass = other.atomicMass;
}

bool Element::operator==(const Element &other) const {
    return (name == other.name && atomicNumber == other.atomicNumber && atomicSymbol == other.atomicSymbol &&
            atomicMass == other.atomicMass);
}

Element &Element::operator=(const Element &other) {
    if (this != &other) {
        name = other.name;
        atomicNumber = other.atomicNumber;
        atomicSymbol = other.atomicSymbol;
        atomicMass = other.atomicMass;
    }
    return *this;
}

std::istream &operator>>(std::istream &in, Element &elem) {
    in >> elem.name >> elem.atomicNumber >> elem.atomicSymbol >> elem.atomicMass;
    return in;
}

std::ostream &operator<<(std::ostream &out, Element &elem) {
    out << "Element: " << elem.name << ", Z: " << elem.atomicNumber << ", symbol: " << elem.atomicSymbol << ", A: "
        << elem.atomicMass;
    return out;
}

void Element::addIsotope(int mass, double abundance) {
    isotopes.emplace_back(mass, abundance);
}

void Element::displayIsotopes() const {
    if (isotopes.empty()) std::cout << name << " has no isotopes.\n";
    else {
        std::cout << "Isotopes of " << name << " are:\n";
        for (const auto &isotope: isotopes) {
            std::cout << "  - Mass: " << isotope.first << ", Abundance: " << isotope.second << "\n";
        }
    }
}
