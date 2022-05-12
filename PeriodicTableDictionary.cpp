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

void PeriodicTable :: insertElement(std::string x, std::string y, int z, float f) {
    periodElement* tmp = new periodElement(x, y, z, f);  //  creating a new element to insert into the table list
    
    beforeCursor->next = tmp;
    tmp->prev = beforeCursor;
    tmp->next = afterCursor;
    afterCursor->prev = tmp;  //  all elements will be taken from the this cursor
    afterCursor = tmp;
    numElements++;
}

int PeriodicTable :: length() const {
    return (numElements);
}

std::string PeriodicTable :: symbol() const {
    return (afterCursor->elementSymbol);
}

std::string PeriodicTable :: nameOf() const {
    return (afterCursor->elementName);
}

int PeriodicTable :: elementPos() const {
    return (afterCursor->atomicNumber);
}

int PeriodicTable :: elmentWeight () const {
    return (afterCursor->atomicMass);
}

void PeriodicTable :: moveFront() {
    beforeCursor = frontDummy;
    afterCursor = frontDummy->next;
    currPos = 0;
}

void PeriodicTable :: moveBack() {
    afterCursor = backDummy;
    beforeCursor = backDummy->prev;
    currPos = numElements - 1;
}

std::string PeriodicTable :: findElement(std::string x) {
    moveFront();
    while (afterCursor != backDummy) {
        if (afterCursor->elementName == x) {
            return (afterCursor->elementName);
        } else if (afterCursor->elementSymbol == x) {
            return (afterCursor->elementSymbol);
        }
        moveNext();
    }

}