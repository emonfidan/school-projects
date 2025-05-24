/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#include "Map.h"
#include "Stack.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;
Map::Map(const string inputFile):inputFile(inputFile){
    allPaths=new LinkedList<string>();
    ifstream input(inputFile);
    int counter=0;

    if(!input.is_open()){
        cout<<inputFile<<" cannot be opened."<<endl;
    }
    else{

        string line;
        vertices = new LinkedList<Vertex*>();
        getline(input,line);
        int noOfVertices=stoi(line);
        for(int i=0;i<noOfVertices;i++){
            getline(input,line);
            //cout<<line;
            istringstream stream(line);
            string str;
            getline(stream,str,' ');
            Vertex* vertex = new Vertex(str,1);
            vertices->sortInsert(1,vertex);

        }
        adjacencyLists=new LinkedList<Vertex*>*[noOfVertices];
        for (int i = 0; i < noOfVertices; i++) {
            adjacencyLists[i] = new LinkedList<Vertex*>();
        }
        mapStack=new Stack<Vertex*>(noOfVertices);
        input.close();
        readFile(inputFile);

    }
}
void Map::readFile(const string inputFile){
    ifstream input(inputFile);
    if(!input.is_open()){
        cout<<inputFile<<" cannot be opened."<<endl;
    }
    else{
        string line;
        string str;
        string vertexName;
            int noOfAdjacents;
        getline(input,line);
        /*int noOfVertices=stoi(line);
        for(int i=0;i<noOfVertices;i++){
            getline(input,line);
            string vertexName;
            int noOfAdjacents;
            istringstream iss(line);
            string token;

            getline(iss, token, ' ');
            vertexName=token;
            getline(iss, token, ' ');
            noOfAdjacents=stoi(token);
            for(int j=0;j<noOfAdjacents;j++){
                if(j==noOfAdjacents-1){
                    getline(iss, token, ' ');
                    //cout<<line.substr(line.length()-3,2)<<"\n";
                    adjacencyLists[vertices->getPosOf(getVertexByName(vertexName))-1]->sortInsert(1,getVertexByName(token));

                }
                else{
                    getline(iss, token, ' ');
                    //cout<<token;
                    adjacencyLists[vertices->getPosOf(getVertexByName(vertexName))-1]->sortInsert(1,getVertexByName(token));
                }
            }

        }*/
        int noOfVertices=stoi(line);
        int recentBlankIndex=-1;
        for(int i=0;i<noOfVertices;i++){
            getline(input,line);
            string vertexName = line.substr(0, 1);
            int noOfAdjacents = stoi(line.substr(2,1));
            for(int j=4;j<noOfAdjacents*2+4;j+=2){
                str=line.substr(j,1);
                adjacencyLists[vertices->getPosOf(getVertexByName(vertexName))-1]->sortInsert(1,getVertexByName(str));
            }
        }
    }
    input.close();
}
Vertex* Map::getVertexByName(string name)const{
    for(int pos=1;pos<=vertices->getLength();pos++){
        //Vertex** vertex=vertices->getEntry(pos);
        if(vertices->getEntry(pos)->getName()==name){
            return vertices->getEntry(pos);
        }

    }
    return nullptr;

}
Map::~Map(){
    for (int i = 1; i <= vertices->getLength(); i++) {
        delete vertices->getEntry(i);
    }
    for (int i = 0; i < vertices->getLength(); i++) {
        delete adjacencyLists[i];
    }
    delete[] adjacencyLists;
    delete mapStack;
    delete vertices;
    delete allPaths;
}

void Map::initializeAdjacencyLists(){
    for (int i = 0; i < vertices->getLength(); i++) {
        adjacencyLists[i]->clear();
    }
    /*ifstream input(inputFile);
    string line;
    getline(input,line);
    for(int i=0;i<vertices->getLength();i++){
        getline(input,line);
        istringstream stream(line);
        string str;
        getline(stream,str,' ');
        string vertexName = str;
        getline(stream,str,' ');
        int noOfAdjacents = stoi(str);
        for(int j=0;j<noOfAdjacents;j++){
            getline(stream,str,' ');
            adjacencyLists[vertices->getPosOf(getVertexByName(vertexName))-1]->sortInsert(1,getVertexByName(str));
        }
    }
    input.close();*/
    readFile(inputFile);

}
void Map::setAllVerticesNotVisited(){

    for(int i=1;i<=vertices->getLength();i++){
        vertices->getEntry(i)->setIsVisited(false);
    }

}
bool Map::isAllVerticesVisited()const{
    int i=1;
    while(i<=vertices->getLength()){
        if(vertices->getEntry(i)->getIsVisited()==false){
            return false;
        }
        i++;
    }
    return true;
}
string Map::findSafestPath(const std::string startCage, const std::string endCage){
    allPaths->clear();
    setAllVerticesNotVisited();
    Vertex* startVertex=getVertexByName(startCage);
    startVertex->setIsVisited(true);
    mapStack->push(startVertex);

    while(!mapStack->isEmpty()){
        //getVertexByName(endCage)->setIsVisited(false);
        Vertex** currentVertex=mapStack->peek();
        LinkedList<Vertex*>* adjacencyList=adjacencyLists[vertices->getPosOf(*currentVertex)-1];
        if(adjacencyList->getLength()==0){
            if((*currentVertex)->getName()==endCage){
                allPaths->insert(1,mapStack->toString());
            }
            mapStack->pop();
        }

        else{

            bool isFirst=true;

            for(int i=1;i<=adjacencyList->getLength();i++){
                if(isFirst && ((*currentVertex)->getName()!=endCage) && (!adjacencyList->getEntry(i)->getIsVisited() || adjacencyList->getEntry(i)->getName()==endCage) ){

                    adjacencyList->getEntry(i)->setIsVisited(true);
                    mapStack->push(adjacencyList->getEntry(i));
                    isFirst=false;
                    if(adjacencyList->getEntry(i)->getName()==endCage){
                        adjacencyList->remove(i);
                    }
                    //cout<<mapStack->toString();
                }
            }
            if(isFirst){
                if((*currentVertex)->getName()==endCage){
                    allPaths->insert(1,mapStack->toString());
                    //cout<<mapStack->toString()<<"\n";
                }
                mapStack->pop();


            }

        }
    }
    initializeAdjacencyLists();
    //*********************************************************************************
    if(allPaths->getLength()==0){
        cout<<"No path exists from "<<startCage<<" to "<<endCage<<"."<<endl;
        return "";
    }
    int minIndex=1;

    int min= allPaths->getEntry(1).length();
    for(int i=2;i<=allPaths->getLength();i++){
        int nextLength=allPaths->getEntry(i).length();
        if(nextLength<min){
            min=nextLength;
            minIndex=i;
        }

    }

    string str=allPaths->getEntry(minIndex);
    //check if there are shorter loops
    int index=-1 ;
    for(int i=str.length()-2;i>=4;i-=2){
        string name1=str.substr(i,1);
        string name2;
        Vertex* vertex1 = getVertexByName(name1);
        int j;
        for(j=0; j<=i-4;j+=2){
            name2=str.substr(j,1);
            Vertex* vertex2 = getVertexByName(name2);
            LinkedList<Vertex*>* adjacencyList=adjacencyLists[vertices->getPosOf(vertex1)-1];
            index = adjacencyList->getPosOf(vertex2);
            if(index!=-1){
                break;
            }
        }
        if(index!=-1){
            str=str.substr(0,j+2)+str.substr(i,str.length());
        }
    }

    return str;
}
int Map::findDiameter(){
    int diameter=-1;
    for(int i=1;i<vertices->getLength();i++){
        for(int j=i+1;j<=vertices->getLength();j++){
            string str= findSafestPath(vertices->getEntry(i)->getName(),vertices->getEntry(j)->getName());
            int num=str.length()/2-1;
            if(diameter<num){
                diameter=num;
            }
        }
    }
    return diameter;
}
int main(){

    Map m("input.txt");
    string path="";
    string str=m.findSafestPath(integer1,integer2);
    for(int i=str.length()-2;i>=0;i-=2){
        path+=str.substr(i,1)+"\n";
    }
    string result="Path consists of "+to_string(str.length()/2)+" routers:\n";
    result+=path;
    result+="Diameter of the graph is "+to_string(m.findDiameter());

    cout<<result;


    return 0;
}
