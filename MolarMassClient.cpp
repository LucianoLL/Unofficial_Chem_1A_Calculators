/* Molar Mass client calculator
 * Luciano Loma Lorenzana
 * Develop: 05/11/2022 - 05/21/2022
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PeriodicTableDictionary.h"
#include "MolarMass.h"

void initPeriodicTable() {
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
}

int main () {
    initPeriodicTable();

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

    int listSize = compoundList.size();
    for (int i = 0; i < listSize; i++) {
        splitCompound(compoundList[i]);
    }
}