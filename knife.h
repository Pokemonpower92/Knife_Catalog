#ifndef KNIFE_H_INCLUDED
#define KNIFE_H_INCLUDED

class Knife {

public:

    std::string make, model, steel, type, notes;

   Knife() = default;
   Knife(std::string m, std::string md, std::string s, std::string t, std::string n): make(m), model(md), steel(s), type(t), notes(n) {}

    void getKnife();
    std::string getMake();
    std::string getModel();
    std::string getSteel();
    std::string getType();
    std::string getNotes();

};

#endif // KNIFE_H_INCLUDED
