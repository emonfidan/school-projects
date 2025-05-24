#include "Gene.h"
#include <iostream>
#include <string>
using namespace std;
Gene::Gene(){
}
Gene::Gene(int i, string n){
    id=i;
    name=n;
}
bool Gene::operator<(const Gene& right){
    if(id<=right.id){
        return true;
    }
    else{
        return false;
    }
}
bool Gene::operator==(const Gene& right){
    if(id==right.id){
        return true;
    }
    else{
        return false;
    }
}
int Gene::getId(){
    return id;
}
string Gene::getName(){
    return name;
}

string Gene::toString(){
    return "";
}
