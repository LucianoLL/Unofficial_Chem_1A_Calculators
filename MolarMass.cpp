/*
 * Molar Mass Calculator ADT
 * Luciano Loma Lorenzana
 * Develop: 05/21/2022 - 05/21/2022
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

int strSize(std::string S) {  //  to make indexing easier to seperate the numbers
    int toReturn = 0;
    for (char& C : S) {
        toReturn++;
    }

    return (toReturn);

}

std::vector<std::string> segComp(std::string S) {  //  to segment the elements from their digits
    std::vector<std::string> toReturn;
    std::string strBuffer = "";
    int eleSize = strSize(S);

    int i = 0;
    while (!(isdigit(S[i])) && i < eleSize) {
        strBuffer += S[i];
    }
    toReturn.push_back(strBuffer);
    if (isdigit(S[i])) {
        strBuffer = S[i];
        toReturn.push_back(strBuffer);
    } else {
        toReturn.push_back("1");
    }
    return (toReturn);
}

float ifParenthesis (std::string S) {

}

float multElement(std::string perElement) {
    
}

float addAllElements(std::vector<int>) {

}