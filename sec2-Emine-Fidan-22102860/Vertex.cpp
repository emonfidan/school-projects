/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#include "Vertex.h"
#include "PrecondViolatedExcept.h"

Vertex::Vertex(){
    name="";
    weight=0;
    isVisited=false;
}
Vertex::Vertex(std::string s,double w ){
    name=s;
    weight=w;
    isVisited=false;
}
double Vertex::getWeight(){
    return weight;
}
std::string Vertex::getName(){
    return name;
}
bool Vertex::operator<(const Vertex*& right)const{

    try{
        if(right!=nullptr){
            return name < (*right).name;
        }
        else{
            std::string msg = "getEntry() called with an empty list or invalid position. \n";
            throw PrecondViolatedExcept(msg);
        }

    }
    catch(const PrecondViolatedExcept& e){
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return false;
    }
}
bool Vertex::operator==(const Vertex& right)const{
    //bool b=(name.compare(right.name)==0);
    //std::cout<<"is string equal "<< b;
    return name.compare(right.name)==0;

}
void Vertex::setIsVisited(bool b){
    isVisited=b;
}
bool Vertex::getIsVisited(){
    return isVisited;
}
