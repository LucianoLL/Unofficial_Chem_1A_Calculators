/*
 * Molar Mass header file
 * Luciano Loma Lorenzana
 * Develop: 05/21/2022 - 05/21/2022
 */

#include <iostream>
#include <string>

#ifndef MOLAR_MASS_H_
#define MOLAR_MASS_H_

class MolarMassCalc {
    // private:
    public:
    /*** Parsing the compound ***/
    std::vector<std::string> splitCompound(std::string clientComp);
    
    /*** To get the weight of each element in the compound ***/
    float multElement(std::string perElement, int x);

    /*** Getting all elements added together ***/
    float addAllElements(std::vector<int>);
};
#endif