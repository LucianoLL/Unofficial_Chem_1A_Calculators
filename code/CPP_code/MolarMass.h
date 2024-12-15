/*
 * Molar Mass header file
 * Luciano Loma Lorenzana
 * Develop: 05/25/2022 - present
 */

#include <iostream>
#include <string>
#include <vector>
#include "PeriodicTableDictionary.h"

#ifndef MOLAR_MASS_H_
#define MOLAR_MASS_H_

/*** In case one of the inputs is incased in parenthesis ***/
std::string parenCase(std::string S);

/*** Parsing the compound ***/
std::vector<std::string> splitCompound(std::string clientComp);

/*** To get the size of the string beng passed ***/
int strSize(std::string S);

/*** To segment the elements from the digits ***/
std::vector<std::string> segComp(std::string S);

/*** To calculate the compound's molar mass ***/
float multElement(std::string currComp);


#endif