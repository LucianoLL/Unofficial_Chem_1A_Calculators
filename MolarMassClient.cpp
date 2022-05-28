/* Molar Mass client calculator
 * Luciano Loma Lorenzana
 * Develop: 05/11/2022 - 05/28/2022
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PeriodicTableDictionary.h"
#include "MolarMass.h"

int main () {
    PeriodicTable Table;  //  declaring the table
    Table.InitTable();  //  initializes/builds the periodic table

    int compoundAmounts;  //  what will eventually become a digit
    std::string failSafe;  //  passing argument as a string as a fail safe
    std::cout << "Please type in the number of compounds you want calculated : " << "\n";
    std::cin >> failSafe;
    std::cout << "\n";
    int stringLen = failSafe.length();  //  grabbing the length of the string input

    for (int i = 0; i < stringLen; i++) {
        if (!isdigit(failSafe[i])) {
            std::cout << "Please type an actual NUMBER of compounds you want calculated: " << "\n";
            std::cin >> failSafe;
            stringLen = failSafe.length();
            i = 0;
        }
    }

    compoundAmounts = std::stoi(failSafe);  //  converting the users input into an actual string

    std::string currCompound;  //  a buffer to store the users current compound
    std::vector<std::string> compoundList;  //  to store all of the user's compound inputs


    for (int i = 0; i < compoundAmounts; i++) {
        std::cout << "Type comound " << i + 1 << " of " << compoundAmounts << " : " << "\n";
        std::cin >> currCompound;  //  taking in the user's inputs
        std::cout << "\n";
        compoundList.push_back(currCompound);  //  adding them into the vector
    }

    int listSize = compoundList.size();  //  to easily parse in through the vector
    std::vector<std::string> vectOne;
    for (int i = 0; i < listSize; i++) {  //  going through the inputs
        vectOne = splitCompound(compoundList[i]);  //  splitting the elements with their appropriate digits 
        float molarMass = 0;  //  the molar mass for our current compound

        std::vector<std::string> vectTwo;  //  a vector that'll hold the element an it's digit
        int compSize = vectOne.size();  //  to make life easier when iterating through
        for (int i = 0; i < compSize; i++) {
            vectTwo = segComp(vectOne[i]);  //  splittign our current element from it's digit
            
            if (Table.findElement(vectTwo[0]) == "Bill Nye") {  //  searching for the element in our list
                std::cout << "Could not find element : " << vectTwo[0] << "\n"
                << "Program now terminating, try reinitializing\n";
                exit(EXIT_FAILURE);

            } else {  //  if found, then we do the necessary arithmetic
                float atomWeight = Table.elmentWeight();
                float atomTimes = std::stof(vectTwo[1]);
                molarMass += multElement(atomWeight, atomTimes);  //  adding the current elements mass to our molar mass
            }
        }
        std::cout << "Molar Mass of " << compoundList[i] << " is : " << molarMass << "\n";
        

    }
}