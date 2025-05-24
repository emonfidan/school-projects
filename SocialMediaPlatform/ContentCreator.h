/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#ifndef CONTENTCREATOR_H_INCLUDED
#define CONTENTCREATOR_H_INCLUDED
#include "LinkedList.h"
#include "Content.h"
#include "RegularUser.h"
#include <iostream>
using namespace std;
class ContentCreator{
public:
    ContentCreator();
    ContentCreator(int id,string name);
    int getId();
    string getName();
    bool operator<(const ContentCreator& right);
    void addContent(Content c);
    void addFollower(int i);
    int doesContentExist(int id )const;
    int doesFollowerExist(int id )const;
    void removeContent(int pos);
    void removeFollower(int pos);
    int getFollowerNumber();
    int getContentNumber();
    int getFollowerIdAt(int pos);
    int getContentIdAt(int pos);
private:
    int id;
    string name;
    LinkedList<int> followerIds;
    LinkedList<Content> contents;
};


#endif // CONTENTCREATOR_H_INCLUDED
