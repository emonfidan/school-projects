/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#ifndef CONTENT_H_INCLUDED
#define CONTENT_H_INCLUDED
#include <iostream>
using namespace std;
class Content{
public:
    Content();
    Content(int i, string title);
    int getId();
    bool operator<(const Content& right);
private:
    int id;
    string title;
};


#endif // CONTENT_H_INCLUDED
