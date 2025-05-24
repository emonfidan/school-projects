/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#include "RegularUser.h"
RegularUser::RegularUser(){
    id=-1;
    name="does not exist";
}
RegularUser::RegularUser(int i, string s){
    id=i;
    name=s;
}
bool RegularUser::operator<(const RegularUser& right){
    if(id<=right.id){
        return true;
    }
    else{
        return false;
    }
}
int RegularUser::getId(){
    return id;
}
string RegularUser::getName(){
    return name;
}

