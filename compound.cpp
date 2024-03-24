#include "include/compound.h"

Compound::Compound() {
    name = "None";
}

Compound::Compound(const std::string &name, const std::vector<Element> &elements) :
        name(name), elements(elements) {}

Compound::~Compound() {
    name = "";
    elements.clear();
}

std::string Compound::getName() const { return name; }

std::vector<Element> Compound::getElements() const { return elements; }

Compound::Compound(const Compound &other) {
    this->name = other.name;
    this->elements = other.elements;
}

Compound &Compound::operator=(const Compound &other) {
    if (this != &other) {
        name = other.name;
        elements = other.elements;
    }
    return *this;
}

std::istream &operator>>(std::istream &in, Compound &comp) {
    in >> comp.name;
    int noElements;
    in >> noElements;
    Element elemToRead;
    for (int i = 0; i < noElements; i++) {
        in >> elemToRead;
        comp.elements.push_back(elemToRead);
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Compound &comp) {
    out << "Compound: " << comp.name << ", Formula: " << comp.calculateFormula() << ", Mass: " << comp.calculateMass()
        << "\n";
    return out;
}

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
    if (noElement != 1)
        formula += std::to_string(noElement);
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


