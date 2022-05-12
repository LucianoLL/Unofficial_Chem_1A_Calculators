/* Periodic table dictionary ADT file
 * Luciano Loma Lorenzana
 * Develop: 05/11/2022 - 05/11/2022
 */

#include <iostream>
#include <string>
#include <algorithm>
#include "PeriodicTableDicitonary.h"

PeriodicTable :: periodElement :: periodElement(std::string x, std::string y, int z, float f) {
    elementSymbol = "";
    elementName = "";
    atomicNumber = 0;
    atomicMass = 0;
    next = nullptr;
    prev = nullptr;
}

PeriodicTable :: PeriodicTable() {
    frontDummy = new periodElement("Bill", "Nye", -1, -1);
    backDummy = new periodElement("Bill", "Nye", -1, -1);
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    currPos = 0;
    numElements = 0;

}

void :: insertElement(std::string x, std::string y, int z, float f) {

}