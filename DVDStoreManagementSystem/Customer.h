#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <iostream>
#include <string>
#include "DVD.h"
using namespace std;
class Customer{
public:
    Customer(const int id,const string str);
    Customer();
    ~Customer();
    bool operator==(Customer right);
    int getCustomerId();
    int getRentedDVD();

    string getName();
    void setCustomerId(int id);
    void setName(string str);

    int getDvdsSize();
    DVD* getDvds();
    void addDvd(DVD dvd);
    bool removeDvd(DVD dvd);
    string toString();

private:
    int customerId;
    string name;
    DVD* dvds;
    int dvdsSize;
};


#endif // CUSTOMER_H_INCLUDED
