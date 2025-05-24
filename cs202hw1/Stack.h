/**
* Title: Binary Search Trees
* Author : Emine Fidan
* ID: 22102860
* Section : 2
* Homework : 1
* Description : stack source file
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
    Stack& operator=(const Stack& right){
        //std::cout<<"operator = is called";
        if(&right != this){
            if(size_max!= right.size_max){
                if(size_max>0){
                    delete[] data;
                }
                size_max=right.size_max;
                if(size_max>0){
                    data= new ItemType[size_max];
                }
                else{
                    data=nullptr;
                }
            }
            for(int i=0;i<size_max;i++){
                data[i]=right.data[i];
            }
            top=right.top;
        }
        return *this;
    }
    bool isEmpty() const {
        return top==-1;
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
        if(data!=nullptr){
            delete [] data;
            data=nullptr;
        }
    }
    std::string toStringInReverse(){
        std::string result="";
        for(int i=top;i>=0;i--){
            result+=std::to_string(data[i]->data);
            result+=", ";
        }
        return result;
    }
    std::string toString(){
        std::string result="";
        for(int i=1;i<=top;i++){
            result+=std::to_string(data[i]->data);
            if(i!=top){
                result+=", ";
            }

        }
        return result+"\n";
    }
    std::string toString2(){
        std::string result="";
        for(int i=0;i<=top;i++){
            result+=std::to_string(data[i]->data);
            if(i!=top){
                result+=", ";
            }

        }
        return result+"\n";
    }
    std::string toString3(){ //sorted display
        std::string result="";
        int arr[top+1];
        for(int i=0;i<=top;i++){
            arr[i]=data[i]->data;
        }
        for(int i=0;i<=top;i++){
            for(int j=0;j<top;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }

        }
        for(int i=0;i<=top;i++){
            result+=std::to_string(arr[i]);
            if(i!=top){
                result+=", ";
            }

        }
        return result+"\n";
    }
    int sumOfStackItems(){
        int result=0;
        for(int i=top;i>=0;i--){
            result+=data[i]->data;
        }
        return result;
    }
    int getSize(){
        return ++top;
    }
private:
    ItemType* data;
    int top;
    int size_max;

};

#endif // STACK_H_INCLUDED
