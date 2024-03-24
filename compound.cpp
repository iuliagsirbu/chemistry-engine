#include "include/compound.h"

Compound::Compound() = default;

Compound::Compound(const std::string &name, const std::vector<Element> &elements) :
        name(name), elements(elements) {}

Compound::~Compound() = default;

const std::string Compound::getName() const { return name; }

std::vector<Element> Compound::getElements() const { return elements; }

double Compound::calculateMass() const {
    double mass = 0.0;
    for (const auto &element: elements) {
        mass += element.getAtomicMass();
    }
    return mass;
}

std::string Compound::calculateFormula() const {
    std::string formula;
    int noElement = 0;
    Element currentElement = elements[0];
    formula += currentElement.getAtomicSymbol();
    for (const auto &element: elements) {
        if (element == currentElement) {
            noElement++;
        } else {
            if (noElement > 1)
                formula += std::to_string(noElement);
            currentElement = element;
            noElement = 1;
            formula += currentElement.getAtomicSymbol();
        }
    }
    return formula;
}

std::vector<int> Compound::atomsNumber() const {
    std::vector<int> atoms;
    int no = 0;
    Element currElem = elements[0];
    for (const auto &element: elements) {
        if (element == currElem) {
            no++;
        } else {
            atoms.push_back(no);
            no = 1;
            currElem = element;
        }
    }
    atoms.push_back(no);
    return atoms;
}

std::ostream &operator<<(std::ostream &out, Compound &comp) {
    out << "Compound: " << comp.name << ", Formula: " << comp.calculateFormula() << ", Mass: " << comp.calculateMass()
        << "\n";
    return out;
}

