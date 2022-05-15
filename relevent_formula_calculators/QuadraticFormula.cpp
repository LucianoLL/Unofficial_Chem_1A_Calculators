/*
 * Quadratic Fromula Program
 * Luciano Loma Lorenzana
 * Develop: 05/15/2022 - 05/15/2022
 */
#include <iostream>
#include <string>
#include <math.h>
int main() {
    float a = 0;  //  the general variable utilized by the quadratic formula
    float b = 0;
    float c = 0;
    bool iterBool = true;  //  the conditional for the loop
    
    while (iterBool == true) { 

        std::cout << "Type value for a : ";
        std::cin >> a;
        std::cout <<"\nType value for b : ";
        std::cin >> b;
        std::cout << "\nType value for c : ";
        std::cin >> c;

        float negB = 0 - b;  //  -b
        float twoA = 2 * a;  // 2a
        float squareB = b * b;  //  b^2
        float fourAC = 4*a*c;  //  4ac
        float inRoot = squareB - fourAC;  //  b^2 - 4ac
        float actRoot = std::sqrt(inRoot);  //  (b^2 - 4ac)^-2

        float negX = (negB - actRoot) / twoA;  //  (-b - (b^2 - 4ac)^-2)  /2a
        float posX = (negB + actRoot) / twoA;   //  (-b + (b^2 - 4ac)^-2)  /2a

        std::cout << "\n";
        std::cout << "+ : " << posX << "\n";
        std::cout << "- : " << negX << "\n";

        std::cout << "Would you like to continue? : Yes or No" << "\n";
        std::string toContinue = "";
        std::cin >> toContinue;
        if (toContinue == "No" || toContinue == "no" || toContinue == "n") {  //  to exit the program
            iterBool = false;
        }

    }
    exit(EXIT_SUCCESS);
}