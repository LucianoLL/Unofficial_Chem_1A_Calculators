/*
 * Periodic Table dicitonary client file
 * Luciano Loma Lorenzana
 * Develop: 05/11/2022 - 05/28/2022
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "PeriodicTableDictionary.h"

int main() {
    PeriodicTable Table;  //  declaringt he table
    Table.InitTable();  //  initializes/builds the periodic table

    bool userAgree = true;
    std::string userInput = "";

    std::cout << "Welcome to the Periodic Table Dictionary!\n"
    << "You can start by typing the symbol or name of the element you are seeking for.\n"
    << "You can also exit anytime by typing 'exit'" << "\n";
    while(userAgree) {
        std::cout << "Type name or symbol of element : ";
        std::cin >> userInput;
        std::cout << "\n";
        if (userInput != "exit") {
            if (Table.findElement(userInput) == "Bill Nye") {
                std::cout << "We couldn't find the element you were looking for.\n";
            } else {
                std::cout << "We found it!\n" 
                << "Symbol : " << Table.symbol() << "\n"
                << "Name : " << Table.nameOf() << "\n"
                << "Atomic Number : " << Table.elementPos() << "\n"
                << "Atomic Mass : " << Table.elmentWeight() << "\n";

            }
            std::cout << "\nTry another element? : Yes or No\n";
            std::cin >> userInput;
            if (userInput == "Yes" || userInput == "yes" || userInput == "y") {
                std::cout << "\n";
                userAgree = true;
            } else {
                std::cout << "\nOk, bye then\n";
                userAgree = false;
            }
        } else {
            userAgree = false;
        }
    }
    exit(EXIT_SUCCESS);
}