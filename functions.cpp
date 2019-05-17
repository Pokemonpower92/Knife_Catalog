#include <iostream>
#include "functions.h"
#include <vector>
#include <sstream>

//Appends a vector of knives to the outfile.
void addKnives(std::vector<Knife>& newKnives, ofstream& fout)
{
    for(int i = 0; i != newKnives.size(); i++)
    {
        std::string temp = newKnives[i].make + " " + newKnives[i].model + " " + newKnives[i].steel
                                        + " " + newKnives[i].type + " " + newKnives[i].notes;
        fout << temp;
        fout << std::endl;
    }
}
void deleteKnife(std::vector<Knife>& kvec, std::vector<Knife>& newKnives)
{
    std::vector<Knife> total = kvec;
    int choice = -2;

    //If newKnives isn't empty add each element to the master knife vector
    if(newKnives.size())
        for(int i = 0; i != newKnives.size(); i++)
            total.push_back(newKnives[i]);

    //Print out the full list of knives
    for(int i = 0; i != total.size(); i++)
    {
        std::cout << (i + 1) << std::endl;
        total[i].getKnife();
    }
    //Ask the user to specify the knife to be deleted.
    //Entering "0" will close the delete function
    do
    {
        std::cout << "Enter the number of the knife you wish to delete. Enter '0' to exit: ";
        std::cin    >> choice;
        std::cout << std::endl;
    }while((choice < -1) || choice > (kvec.size() + newKnives.size()));

    if(choice != 0)
    {
        if (choice > kvec.size())
            newKnives.erase(newKnives.begin() + ((choice -1) - kvec.size()));
        else
            kvec.erase(kvec.begin() + (choice - 1));
    }

    for(int i = 0; i != kvec.size(); i++)
        kvec[i].getKnife();
    for(int i = 0; i != newKnives.size(); i++)
        newKnives[i].getKnife();
}

void enterKnife(std::vector<Knife>& newKnives)
{
    //Get the details of the new knife from user.
    std::string make, model, steel, type, notes;

    std::cout << "Enter the make: ";
    std::cin    >> make;
    std::cout << "Enter the model: ";
    std::cin    >> model;
    std::cout << "Enter the steel: ";
    std::cin    >> steel;
    std::cout << "Enter the type: ";
    std::cin    >> type;
    std::cin.ignore();
    std::cout << "Enter any notes: ";
    std::getline(std::cin, notes);
    std::cout << std::endl;

    //Initialize a new Knife object with user parameters
    Knife newKnife = Knife(make, model, steel, type, notes);
    newKnives.push_back(newKnife);
}
void loadKnives(std::vector<Knife>& kvec, ifstream& fin)
{
    /* Each knife is stored as a single string on the same line
      * in the catalog.txt file.
      * This function pushes each back into kvec
    */
    std::string nextString;
    std::string noteString;
    std::string make, model, steel, type;

    while(std::getline(fin, nextString))
    {
        std::istringstream knife(nextString);
        knife >> make >> model >> steel >> type;
        std::getline(knife, noteString);
        Knife newKnife = Knife(make, model, steel, type, noteString.substr(1));
        kvec.push_back(newKnife);
    }
}
void printKnives(std::vector<Knife>& kvec, std::vector<Knife>& newKnives)
{
    for(int i = 0; i != kvec.size(); i++)
    {
        kvec[i].getKnife();
        std::cout << std::endl;
    }
    for(int i = 0; i != newKnives.size(); i++)
    {
        newKnives[i].getKnife();
         std::cout << std::endl;
    }
}
void printMenu()
{
    std::cout << "**********--------------**********" << std::endl << std::endl;
    std::cout << "          Knife Database" << std::endl << std::endl;
    std::cout << "**********--------------**********" << std::endl << std::endl;

    std::cout << "             Main menu" << std::endl << std:: endl;
    std::cout << "1: Enter a new knife." << std::endl;
    std::cout << "2: Delete a knife." << std::endl;
    std::cout << "3: Search by make." << std::endl;
    std::cout << "4: Print all knives." << std::endl;
    std::cout << "5: Exit." << std::endl;
    std::cout << endl;
    std::cout << "**********************************" << std::endl;
}
void processChoice(int choice, std::vector<Knife>& kvec, std::vector<Knife>& newKnives)
{
    switch(choice)
    {
        case 1:
            std::cout << std::endl;
            enterKnife(newKnives);
            break;
        case 2:
            std::cout << std::endl;
            deleteKnife(kvec, newKnives);
            break;
        case 3:
            std::cout << std::endl;
            searchMake(kvec, newKnives);
            break;
        case 4:
            std::cout << std::endl;
            printKnives(kvec, newKnives);
            std::cout << std::endl;
            break;
    }
}
//Searches both kvec and newKnives for knives by a specific maker
void searchMake(std::vector<Knife>& kvec, std::vector<Knife>& newKnives)
{
    std::string make = "";

    std::cout << "Enter a make to search for. (Capitalize the first letter): ";
    std::cin    >> make;
    std::cout << std::endl;

    for(int i = 0; i != kvec.size(); i++)
        if(make == kvec[i].make)
            kvec[i].getKnife();
    for(int i = 0; i != newKnives.size(); i++)
        if(make == newKnives[i].make)
            newKnives[i].getKnife();
}
