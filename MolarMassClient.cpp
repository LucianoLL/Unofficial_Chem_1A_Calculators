/* Molar Mass client calculator
 * Luciano Loma Lorenzana
 * Develop: 05/11/2022 - 05/26/2022
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PeriodicTableDictionary.h"
#include "MolarMass.h"

int main () {
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
            
            if (ElementsTable.findElement(vectTwo[0]) == "Bill Nye") {  //  searching for the element in our list
                std::cout << "Could not find element : " << vectTwo[0] << "\n"
                << "Program now terminating, try reinitializing\n";
                exit(EXIT_FAILURE);

            } else {  //  if found, then we do the necessary arithmetic
                float atomWeight = ElementsTable.elmentWeight();
                float atomTimes = std::stof(vectTwo[1]);
                molarMass += multElement(atomWeight, atomTimes);  //  adding the current elements mass to our molar mass
            }
        }
        std::cout << "Molar Mass of " << compoundList[i] << " is : " << molarMass << "\n";
        

    }
}