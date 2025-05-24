/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <iostream>
#include <string>

class Vertex {
public:
    Vertex();
    Vertex(std::string s, double w);
    std::string getName();
    double getWeight();
    bool operator<(const Vertex*& right) const;
    bool operator==(const Vertex& right) const;
    void setIsVisited(bool b);
    bool getIsVisited();

private:
    std::string name;
    double weight;
    bool isVisited;
};

#endif // VERTEX_H_INCLUDED
