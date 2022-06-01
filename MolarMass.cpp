/*
 * Molar Mass Calculator ADT
 * Luciano Loma Lorenzana
 * Develop: 05/21/2022 - 05/26/2022
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "MolarMass.h"
#include "PeriodicTableDictionary.h"

std::vector<std::string> splitCompound(std::string clientComp) {
    std::vector<std::string> toReturn;  //  creating a vector that'll return the parsed compounds
    int stirngLen = clientComp.length();  //  to easily iterate through the string
    std::string bufferStr = "";  //  to temporarily holds out elments as we're parsing

    for (int i = 0; i < stirngLen; i++) {
        bufferStr = "";  //  clearing our buffer every time
        if (std::isupper(clientComp[i])) {  //  checking if the current character is uppercase
            bufferStr = clientComp[i];  //  is we know it's a new element
            if (std::islower(clientComp[i + 1])) {  //  we check that it's an elements with two characters
                i++;  //  if so we add it to our buffer
                bufferStr += clientComp[i];
            }
            if (isdigit(clientComp[i + 1])) {  //  we also check if it's followed by a number
                i++;  //  if so we also add to that our buffer
                bufferStr += clientComp[i];
            }
            toReturn.push_back(bufferStr);
        } else if (clientComp[i] == '(') {  //  if there are parenthesis then we have a speacial case
            while (clientComp[i] != ')') {  // we just grab what's inside the parenthesis and the following digit
                bufferStr += clientComp[i];
                i++;
            }
            bufferStr += clientComp[i];  //  we add the closing parenthesis
            if (isdigit(clientComp[i + 1])) {  //  check for any extra digit outside the parenthesis
                i++;
                bufferStr += clientComp[i];
            }
            toReturn.push_back(bufferStr);  //  adding the new element to our list of elements
        }
    }
    return (toReturn);  //  return the vector
}

std::vector<std::string> segComp(std::string S) {  //  to segment the elements from their digits
    std::vector<std::string> toReturn;  //  a vector with the element and numbers parsed into their own vector
    std::string strBuffer = "";
    int eleSize = S.length();

    int i = 0;
    while (!(isdigit(S[i])) && i < eleSize) {  //  as long as we don;t reach the end or hit a numerical digit
        strBuffer += S[i];  //  add it to our string buffer
        i++;
    }
    toReturn.push_back(strBuffer);  //  pushing our parsed element into our vector
    if (isdigit(S[i])) {  //  checking if our last element is a numerical digit
        strBuffer = S[i];  //  we make it our string buffer
        toReturn.push_back(strBuffer);  //  push it as a new element into our vector
    } else {
        toReturn.push_back("1");  //  elese we'll just be multiplying by 1
    }
    return (toReturn);  //  return that vector
}

float multElement(std::string currComp, PeriodicTable Table) {
        std::cout << "In helepr fcn : " << currComp << "\n";
        float molarMass = 0;  //  the molar mass for our current compound
        
        std::vector<std::string> vectOne;
        vectOne = splitCompound(currComp);

        std::vector<std::string> vectTwo;  //  a vector that'll hold the element an it's digit
        int compSize = vectOne.size();  //  to make life easier when iterating through
        std::cout << compSize << "\n";
        for (int j = 0; j < compSize; j++) {
            std::cout << j << " ";
            vectTwo = segComp(vectOne[j]);  //  splittign our current element from it's digit
            
            if (Table.findElement(vectTwo[0]) == "Bill Nye") {  //  searching for the element in our list
                std::cout << "Could not find element : " << vectTwo[0] << "\n";
                exit(EXIT_FAILURE);

            } else {  //  if found, then we do the necessary arithmetic
                float atomWeight = Table.elmentWeight();
                float atomTimes = std::stof(vectTwo[1]);
                molarMass += (atomWeight * atomTimes);  //  adding the current elements mass to our molar mass
            }
        }
        std::cout << molarMass << "\n";
        return (molarMass);
    
}