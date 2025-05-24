/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "LinkedList.h"
#include "Vertex.h"
#include "Stack.h"
#include <iostream>
#include<string>
class Map {
public:
    Map(const std::string inputFile);
    ~Map();
    std::string findSafestPath(const std::string startCage, const std::string endCage);
    //LinkedList<std::string>* findAllPaths(const std::string startCage, const std::string endCage);
    Vertex** getVertexPtrByName(std::string name)const;
    Vertex* getVertexByName(std::string name)const;
    bool isAllVerticesVisited()const;
    void setAllVerticesNotVisited();
    void initializeAdjacencyLists();
    int findDiameter();
    void readFile(const std::string inputFile);
private:
    Stack<Vertex*>* mapStack; //stack used to implement depth-first algorithm
    LinkedList<Vertex*>** adjacencyLists; //adjacency lists array pointer
    LinkedList<Vertex*>* vertices;
    std::string inputFile;
    LinkedList<std::string>* allPaths;

};

#endif // MAP_H_INCLUDED
