/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include<string>
template<class ItemType>
class Stack {
public:
    Stack(int max_size):top(-1){
        size_max=max_size;
        data=new ItemType[size_max];
    }
    bool isEmpty() const {
        return top==-1;
    }
    int getSize() const {
        return top+1;
    }
    bool push(const ItemType& newEntry){
        if(top>=size_max-1){
            return false;
        }
        data[++top] = newEntry;
        return true;
    }
    bool pop(){
        if(isEmpty()){
            return false;
        }
        top--;
        return true;
    }
    ItemType* peek() const{
        if(isEmpty()){
            return nullptr;//default
        }
        return &data[top];
    }
    ~Stack(){
        delete [] data;
    }
    std::string toString(){
        std::string result="";
        for(int i=top;i>=0;i--){
            result+=data[i]->getName();
            result+=",";
        }
        return result;
    }
private:
    ItemType* data;
    int top;
    int size_max;

};

#endif // STACK_H_INCLUDED
