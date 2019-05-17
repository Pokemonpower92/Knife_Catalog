#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void addKnives(std::vector<Knife>&, ofstream&);
void deleteKnife(std::vector<Knife>&, std::vector<Knife>&);
void enterKnife(std::vector<Knife>&);
void loadKnives(std::vector<Knife>&, ifstream&);
void printKnives(std::vector<Knife>&, std::vector<Knife>&);
void printMenu();
void processChoice(int, std::vector<Knife>&);
void searchMake(std::vector<Knife>&, std::vector<Knife>&);

#endif // FUNCTIONS_H_INCLUDED
