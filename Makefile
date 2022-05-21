CPP = g++
CPPFLAGS = -Wall -Wextra -pedantic -std=c++17 -Ofast

MolarMassClient : MolarMassClient.o MolarMass.o PeriodicTableDictionary.o
		$(CPP) $(CPPFLAGS) -o MolarMassClient MolarMassClient.o MolarMass.o PeriodicTableDictionary.o

MolarMassClient.o : MolarMassClient.cpp MolarMass.cpp MolarMass.h
		$(CPP) $(CPPFLAGS) -c MolarMassClient.cpp 

MolarMass.o : MolarMass.cpp MolarMass.h
		$(CPP) $(CPPFLAGS) -c MolarMass.cpp

PeriodicTableDictionary.o :  PeriodicTableDictionary.cpp PeriodicTableDictionary.h
		$(CPP) $(CPPFLAGS) -c PeriodicTableDictionary.cpp

clean :
		rm -f MolarMassClient MolarMassClient.o MolarMass.o PeriodicTableDictionary.o