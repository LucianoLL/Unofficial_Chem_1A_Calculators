/*
 * Molar Mass Calculator ADT
 * Luciano Loma Lorenzana
 * Develop: 05/21/2022 - 05/21/2022
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "MolarMass.h"
#include "PeriodicTableDictionary.h"

std::vector<std::string> splitCompound(std::string clientComp) {
    std::vector<std::string> toReturn;
    int stirngLen = clientComp.length();
    std::string bufferStr = "";

    for (int i = 0; i < stirngLen; i++) {
        bufferStr = "";
        if (std::isupper(clientComp[i])) {
            bufferStr = clientComp[i];
            if (std::islower(clientComp[i + 1])) {
                i++;
                bufferStr += clientComp[i];
            }
            if (isdigit(clientComp[i + 1])) {
                i++;
                bufferStr += clientComp[i];
            }
            std::cout << bufferStr << "\n";
            toReturn.push_back(bufferStr);
        } else if (clientComp[i] == '(') {
            while (clientComp[i] != ')') {
                bufferStr += clientComp[i];
                i++;
            }
            bufferStr += clientComp[i];
            if (isdigit(clientComp[i + 1])) {
                i++;
                bufferStr += clientComp[i];
            }
            std::cout << bufferStr << "\n";
            toReturn.push_back(bufferStr);
        }
    }
    return (toReturn);
}

float multElement(std::string perElement, int x){

}

float addAllElements(std::vector<int>) {

}