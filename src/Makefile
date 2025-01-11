CPP = g++
CPPFLAGS = -Wall -Wextra -pedantic -std=c++17 -Ofast
SRCMM = MolarMass
SRCPT = PeriodicTable
SRCPH = phConversion


MolarMassClient : MolarMassClient.o MolarMass.o PeriodicTableDictionary.o
		$(CPP) $(CPPFLAGS) -o MolarMassClient MolarMassClient.o MolarMass.o PeriodicTableDictionary.o

MolarMassClient.o : $(SRCMM)/MolarMassClient.cpp 
		$(CPP) $(CPPFLAGS) -c $(SRCMM)/MolarMassClient.cpp 

MolarMass.o : $(SRCMM)/MolarMass.cpp $(SRCMM)/MolarMass.h
		$(CPP) $(CPPFLAGS) -c $(SRCMM)/MolarMass.cpp

PeriodicTableClient : PeriodicTableClient.o  PeriodicTableDictionary.o
		$(CPP) $(CPPFLAGS) -o  PeriodicTableClient  PeriodicTableClient.o  PeriodicTableDictionary.o

PeriodicTableClient.o : $(SRCPT)/PeriodicTableClient.cpp
		$(CPP) $(CPPFLAGS) -c $(SRCPT)/PeriodicTableClient.cpp

PeriodicTableDictionary.o : $(SRCPT)/PeriodicTableDictionary.cpp $(SRCPT)/PeriodicTableDictionary.h
		$(CPP) $(CPPFLAGS) -c $(SRCPT)/PeriodicTableDictionary.cpp


clean :
		rm -f MolarMassClient PeriodicTableClient *.o
