/* Molar Mass client calculator
 * Luciano Loma Lorenzana
 * Develop: 05/11/2022 - 05/11/2022
 */

#include <iostream>
#include <string>
#include <vector>
#include "MolarMass.h"

int main () {
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
        std::cout << "Type comound " << i << " of " << compoundAmounts << " : " << "\n";
        std::cin >> currCompound;  //  taking in the user's inputs
        std::cout << "\n";
        compoundList.push_back(currCompound);  //  adding them into the vector
    }
}