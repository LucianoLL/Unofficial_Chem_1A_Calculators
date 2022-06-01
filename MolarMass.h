/*
 * Molar Mass header file
 * Luciano Loma Lorenzana
 * Develop: 05/25/2022 - 05/21/2022
 */

#include <iostream>
#include <string>
#include <vector>
#include "PeriodicTableDictionary.h"

#ifndef MOLAR_MASS_H_
#define MOLAR_MASS_H_

/*** Parsing the compound ***/
std::vector<std::string> splitCompound(std::string clientComp);

/*** To get the size of the string beng passed ***/
int strSize(std::string S);

/*** To segment the elements from the digits ***/
std::vector<std::string> segComp(std::string S);

/*** To get the weight of each element in the compound ***/
float multElement(std::string currComp);


#endif