/*
 * Periodic Table dicitonary client file
 * Luciano Loma Lorenzana
 * Develop: 05/11/2022 - 05/11/2022
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "PeriodicTableDictionary.h"

int main() {
    PeriodicTable ElementsTable;
    std::ifstream inFile;
    inFile.open("PeriodicTable.txt");

    std::string currLine = "";  //  to grab the current line that we're on in the text file
    ElementsTable.moveFront();  //  moving to the front of our table
    while (std::getline(inFile, currLine)) {  //  to iterate through our text document
        std::stringstream toStream(currLine);  //  to parse/tokenize our string
        std::string strBuffer = "";  //  to hold the current element in the string
        
        std::string tmpSymbol = "";  //  place holder name for element symbol
        std::string tmpName = "";  //  place holder for the element name
        int tmpNumber = 0;  //  place holder for the atomic number
        float tmpMass = 0;  //  place holder for it's mass
        /* 
         * got the idea for the parsing through this site:
         * https://reactgo.com/iterate-over-words-cpp/
         */
        for (int i = 0; toStream >> strBuffer; i++) {
            if (i == 0) {
                tmpSymbol = strBuffer;
            } else if ( i == 1) {
                tmpName = strBuffer;
            } else if (i == 2) {
                tmpNumber = std::stoi(strBuffer);
            } else if (i == 3) {
                tmpMass = std::stof(strBuffer);
            }
        }
        ElementsTable.insertElement(tmpSymbol, tmpName, tmpNumber, tmpMass);  //  inseritng our new element into our database
    }

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
            if (ElementsTable.findElement(userInput) == "Bill Nye") {
                std::cout << "We couldn't find the element you were looking for.\n";
            } else {
                std::cout << "We found it!\n" 
                << "Symbol : " << ElementsTable.symbol() << "\n"
                << "Name : " << ElementsTable.nameOf() << "\n"
                << "Atomic Number : " << ElementsTable.elementPos() << "\n"
                << "Atomic Mass : " << ElementsTable.elmentWeight() << "\n";

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