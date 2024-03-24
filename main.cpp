#include <iostream>
#include <fstream>
#include <cassert>
#include "include/element.h"
#include "include/compound.h"
#include "include/reaction.h"

std::ifstream ein("inputs/element.in");
std::ifstream compin("inputs/compound.in");
std::ifstream rin("inputs/reactant.in");

int main() {
    // ~~~ELEMENT CLASS~~~
    std::cout << "===ELEMENT CLASS===\n";
    // constructors
    Element hydrogen;
    std::cout << hydrogen << "\n";

    hydrogen = {"Hydrogen", 1, "H", 1};
    std::cout << hydrogen << "\n";

    // getters
    std::cout << hydrogen.getName() << " " << hydrogen.getAtomicSymbol() << " " << hydrogen.getAtomicNumber() << " "
              << hydrogen.getAtomicMass() << "\n";

    // setters
    hydrogen.setName("HYDROGEN");
    hydrogen.setAtomicMass(1.00784);
    std::cout << hydrogen << "\n";

    // copy constructor
    Element hydrogenCopy(hydrogen);
    std::cout << "COPY -> " << hydrogenCopy << "\n";

    // operator overloading
    if (hydrogen == hydrogenCopy)
        std::cout << "They are the same element!\n";
    else std::cout << "They are different elements!\n";

    hydrogenCopy.setName("Hydrogen");
    hydrogen = hydrogenCopy;
    std::cout << hydrogen << "\n";

    // reading (ein) and writing elements
    Element oxygen, chlorine, sulfur;
    ein >> oxygen >> chlorine >> sulfur;
    std::cout << chlorine << "\n";

    // methods
    oxygen.addIsotope(16, 99.76);
    oxygen.addIsotope(17, 0.04);
    oxygen.addIsotope(18, 0.20);
    oxygen.displayIsotopes();

    // asserts
    std::cout << "\nASSERTS: \n";
    assert(hydrogen.getName() == "Hydrogen");
    std::cout << "Element Checkpoint #1\n";
    assert(sulfur.getName() == "Sulfur");
    std::cout << "Element Checkpoint #2\n";
    assert(chlorine.getAtomicNumber() == 17);
    std::cout << "Element Checkpoint #3\n";
    assert(hydrogenCopy.getAtomicMass() == 1.00784);
    std::cout << "Element Checkpoint #4\n";

    // ~~~COMPOUND CLASS~~~
    std::cout << "\n\n";
    std::cout << "===COMPOUND CLASS===\n";
    // constructors
    Compound water;
    std::cout << water.getName() << "\n";
    water = {"Water", {hydrogen, hydrogen, oxygen}};
    std::cout << water << "\n";
    Compound water2(water);
    std::cout << water2 << "\n";
    Compound hydrochloricAcid, hydrogenSulfide;

    // reading
    compin >> hydrochloricAcid >> hydrogenSulfide;
    std::cout << hydrochloricAcid << "\n";

    // methods
    std::vector<Element> testGetElements = hydrochloricAcid.getElements();
    for (const auto &element: testGetElements) {
        std::cout << element << "\n";
    }
    std::cout << hydrogenSulfide.calculateFormula() << " " << hydrogenSulfide.calculateMass() << "\n";

    // asserts
    std::cout << "\nASSERTS: \n";
    assert(water.getName() == "Water");
    std::cout << "Compound Checkpoint #1\n";
    assert(hydrogenSulfide.getName() == "HydrogenSulfide");
    std::cout << "Compound Checkpoint #2\n";
    assert(hydrochloricAcid.calculateFormula() == "HCl");
    std::cout << "Compound Checkpoint #3\n";
    assert(int(hydrochloricAcid.calculateMass()) == 36);
    std::cout << "Compound Checkpoint #4\n";


    // ~~~REACTION CLASS~~~
    std::cout << "\n\n";
    std::cout << "===REACTION CLASS===\n";
    // constructors
    Reaction waterReaction;
    std::cout << waterReaction << "\n";

    Compound hydrogenMolecule = {"hydrogenMolecule", {hydrogen, hydrogen}};
    Compound oxygenMolecule = {"oxygenMolecule", {oxygen, oxygen}};
    waterReaction = {{hydrogenMolecule, oxygenMolecule},
                     {water}};
    std::cout << waterReaction << "\n";

    Reaction waterReactionCopy(waterReaction);
    std::cout << waterReactionCopy << "\n";

    // reading
    Reaction sulfuricReaction, hydrochloricReaction;
    rin >> sulfuricReaction >> hydrochloricReaction;
    std::cout << hydrochloricReaction << "\n";
    sulfuricReaction.displayReaction();
    hydrochloricReaction.displayReaction();
    waterReaction.displayReaction();

    return 0;
}
