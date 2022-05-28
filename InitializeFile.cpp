/* 
 * Initialize header file
 * Luciano Loma Lorenzana
 * Develop: 05/28/2022 - 05/28/2022
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <PeriodicTableDictionary.h>
#include <MolarMass.h>

#ifndef INIT_FILE_H_
#define INIT_FILE_H_

/*** Initializing the periodic Table ***/
void InitTable(PeriodicTable Table) {
    std::ifstream inFile;
    inFile.open("PeriodicTable.txt");
    std::string currLine = "";  //  to grab the current line that we're on in the text file
    Table.moveFront();  //  moving to the front of our table
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
        Table.insertElement(tmpSymbol, tmpName, tmpNumber, tmpMass);  //  inseritng our new element into our database
    }

}

#endif