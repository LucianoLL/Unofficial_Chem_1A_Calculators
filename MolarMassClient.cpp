/* Molar Mass client claculator
 * Luciano Loma Lorenzana
 * Develop: 05/11/2022
 */

#include <iostream>
#include <string>
#include "MolarMass.h"

int main (int argc, char *argv[]) {
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
}