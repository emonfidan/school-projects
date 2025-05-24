#ifndef TWOTUPLES_H_INCLUDED
#define TWOTUPLES_H_INCLUDED
#include <iostream>
#include <string>
#include "Tuple.h"
class TwoTuples{
public:
    TwoTuples(){
        id=0;
        length=0;
    }
    TwoTuples(Tuple* tupl1,Tuple* tupl2, int leng,int i){
        tuple1=tupl1;
        tuple2=tupl2;
        length=leng;
        id=i;
    }
    Tuple* getTupleArr1(){
        return tuple1;
    }
    Tuple* getTupleArr2(){
        return tuple2;
    }
    /*std::string getStr(){
        return str;
    }*/
    int getLength(){
        return length;
    }
    int getId(){
        return id;
    }

private:
    Tuple* tuple1;
    Tuple* tuple2;
    int length;
    int id;
};




#endif // TWOTUPLES_H_INCLUDED
