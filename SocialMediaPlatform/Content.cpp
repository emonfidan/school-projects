/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#include "Content.h"
#include <iostream>
using namespace std;
Content::Content(){

}
Content::Content(int i,string tit){
    id=i;
    title=tit;
}
int Content::getId(){
    return id;
}
bool Content::operator<(const Content& right){
    if(id<=right.id){
        return true;
    }
    else{
        return false;
    }
}
