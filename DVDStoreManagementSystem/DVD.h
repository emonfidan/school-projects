#ifndef DVD_H_INCLUDED
#define DVD_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class DVD{
public:
    DVD(const string no,const string tit,const string dir);
    DVD();
    ~DVD();
    bool operator==(DVD right);
    string getSerialNo();
    string getTitle();
    string getDirector();
    string toString();
    void setRented(bool b);
    bool getRented();

private:
    string serialNo;
    string title;
    string director;
    bool rented;


};


#endif // DVD_H_INCLUDED
