#include <iostream>
#include <string>
#include "knife.h"

using namespace std;


void Knife::getKnife()
{
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "Steel: " << steel << endl;
    cout << "Type: " << type << endl;
    cout << "Notes: " << notes << endl;
    return;
};

string Knife::getMake()
{
    return make;
};

string Knife::getModel()
{
    return model;
};

string Knife::getSteel()
{
    return steel;
};

string Knife::getType()
{
    return type;
};

string Knife::getNotes()
{
    return notes;
};

