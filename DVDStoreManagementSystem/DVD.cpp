#include <iostream>
#include <string>
#include "DVD.h"
#include "Customer.h"
using namespace std;
DVD::DVD(const string no,const string tit,const string dir){
    serialNo=no;
    title=tit;
    director=dir;
    rented=false;
}
DVD::DVD(){
    rented=false;
}
DVD::~DVD(){

}
bool DVD::operator==(DVD right){
    if(this->serialNo==right.serialNo){
        return true;
    }
    return false;
}
string DVD::getSerialNo(){
    return serialNo;
}
string DVD::getTitle(){
    return title;
}
string DVD::getDirector(){
    return director;
}

string DVD::toString(){
    string str= "DVD: "+serialNo+", Title: "+title+", Director: "+director+", ";
    if(!rented)
        str+="Available";
    else
        str+="Rented";
    return str+"\n";
}
void DVD::setRented(bool b){
    rented=b;
}
bool DVD::getRented(){
    return rented;
}

