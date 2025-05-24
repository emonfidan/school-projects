#ifndef GENE_H_INCLUDED
#define GENE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Gene{
public:
    Gene();
    Gene(int id, string name);
    bool operator<(const Gene& right);
    bool operator==(const Gene& right);
    int getId();
    string getName();
    string toString();
private:
    int id;
    string name;
    int* ptr;

};


#endif // GENE_H_INCLUDED
