import os

def programOptions(userInput):
    if userInput == 0:
        return "./PeriodicTableClient"
    elif userInput == 1:
        return "./MolarMassClient"
    
    elif userInput == 2:
        return "./QuadraticFormula"
    
    else:
        raise OSError("Program Not Available")
    
if __name__ == "__main__":
    userInt = int(input("Select Program: \n\
Periodic Table Database : 0\n\
Molar Mass Calculator : 1\n\
Quadratic Formula Calculator : 2\n\
select: "))

    desiredProgram = programOptions(userInt)
    os.system(desiredProgram)
    