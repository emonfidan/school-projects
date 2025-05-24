#include "ZooMap.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

ZooMap::ZooMap(const string cageFile, const string zooFile):zooFile(zooFile){
    ifstream cage(cageFile);
    int counter=0;
    if(!cage.is_open()){
        cout<<cageFile<<" cannot be opened."<<endl;
    }
    else{
        string line;
        vertices = new LinkedList<Vertex*>();
        while(getline(cage,line)){
            istringstream stream(line);
            string name;
            double weight;
            if(getline(stream,name,';') && (stream>>weight)){
                Vertex* vertex = new Vertex(name,weight);
                vertices->sortInsert(1,vertex);
            }
        }
        adjacencyLists=new LinkedList<Vertex*>*[vertices->getLength()];
        for (int i = 1; i <= vertices->getLength(); i++) {
            adjacencyLists[i] = new LinkedList<Vertex*>();
        }

        mapStack=new Stack<Vertex>(vertices->getLength());
        cage.close();
        ifstream zoo(zooFile);
        if(!zoo.is_open()){
            cout<<zooFile<<" cannot be opened."<<endl;
        }
        else{

            string line2;
            string vertexName;
            string edgeName;
            while(getline(zoo,line2)){
            istringstream stream2(line2);

                if(getline(stream2,vertexName,';')&&getline(stream2,edgeName)){
                    adjacencyLists[vertices->getPosOf(getVertexByName(vertexName))]->sortInsert(1,getVertexByName(edgeName));
                    counter++;
                }
            }
            zoo.close();
        }
    }
    cout<<vertices->getLength()<<" cages and "<<counter<<" connections have been loaded."<<endl;
}
/*Vertex** ZooMap::getVertexPtrByName(string name)const{
    for(int pos=1;pos<=vertices->getLength();pos++){
        Vertex** vertex=vertices->getEntry(pos);
        if(vertex->getName()==name){
            return vertex;
        }

    }
    return nullptr;
}*/
Vertex* ZooMap::getVertexByName(string name)const{
    for(int pos=1;pos<=vertices->getLength();pos++){
        Vertex* vertex=vertices->getEntry(pos);
        if(vertex->getName()==name){
            return vertex;
        }

    }

}
ZooMap::~ZooMap(){
    //delete[] adjacencyLists;
}
void ZooMap::displayAllCages() const{
    cout<<"The cages in the zoo are:"<<endl;
    cout<<vertices->toString();
}
void ZooMap::displayAdjacentCages(const string cageName) const{
    cout<<"The cages adjacent to "<<cageName<<" are:"<<endl;
    cout<<cageName<<" -> ";
    cout<<adjacencyLists[vertices->getPosOf(getVertexByName(cageName))]->toString();
}
void ZooMap::onlyDisplayAdjacentCages(const string cageName) const{
    cout<<cageName<<" -> ";
    cout<<adjacencyLists[vertices->getPosOf(getVertexByName(cageName))]->toString();
}
void ZooMap::displayZooMap() const{
    cout<<"The whole zoo map is:"<<endl;
    for(int i=1;i<=vertices->getLength();i++){
        string cageName=vertices->getEntry(i)->getName();
        onlyDisplayAdjacentCages(cageName);
    }
}
void ZooMap::findAllPaths(const string startCage, const string endCage, LinkedList<string>* allPaths){


    setAllVerticesNotVisited();

    Vertex* startVertex=getVertexByName(startCage);
    startVertex->setIsVisited(true);
    mapStack->push(*startVertex);
    //cout<<mapStack->toString();
    while(!mapStack->isEmpty()){
        //getVertexByName(endCage)->setIsVisited(false);
        Vertex* currentVertex=mapStack->peek();
        LinkedList<Vertex*>* adjacencyList=adjacencyLists[vertices->getPosOf(currentVertex)];

        if(adjacencyList->getLength()==0){
            if(currentVertex->getName()==endCage){
                allPaths->insert(1,mapStack->toString());
            }
            mapStack->pop();
        }

        else{

            bool isFirst=true;
            for(int i=1;i<=adjacencyList->getLength();i++){

                if(isFirst && (currentVertex->getName()!=endCage) && (!adjacencyList->getEntry(i)->getIsVisited() || adjacencyList->getEntry(i)->getName()==endCage) ){

                    adjacencyList->getEntry(i)->setIsVisited(true);
                    mapStack->push(*(adjacencyList->getEntry(i)));
                    isFirst=false;
                    if(adjacencyList->getEntry(i)->getName()==endCage){
                        adjacencyList->remove(i);
                    }
                    //cout<<mapStack->toString();
                }
            }
            if(isFirst){
                if(currentVertex->getName()==endCage){
                    allPaths->insert(1,mapStack->toString());
                }
                mapStack->pop();


            }

        }

    }
    initializeAdjacencyLists();

}
void ZooMap::initializeAdjacencyLists(){
    for (int i = 1; i <= vertices->getLength(); i++) {
        adjacencyLists[i]->clear();
    }
    ifstream zoo(zooFile);
    if (!zoo.is_open()) {
        cout << zooFile << " cannot be opened." << endl;
    } else {
        string line;
        string vertexName;
        string edgeName;
        while (getline(zoo, line)) {
            istringstream stream(line);

            if (getline(stream, vertexName, ';') && getline(stream, edgeName)) {
                adjacencyLists[vertices->getPosOf(getVertexByName(vertexName))]->sortInsert(1, getVertexByName(edgeName));
            }
        }
        zoo.close();
    }
}
void ZooMap::setAllVerticesNotVisited(){

    for(int i=1;i<=vertices->getLength();i++){
        vertices->getEntry(i)->setIsVisited(false);
    }
    /*for(int j=0;j<vertices->getLength();j++){
        for(int k=1;k<=adjacencyLists[j]->getLength();k++){
            adjacencyLists[j]->getItemTypePtrAt(k)->getNodePtr()->setIsVisited(false);
        }
    }*/
}
bool ZooMap::isAllVerticesVisited()const{
    int i=1;
    while(i<=vertices->getLength()){
        if(vertices->getEntry(i)->getIsVisited()==false){
            return false;
        }
        i++;
    }
    return true;
}
void ZooMap::findSafestPath(const std::string startCage, const std::string endCage){

    LinkedList<string>* allPaths=new LinkedList<string>();
    findAllPaths(startCage,endCage,allPaths);
    if(allPaths->getLength()==0){
        cout<<"No path exists from "<<startCage<<" to "<<endCage<<"."<<endl;
        return;
    }
    double products[allPaths->getLength()];
    for(int i=1;i<=allPaths->getLength();i++){
        double product=1;
        string input=allPaths->getEntry(i);
        istringstream ss(input);
        string token;
        while (getline(ss, token, ',')) {
            product*=getVertexByName(token)->getWeight();
        }
        products[i-1]=product;
    }

    int maxIndex=0;
    double max=products[0];
    for(int i=1;i<allPaths->getLength();i++){
        if(products[i]>max){
            max=products[i];
            maxIndex=i;
        }
    }

    cout<<"Safest path from "<<startCage<<" to "<<endCage<<" is:"<<endl;
    string str=allPaths->getEntry(maxIndex+1);
    bool isFirst=true;
    for(int i=str.length()-2;i>=0;i-=2){
        if(isFirst){
            isFirst=false;
        }
        else{
            cout<<"-> ";
        }
        cout<<str.substr(i,1)<<" ";
    }
    cout<<"\nProbability: "<< fixed << setprecision(6) << max << endl;
}
void ZooMap::findMostDangerousPath(const string startCage, const string endCage){
    LinkedList<string>* allPaths=new LinkedList<string>();
    findAllPaths(startCage,endCage,allPaths);
    if(allPaths->getLength()==0){
        cout<<"No path exists from "<<startCage<<" to "<<endCage<<"."<<endl;
        return;
    }
    double products[allPaths->getLength()];
    for(int i=1;i<=allPaths->getLength();i++){
        double product=1;
        string input=allPaths->getEntry(i);
        istringstream ss(input);
        string token;
        while (getline(ss, token, ',')) {
            product*=getVertexByName(token)->getWeight();
        }
        products[i-1]=product;
    }

    int minIndex=0;
    double min=products[0];
    for(int i=1;i<allPaths->getLength();i++){
        if(products[i]<min){
            min=products[i];
            minIndex=i;
        }
    }

    cout<<"Most dangerous path from "<<startCage<<" to "<<endCage<<" is:"<<endl;
    string str=allPaths->getEntry(minIndex+1);
    bool isFirst=true;
    for(int i=str.length()-2;i>=0;i-=2){
        if(isFirst){
            isFirst=false;
        }
        else{
            cout<<"-> ";
        }
        cout<<str.substr(i,1)<<" ";
    }
    cout<<"\nProbability: "<< fixed << setprecision(6) << min << endl;
}
int main(){

    ZooMap zm("cage.txt", "zoo.txt");
    zm.displayAllCages();
    cout << endl;
    zm.displayAdjacentCages("E");
    cout << endl;
    zm.displayAdjacentCages("C");
    cout << endl;
    zm.displayZooMap();
    cout << endl;
    zm.findSafestPath("E", "A");
    cout << endl;
    zm.findSafestPath("D", "C");
    cout << endl;
    zm.findMostDangerousPath("E", "A");
    cout << endl;
    zm.findMostDangerousPath("D", "C");
    cout << endl;
    zm.findMostDangerousPath("C", "F");

    return 0;
}
