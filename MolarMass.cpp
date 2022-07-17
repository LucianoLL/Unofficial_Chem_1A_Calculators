/*
 * Molar Mass Calculator ADT
 * Luciano Loma Lorenzana
 * Develop: 05/21/2022 - 06/02/2022
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "MolarMass.h"
#include "PeriodicTableDictionary.h"

std::vector<std::string> parenCase(std::string S) {
    int strSize = S.size();
    int outNum = 0;  //  initializing the numebr outside of the parenthesis

    if (S[strSize - 1] == ')') {
        outNum = 1;
    } else if (!isdigit(S[strSize - 1])) {
        std::cout << "Element outside of parenthesis is not a number \n"
        << "Terminating program now, reinitialize later \n";
        exit(EXIT_FAILURE);
    } else {
        outNum = (int)(S[strSize - 1]);
        S = S.substr(0, strSize - 1);  //  getting rid of the last element in the string
        strSize = S.size();  //  creatng anew size
    }

    std::vector<std::string> toReturn;
    std::string strBuffer = "";
    int intBuffer = 0;
    for (int i = 1; 1 < strSize - 1; i++) {
        if (std::isupper(S[i])) {
            strBuffer = S[i];
            if (std::islower(S[i + 1])) {
                i++;
                strBuffer += S[i];
            }
            if (isdigit(S[i + 1])) {
                i++;
                intBuffer = (int)(S[i]);
                intBuffer *= outNum;
                strBuffer += std::to_string(intBuffer);
            }
            toReturn.push_back(strBuffer);

        }
    }
    return (toReturn);

}

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



float multElement(std::string currComp) {
    PeriodicTable Table;
    Table.InitTable();

    float molarMass = 0;  //  the molar mass for our current compound
    
    std::vector<std::string> vectOne;
    vectOne = splitCompound(currComp);

    std::vector<std::string> vectTwo;  //  a vector that'll hold the element an it's digit
    int compSize = vectOne.size();  //  to make life easier when iterating through

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
    return (molarMass);
    
}