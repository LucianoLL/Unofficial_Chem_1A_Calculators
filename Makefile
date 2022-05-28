CPP = g++
CPPFLAGS = -Wall -Wextra -pedantic -std=c++17 -Ofast

InitializeFile.o : InitializeFile.cpp InitializeFile.h PeriodicTableDictionary.cpp PeriodicTableDictionary,h
		$(cpp) $(CPPFLAGS) -c InitializeFile.cpp

MolarMassClient : MolarMassClient.o MolarMass.o PeriodicTableDictionary.o
		$(CPP) $(CPPFLAGS) -o MolarMassClient MolarMassClient.o MolarMass.o PeriodicTableDictionary.o

MolarMassClient.o : MolarMassClient.cpp MolarMass.cpp MolarMass.h
		$(CPP) $(CPPFLAGS) -c MolarMassClient.cpp 

MolarMass.o : MolarMass.cpp MolarMass.h
		$(CPP) $(CPPFLAGS) -c MolarMass.cpp

PeriodicTableClient : PeriodicTableClient.o PeriodicTableDictionary.o InitializeFile.o
		$(CPP) $(CPPFLAGS) -o PeriodicTableClient PeriodicTableClient.o PeriodicTableDictionary.o

PeriodicTableClient.o : PeriodicTableClient.cpp PeriodicTableDictionary.cpp InitializeFile.cpp
		$(CPP) $(CPPFLAGS) -c PeriodicTableClient.cpp

PeriodicTableDictionary.o :  PeriodicTableDictionary.cpp PeriodicTableDictionary.h
		$(CPP) $(CPPFLAGS) -c PeriodicTableDictionary.cpp


clean :
		rm -f MolarMassClient PeriodicTableClient InitializeFile *.o