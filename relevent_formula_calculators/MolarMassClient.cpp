/* Molar Mass client calculator
 * Luciano Loma Lorenzana
 * Develop: 05/11/2022 - 06/01/2022
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PeriodicTableDictionary.h"
#include "MolarMass.h"

int main () {
    // PeriodicTable Table;  //  declaring the table
    // Table.InitTable();  //  initializes/builds the periodic table

    std::string userComp = "";
    bool fcnBool = true;

    std::cout << "Welcome to the Molar Mass Calculator\n"
    << "You can exit anytime by typing the word exit \n";

    std::string userOpt = "";

    while (fcnBool == true) {
        std::cout << "Please type any compound : ";
        std::cin >> userComp;
        if (userComp == "exit") {
            fcnBool = false;
        } else {
            float mass = multElement(userComp);
            std::cout << "The Molar Mass of " << userComp << " is : " << mass << "\n";
            std::cout << "Would you like to try another compound : Yes or No?\n";
            std::cin >> userOpt;
            if ((userOpt == "Yes") || (userOpt == "yes") || (userOpt == "y") || (userOpt == "Y")) {
                fcnBool = true;
            } else {
                fcnBool = false;
            }  
        }     
    }
    exit(EXIT_SUCCESS);
}