/*
 * Main Makefile
 * Luciano Loma Lorenzana
 * Develop: 05/16/2022 - 05/16/2022
 */

CPP = g++
CPPFLAGS = -Wall -Wextra -pedantic -std=c++17 -Ofast

MolarMassClient : MolarMassClient.o MolarMass.o PeriodicTableDicitonary.o
	$(CPP) $(CPPFLAGS) -o MolarMassClient MolarMassClient.o MolarMass.o PeriodicTableDicitonary.o

MolarMassClient.o : MolarMassClient.cpp MolarMass.cpp MolarMass.h
	$(CPP) $(CPPFLAGS) -c MolarMassClient.cpp 

MolarMass.o : MolarMass.cpp MolarMass.h
	$(CPP) $(CPPFLAGS) -c MolarMass.cpp

PeriodicTableDicitonary.o :  PeriodicTableDicitonary.cpp PeriodicTableDicitonary.h
	$(CPP) $(CPPFLAGS) -c PeriodicTableDicitonary.cpp

clean :
	rm -f MolarMassClient MolarMassClient.o MolarMass.o PeriodicTableDicitonary.o