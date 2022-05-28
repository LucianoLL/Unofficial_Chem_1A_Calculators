/* 
 * Periodic Table dicitonary header file
 * Luciano Loma Lorenzana
 * Develop: 05/11/2022 - 05/21/2022
 */

#include <iostream>
#include <string>

#ifndef PERIODIC_TABLE_H_
#define PERIODIC_TABLE_H_

class PeriodicTable {
    private:
    /*** The struct that'll hold the elements***/
    struct periodElement {
        std::string elementSymbol;
        std::string elementName;
        int atomicNumber;
        float atomicMass;
        periodElement* next;
        periodElement* prev;

        periodElement(std::string x, std::string y, int z, float f);
    };

    /*** Elements to set up the initial table ***/
    periodElement* frontDummy;
    periodElement* backDummy;
    periodElement* afterCursor;
    periodElement* beforeCursor;
    int currPos;
    int numElements;

    public:
    /*** Constructing the table ***/
    PeriodicTable();

    /*** Deconstructs the table ***/
    ~PeriodicTable();

    /*** Insertion Functions ***/
    void insertElement(std::string x, std::string y, int z, float f);  //  to insert any new periodic elements

    /*** Access functions for the periodic table ***/
    int length() const;  //  for iteration purposes

    std::string symbol() const;  //  returns the elements symbol

    std::string nameOf() const;  //  returns the name of the elements

    int elementPos() const;  //  returns the current elements atomic number

    float elmentWeight() const;  //  returns the elements atomic weight

    /*** Traversal Functions ***/
    void moveFront();  //  moves the cursor to the front of the table

    void moveBack();  //  moves the cursor to the back of the table
    
    void moveNext();  //  moves the cursor to the next element

    void movePrev();  //  moves the cursor to the previous elements

    std::string findElement(std::string x);  //  to find the element that the user is looking for

    /*** Inititializing the table ***/
    void InitTable();
};
#endif