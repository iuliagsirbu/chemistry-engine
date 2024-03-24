#ifndef CHEMISTRY_ENGINE_ELEMENT_H
#define CHEMISTRY_ENGINE_ELEMENT_H

#include <iostream>
#include <vector>

class Element {
    std::string name;
    int atomicNumber;
    std::string atomicSymbol;
    double atomicMass;
    std::string electronConfiguration;
    std::vector<std::pair<int, double>> isotopes;

public:
    // constructors + destructor
    Element();

    Element(const std::string &name, int atomicNumber, const std::string &atomicSymbol, double atomicMass);

    ~Element();

    // getters
    const std::string getName() const;

    const std::string getAtomicSymbol() const;

    int getAtomicNumber() const;

    double getAtomicMass() const;

    // copy constructor
    Element(const Element &other);

    // operator overloading
    bool operator==(const Element &other) const;

    Element &operator=(const Element &other);

    friend std::istream &operator>>(std::istream &in, Element &elem);

    friend std::ostream &operator<<(std::ostream &out, Element &elem);

    // other methods
    void addIsotope(int mass, double abundance);

    void displayIsotopes() const;
};

#endif //CHEMISTRY_ENGINE_ELEMENT_H
