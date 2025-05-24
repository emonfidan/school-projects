#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class Hash{
public:
    Hash(string str, int i){
        key=str;
        value=i;
    }
    string getKey(){
        return key;
    }
    int getValue(){
        return value;
    }
private:
    string key;
    int value;
};

#endif // HASH_H_INCLUDED
