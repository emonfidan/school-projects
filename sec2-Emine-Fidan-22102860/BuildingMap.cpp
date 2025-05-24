#include "BuildingMap.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Vertex.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

BuildingMap::BuildingMap(const string buildingMapFile){
    inputFile=buildingMapFile;
    allPaths=new LinkedList<string>();
    ifstream buildingMap(buildingMapFile);
    int counter=0;
    if(!buildingMap.is_open()){
        cout<<buildingMapFile<<" cannot be opened."<<endl;
    }
    else{
        string line;
        vertices = new LinkedList<Vertex*>();
        getline(buildingMap, line);
        istringstream firstLine(line);
        int rows, cols;
        firstLine >> rows >> cols;
        int noOfVertices=rows*cols;
        noOfRows=rows;
        noOfCols=cols;
        //initialize adjacencylists and stack
        adjacencyLists=new LinkedList<Vertex*>*[noOfVertices];
        for (int i = 0; i < noOfVertices; i++) {
            adjacencyLists[i] = new LinkedList<Vertex*>();
        }
        mapStack=new Stack<Vertex*>(noOfVertices);

        //int row = 0;
        string lines[rows];
        int i=0;
        while (getline(buildingMap, line)) {
            lines[i]=line;
            i++;
        }
        for(int row=rows-1;row>=0;row--) {
            line=lines[row];
            for (int col = 0; col < cols; ++col) {
                string name= "("+to_string(row)+","+to_string(col)+")";
                Vertex* vertex = new Vertex(name,1);
                vertices->sortInsert(1,vertex);
                int currentIndex=col+row*cols;
                int leftIndex=currentIndex-1;
                int bottomIndex=currentIndex+cols;
                if(line[col]=='0'){
                    string leftName="";
                    string bottomName= "";
                    if(col-1>=0){
                        leftName= "("+to_string(row)+","+to_string(col-1)+")";
                    }
                    if(row+1<rows){
                        bottomName= "("+to_string(row+1)+","+to_string(col)+")";
                    }

                    if(leftName!="" && bottomName!=""){
                        adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(leftName));
                        adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(bottomName));
                        adjacencyLists[leftIndex]->sortInsert(1,vertex);
                        adjacencyLists[bottomIndex]->sortInsert(1,vertex);
                    }
                    else if(leftName!=""){
                        adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(leftName));
                        adjacencyLists[leftIndex]->sortInsert(1,vertex);
                    }
                    else if(bottomName!=""){
                        adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(bottomName));
                        adjacencyLists[bottomIndex]->sortInsert(1,vertex);
                    }

                }
                else if(line[col]=='1'){
                    string bottomName= "";
                    if(row+1<rows){
                        bottomName= "("+to_string(row+1)+","+to_string(col)+")";
                    }
                    if(bottomName!=""){
                        adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(bottomName));
                        adjacencyLists[bottomIndex]->sortInsert(1,vertex);
                    }
                }
                else if(line[col]=='2'){
                    string leftName="";
                    if(col-1>=0){
                        leftName= "("+to_string(row)+","+to_string(col-1)+")";
                    }
                    if(leftName!=""){
                        adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(leftName));
                        adjacencyLists[leftIndex]->sortInsert(1,vertex);
                    }
                }

                //line[col]
            }
            //++row;
        }

        buildingMap.close();

    }
    cout<<noOfRows<<" rows and "<<noOfCols<<" columns have been read.\n";
}
Vertex* BuildingMap::getVertexByName(string name)const{
    for(int pos=1;pos<=vertices->getLength();pos++){
        Vertex* vertex=vertices->getEntry(pos);
        if(vertex->getName()==name){
            return vertex;
        }

    }
    return nullptr;
}
BuildingMap::~BuildingMap(){
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
void BuildingMap::displayAllCubicles() const{
    cout<<"The cubicles in the building are:";
    for(int i=1;i<=vertices->getLength();i++){
        if(i%noOfCols==1){
            cout<<"\n";
        }
        cout<<vertices->getEntry(i)->getName();
        if(i%noOfCols!=0){
            cout<<",";
        }
    }
    cout<<"\n";
}
void BuildingMap::displayAdjacentCubicles(const int row, const int col) const{

    string name= "("+to_string(row)+","+to_string(col)+")";
    cout<<"The cubicles adjacent to "<<name<<" are:\n";
    cout<<name<<" -> "<<adjacencyLists[col+row*noOfCols]->toString();
    if(adjacencyLists[col+row*noOfCols]->getLength()==0){
        cout<<"\n";
    }
}
void BuildingMap::displayBuildingMap() const{
    cout<<"The building map is as follows:"<<endl;
    for(int i=0;i<noOfRows;i++){
        for(int j=0;j<noOfCols;j++){
            string name= "("+to_string(i)+","+to_string(j)+")";
            cout<<name<<" -> "<<adjacencyLists[j+i*noOfCols]->toString();
            if(adjacencyLists[j+i*noOfCols]->getLength()==0){
                cout<<"\n";
            }
        }
    }
}
bool BuildingMap::isAllVerticesVisited()const{
    int i=1;
    while(i<=vertices->getLength()){
        if(vertices->getEntry(i)->getIsVisited()==false){
            return false;
        }
        i++;
    }
    return true;
}
void BuildingMap::setAllVerticesNotVisited(){

    for(int i=1;i<=vertices->getLength();i++){
        vertices->getEntry(i)->setIsVisited(false);
    }

}
void BuildingMap::findPaths(const int startRow, const int startCol, const int endRow, const int endCol){
    string startName= "("+to_string(startRow)+","+to_string(startCol)+")";
    string endName= "("+to_string(endRow)+","+to_string(endCol)+")";
    allPaths->clear();
    setAllVerticesNotVisited();
    Vertex* startVertex=getVertexByName(startName);
    startVertex->setIsVisited(true);
    mapStack->push(startVertex);

    while(!mapStack->isEmpty()){
        Vertex** currentVertex=mapStack->peek();
        LinkedList<Vertex*>* adjacencyList=adjacencyLists[vertices->getPosOf(*currentVertex)-1];
        if(adjacencyList->getLength()==0){
            if((*currentVertex)->getName()==endName){
                string s=mapStack->toString();
                allPaths->sortInsertStr(1,&s);
            }
            mapStack->pop();
        }

        else{

            bool isFirst=true;

            for(int i=1;i<=adjacencyList->getLength();i++){
                if(isFirst && ((*currentVertex)->getName()!=endName) && (!adjacencyList->getEntry(i)->getIsVisited() || adjacencyList->getEntry(i)->getName()==endName) ){

                    adjacencyList->getEntry(i)->setIsVisited(true);
                    mapStack->push(adjacencyList->getEntry(i));
                    isFirst=false;
                    if(adjacencyList->getEntry(i)->getName()==endName){
                        adjacencyList->remove(i);
                    }
                }
            }
            if(isFirst){
                if((*currentVertex)->getName()==endName){
                    string s=mapStack->toString();
                    allPaths->sortInsertStr(1,&s);
                }
                mapStack->pop();


            }

        }
    }
    //displayBuildingMap();
    initializeAdjacencyLists();
    //displayBuildingMap();
    //*********************************************************************************
    if(allPaths->getLength()==0){
        cout<<"Paths from "<<startName<<" to "<<endName<<" are:\nNone\n";
        return ;
    }
    // Check if there are shorter paths and add them
    LinkedList<string> newPaths=LinkedList<string>();

    for (int i = 1; i <= allPaths->getLength(); i++) {

        string path = allPaths->getEntry(i);
        string tempPath=path;

        while(tempPath.length()>0){
            string arry[2];
            string* arr=arry;
            while(getFirstAndLastPairs(path,arr)){
                if (isShorterPathAvailable(arr[0], arr[1])) {
                    string newPath = allPaths->getEntry(i).substr(0, allPaths->getEntry(i).find(arr[0])+arr[0].length())+
                        allPaths->getEntry(i).substr(allPaths->getEntry(i).find(arr[1]), allPaths->getEntry(i).length()+
                        arr[1].length()-allPaths->getEntry(i).find(arr[1]));
                    newPaths.insert(1, newPath);

                }
            }
            deleteFirstPair(tempPath);
            path=tempPath;
        }
    }
    for(int i=1;i<=newPaths.getLength();i++){
        allPaths->sortInsertStr(1, newPaths.getItemTypePtrAt(i)->getNodePtr());
    }
    cout<<"Paths from "<<startName<<" to "<<endName<<" are:\n";

    for(int i=1;i<=allPaths->getLength();i++){
        allPathsToString(allPaths->getEntry(i));
    }
    if(allPaths->getLength()==0){
        cout<<"None\n";
    }

}
void BuildingMap::findPathsWithoutCout(const int startRow, const int startCol, const int endRow, const int endCol){
    string startName= "("+to_string(startRow)+","+to_string(startCol)+")";
    string endName= "("+to_string(endRow)+","+to_string(endCol)+")";
    allPaths->clear();
    setAllVerticesNotVisited();
    Vertex* startVertex=getVertexByName(startName);
    startVertex->setIsVisited(true);
    mapStack->push(startVertex);

    while(!mapStack->isEmpty()){
        Vertex** currentVertex=mapStack->peek();
        LinkedList<Vertex*>* adjacencyList=adjacencyLists[vertices->getPosOf(*currentVertex)-1];
        if(adjacencyList->getLength()==0){
            if((*currentVertex)->getName()==endName){
                string s=mapStack->toString();
                allPaths->sortInsertStr(1,&s);
            }
            mapStack->pop();
        }

        else{

            bool isFirst=true;

            for(int i=1;i<=adjacencyList->getLength();i++){
                if(isFirst && ((*currentVertex)->getName()!=endName) && (!adjacencyList->getEntry(i)->getIsVisited() || adjacencyList->getEntry(i)->getName()==endName) ){

                    adjacencyList->getEntry(i)->setIsVisited(true);
                    mapStack->push(adjacencyList->getEntry(i));
                    isFirst=false;
                    if(adjacencyList->getEntry(i)->getName()==endName){
                        adjacencyList->remove(i);
                    }
                }
            }
            if(isFirst){
                if((*currentVertex)->getName()==endName){
                    string s=mapStack->toString();
                    allPaths->sortInsertStr(1,&s);
                }
                mapStack->pop();


            }

        }
    }
    //displayBuildingMap();
    initializeAdjacencyLists();
    //displayBuildingMap();
    //*********************************************************************************
    if(allPaths->getLength()==0){
        return ;
    }
    // Check if there are shorter paths and add them
    LinkedList<string> newPaths=LinkedList<string>();

    for (int i = 1; i <= allPaths->getLength(); i++) {

        string path = allPaths->getEntry(i);
        string tempPath=path;

        while(tempPath.length()>0){
            string arry[2];
            string* arr=arry;
            while(getFirstAndLastPairs(path,arr)){
                if (isShorterPathAvailable(arr[0], arr[1])) {
                    string newPath = allPaths->getEntry(i).substr(0, allPaths->getEntry(i).find(arr[0])+arr[0].length())+
                        allPaths->getEntry(i).substr(allPaths->getEntry(i).find(arr[1]), allPaths->getEntry(i).length()+
                        arr[1].length()-allPaths->getEntry(i).find(arr[1]));
                    newPaths.insert(1, newPath);

                }
            }
            deleteFirstPair(tempPath);
            path=tempPath;
        }
    }
    for(int i=1;i<=newPaths.getLength();i++){
        allPaths->sortInsertStr(1, newPaths.getItemTypePtrAt(i)->getNodePtr());
    }


}
void BuildingMap::allPathsToString(string str){
    bool isFirstTime=true;
    bool go=true;
    while(go){
        size_t lastStart = str.rfind('(', str.length() - 1);
        if (lastStart == string::npos) {go=false; break;}
        size_t lastEnd = str.rfind(')', str.length() - 1) + 1;
        if (lastEnd == string::npos) {go=false; break;}
        if(isFirstTime){
            isFirstTime=false;
        }
        else{
            cout<<" -> ";
        }
        string lastPair = str.substr(lastStart, lastEnd - lastStart);
        cout<<lastPair;
        str.erase(lastStart, lastPair.length());

    }
    cout<<"\n";
}
void BuildingMap::deleteFirstPair(string& str){
    size_t start = str.find('(');
    if (start == string::npos) return;

    size_t end = str.find(')', start);
    if (end == string::npos) return;

    end++;

    if (end < str.size() && str[end] == ',') {
        end++;
    }

    str.erase(start, end - start);
}
bool BuildingMap::isShorterPathAvailable(const string& startPair, const string& endPair) {
    Vertex* startVertex = getVertexByName(startPair);
    Vertex* endVertex = getVertexByName(endPair);

    int r, c;
    sscanf(startPair.c_str(), "(%d,%d)", &r, &c);
    int adjacencyListIndex = c + r * noOfCols;

    LinkedList<Vertex*>* adjacencyList = adjacencyLists[adjacencyListIndex];
    int index = adjacencyList->getPosOf(endVertex);
    return index != -1 ;
}
bool BuildingMap::getFirstAndLastPairs( string& path,string*& arr) {
    size_t firstStart = path.find('(');
    size_t firstEnd = path.find(')', firstStart) + 1;
    size_t lastStart = path.rfind('(', path.length() - 1);
    size_t lastEnd = path.rfind(')', path.length() - 1) + 1;

    string firstPair = path.substr(firstStart, firstEnd - firstStart);
    string lastPair = path.substr(lastStart, lastEnd - lastStart);
    arr[0]=firstPair;
    arr[1]=lastPair;
    if((firstEnd - firstStart+1 == lastStart)|| firstStart==lastStart){
        return false;
    }
    else{
        path=path.substr(firstStart, lastStart);
    }

}
bool BuildingMap::doesPairExist(string bigstr, string str){
    return bigstr.find(str) != string::npos;
}
void BuildingMap::initializeAdjacencyLists(){
    for (int i = 0; i < noOfCols*noOfRows; i++) {
        adjacencyLists[i]->clear();
    }
    string line;
    ifstream buildingMap(inputFile);
    getline(buildingMap, line);
    istringstream firstLine(line);
    int rows, cols;
    firstLine >> rows >> cols;
    int noOfVertices=rows*cols;

    string lines[rows];
    int i=0;
    while (getline(buildingMap, line)) {
        lines[i]=line;
        i++;
    }
    for(int row=rows-1;row>=0;row--) {
        line=lines[row];
        for (int col = 0; col < cols; ++col) {
            string name= "("+to_string(row)+","+to_string(col)+")";
            Vertex* vertex = getVertexByName(name);
            int currentIndex=col+row*cols;
            int leftIndex=currentIndex-1;
            int bottomIndex=currentIndex+cols;

            if(line[col]=='0'){
                string leftName="";
                string bottomName= "";

                if(row+1<rows){
                    leftName= "("+to_string(row)+","+to_string(col-1)+")";
                }
                if(col-1>=0){
                    bottomName= "("+to_string(row+1)+","+to_string(col)+")";
                }

                if(leftName!="" && bottomName!=""){
                    adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(leftName));
                    adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(bottomName));
                    adjacencyLists[leftIndex]->sortInsert(1,vertex);
                    adjacencyLists[bottomIndex]->sortInsert(1,vertex);
                }
                else if(leftName!=""){
                    adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(leftName));
                    adjacencyLists[leftIndex]->sortInsert(1,vertex);
                }
                else if(bottomName!=""){
                    adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(bottomName));
                    adjacencyLists[bottomIndex]->sortInsert(1,vertex);
                }

            }
            else if(line[col]=='1'){
                string bottomName= "";
                if(row+1<rows){
                    bottomName= "("+to_string(row+1)+","+to_string(col)+")";
                }

                if(bottomName!=""){
                    adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(bottomName));
                    adjacencyLists[bottomIndex]->sortInsert(1,vertex);
                }
            }
            else if(line[col]=='2'){
                string leftName="";
                if(col-1>=0){
                    leftName= "("+to_string(row)+","+to_string(col-1)+")";
                }

                if(leftName!=""){
                    adjacencyLists[currentIndex]->sortInsert(1,getVertexByName(leftName));
                    adjacencyLists[leftIndex]->sortInsert(1,vertex);
                }
            }

            //line[col]
        }
        //++row;
    }

    buildingMap.close();

}
void BuildingMap::findPaths(const int startRow, const int startCol, const int endRow, const int endCol,
const int avoidRow, const int avoidCol){

    findPathsWithoutCout(startRow,startCol,endRow,endCol);
    string s= "("+to_string(avoidRow)+","+to_string(avoidCol)+")";
    cout<<"Paths from ("<<startRow<<","<<startCol<<") to ("<<endRow<<","<<endCol<<") avoiding "<<s<<" are:\n";
    bool b=false;
    for(int i=1;i<=allPaths->getLength();i++){
        if(!doesPairExist(allPaths->getEntry(i),s)){
            allPathsToString(allPaths->getEntry(i));
            b=true;
        }
    }
    if(!b){
        cout<<"None\n";
    }
}
/*int main(){

    BuildingMap bm("input.txt");
    cout << endl;
    bm.displayAllCubicles();
    cout << endl;
    bm.displayAdjacentCubicles(1,1);
    cout << endl;
    bm.displayAdjacentCubicles(2,2);
    cout << endl;
    bm.displayAdjacentCubicles(3,5);
    cout << endl;
    bm.displayBuildingMap();
    cout << endl;
    bm.findPaths(0,0,4,0);
    cout << endl;
    bm.findPaths(0,0,4,0,1,3);
    cout << endl;

    bm.findPaths(0,0,4,0,2,1);
    cout << endl;
    bm.findPaths(3,1,2,4);
    return 0;
}
*/
