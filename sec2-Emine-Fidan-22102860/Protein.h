#ifndef PROTEIN_H_INCLUDED
#define PROTEIN_H_INCLUDED
#include <iostream>
#include <string>
#include "Gene.h"
#include "LinkedList.h"
using namespace std;

class Protein{
public:
    Protein();
    ~Protein();
    Protein(const int id);
    bool operator<(const Protein& right);
    bool operator==(const Protein& right);
    int getId();
    int getGeneNumber();
    LinkedList<Gene>* getPtr();
    void addGene(const int geneID, const string geneName);
    void removeGene(const int geneID);
    string toString();
    void printGenes();
    void removeAllGenes();
    Gene* findGeneById(const int geneID);
private:
    int id;
    LinkedList<Gene> genes=LinkedList<Gene>();
};

#endif // PROTEIN_H_INCLUDED
