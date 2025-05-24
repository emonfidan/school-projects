#ifndef PATHWAY_H_INCLUDED
#define PATHWAY_H_INCLUDED
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Protein.h"
using namespace std;
class Pathway{
public:
    Pathway();
    Pathway(const int pathwayId, const string pathwayName);
    ~Pathway();
    bool operator<(const Pathway& right);
    bool operator==(const Pathway& right);
    int getId();
    LinkedList<Protein>* getPtr();
    string getName();
    void addProtein(const int proteinId);
    void removeProtein(const int proteinId);
    void removeAllProteins();
    Protein* findProteinById(const int proteinId);
    bool doesProteinIdExist(int id);
    void printProteins();
    string toString();
private:
    int id;
    string name;
    LinkedList<Protein> proteins=LinkedList<Protein>();
};


#endif // PATHWAY_H_INCLUDED
