/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#ifndef REGULARUSER_H_INCLUDED
#define REGULARUSER_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class RegularUser{
public:
    RegularUser();
    RegularUser(int id,string name);
    bool operator<(const RegularUser& right);
    int getId();
    string getName();

private:
    int id;
    string name;
};


#endif // REGULARUSER_H_INCLUDED
