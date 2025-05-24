#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;
Customer::Customer(const int id, const string str){
    customerId=id;
    name=str;
    dvds=nullptr;
    dvdsSize=0;
}
Customer::Customer(){
    dvds=nullptr;
    dvdsSize=0;
}
Customer::~Customer(){
    if(dvds!=nullptr){
        delete[] dvds;
    }
}
bool Customer::operator==(Customer right){
    if(this->customerId==right.customerId){
        return true;
    }
    return false;
}
void Customer::setCustomerId(int id){
    customerId=id;
}
void Customer::setName(string str){
    name=str;
}


int Customer::getCustomerId(){
    return customerId;
}
string Customer::getName(){
    return name;
}
int Customer::getDvdsSize(){
    return dvdsSize;
}
DVD* Customer::getDvds(){
    return dvds;
}
void Customer::addDvd(DVD dvd){
    DVD* newDvds = new DVD[dvdsSize+1];
    for(int i=0;i<dvdsSize;i++){
        //newCustomers[i]->setCustomerId(customers[i].getCustomerId());
        //newCustomers[i]->setName(customers[i].getName());
        newDvds[i]=dvds[i];
    }
    newDvds[dvdsSize]=dvd;
    if(dvds!=nullptr)
    delete[] dvds;
    dvdsSize++;
    dvds=newDvds;
    dvd.setRented(true);

}
bool Customer::removeDvd(DVD dvd){
    bool remove=false;
    if(dvdsSize==0)
        return remove;
    DVD* newDvds;
    if(dvdsSize==1){
        if(*dvds==dvd){
            dvdsSize--;
            delete dvds;
            dvds=nullptr;
            return true;
        }
        else{
            return false;
        }
    }
    else{
        newDvds = new DVD[dvdsSize-1];
    }
    int j=0;
    for(int i=0;i<dvdsSize-1;i++){
        //newCustomers[i]->setCustomerId(customers[i].getCustomerId());
        //newCustomers[i]->setName(customers[i].getName());
        if(dvds[i]==dvd){
            remove=true;
        }
        else{
            newDvds[j]=dvds[i];
            j++;
        }
    }
    if(remove){
        if(dvds!=nullptr)
            delete[] dvds;
        dvdsSize--;
        dvds=newDvds;
        dvd.setRented(false);
    }

    return remove;
}
string Customer::toString(){
    return "Customer: "+to_string(customerId)+", Name: "+name+", DVDs Rented: "+to_string(dvdsSize)+"\n";
}
