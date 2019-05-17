/*Knife Database v1.0
 *A simple tool to help me catalog my knife collection
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

#include "knife.h"
#include "knife.cpp"
#include "functions.h"
#include "functions.cpp"

using namespace std;

int main ()
{

    ifstream fin;
    ofstream fout;
    fin.open("Catalog.txt");
    if(fin.fail())
    {
        cout << "Failed to open file 1. Exiting." << endl;
        return -1;
    }

    fout.open("Catalog.txt", std::ios::app);
    if(fout.fail())
    {
        cout << "Failed to open file 2. Exiting." << endl;
        return -1;
    }
    vector<Knife> kvec;
    vector<Knife> newKnives;
    int choice = 0;

    //If a user deletes one of the knives loaded from the file
    //the file must be overwritten and then loaded with the
    //modified kvec vector. This int holds the original size of
    //kvec.
    loadKnives(kvec, fin);
    int kvecState = kvec.size();

    // Operate the program until the user chooses "Exit program."
    do
    {
        //Print the menu
        printMenu();

        //Get  the user's choice from the menu
        //Make sure it is within the menu's range
        do
        {
            cout << "Enter your choice: ";
            cin >> choice;

            //Process the choice
            processChoice(choice, kvec, newKnives);

           //Ask them to enter another choice if their first was invalid.
            if(choice < 1 || choice > 5)
                    cout << "Invalid Choice. Try again." << endl;

        }while(choice < 1 || choice > 5);
    }while(choice != 5);

    //Overwrite the file if a user has deleted an item from it.
    if(kvec.size() != kvecState)
    {
        //Clear the catalog file
        //and reload it with kvec and newKnives
        fout.close();
        fout.open("Catalog.txt");

        addKnives(kvec, fout);

        if(newKnives.size());
            addKnives(newKnives, fout);
    }
    else
        addKnives(newKnives, fout);

    fin.close();
    fout.close();

    return 0;
}
