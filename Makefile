/*
 * Main Makefile
 * Luciano Loma Lorenzana
 * Develop: 05/16/2022 - 05/16/2022
 */

CPP = g++
CPPFLAGS = -Wall -Wextra -pedantic -std=c++17 -Ofast
MolarMass : MolarMass.o PeriodicTableDicitonary.o
	$(CPP) $(CPPFLAGS) -o MolarMass MolarMass.o PeriodicTableDicitonary.o

MolarMass.o : MolarMass.cpp
	$(CPP) $(CPPFLAGS) -c MolarMass.cpp