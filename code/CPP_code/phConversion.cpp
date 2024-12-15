/*
 * pH Conversion Functions/ADT
 * Luciano Loma Lorenzana
 * Develop: 08/24/2024
 */

#include <iostream>
#include <string>
#include <vector>

#include "phConversion.h"


/*** pH = -log(H+), log base of 10 ***/
std::string pHFromHydrogenIonAmount(std:string hydroIonAmt) {
	if (!std::isdigit(hydroIonAmt)) {
		std::cout << "Please enter a valid numerical value. \n";
	}
	
	intAmount = std:stoi(hydroIonAmt)

	
}
