#ifndef BUILDINGMAP_H_INCLUDED
#define BUILDINGMAP_H_INCLUDED
#include "LinkedList.h"
#include "Vertex.h"
#include "Stack.h"
#include <iostream>
#include<string>
using namespace std;
class BuildingMap {
public:
    BuildingMap(const string buildingMapFile);
    ~BuildingMap();
    void displayAllCubicles() const;
    void displayAdjacentCubicles(const int row, const int col) const;
    void displayBuildingMap() const;
    void findPaths(const int startRow, const int startCol, const int endRow, const int endCol);
    void findPathsWithoutCout(const int startRow, const int startCol, const int endRow, const int endCol);
    void findPaths(const int startRow, const int startCol, const int endRow, const int endCol,
    const int avoidRow, const int avoidCol);
    Vertex* getVertexByName(string name)const;
    void initializeAdjacencyLists();
    bool isAllVerticesVisited()const;
    void setAllVerticesNotVisited();
    bool getFirstAndLastPairs( string& path,string*& arr) ;
    void deleteFirstPair(string& tempPath);
    bool doesPairExist(string bigstr, string str);
    void allPathsToString(string str);
    bool isShorterPathAvailable(const string& startPair, const string& endPair);
private:
    Stack<Vertex*>* mapStack; //stack used to implement depth-first algorithm
    LinkedList<Vertex*>** adjacencyLists; //adjacency lists array pointer
    LinkedList<Vertex*>* vertices;
    std::string inputFile;
    LinkedList<std::string>* allPaths;
    int noOfRows;
    int noOfCols;
};

#endif // BUILDINGMAP_H_INCLUDED
