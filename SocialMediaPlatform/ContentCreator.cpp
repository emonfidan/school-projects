/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#include "ContentCreator.h"
#include <iostream>
using namespace std;
ContentCreator::ContentCreator(){

}
ContentCreator::ContentCreator(int i, string s){
    id=i;
    name=s;
}
int ContentCreator::getId(){
    return id;
}
string ContentCreator::getName(){
    return name;
}
bool ContentCreator::operator<(const ContentCreator& right){
    if(id<=right.id){
        return true;
    }
    else{
        return false;
    }
}
void ContentCreator::addContent(Content c){
    contents.sortInsert(1,c);
}
void ContentCreator::addFollower(int i){
    followerIds.sortInsert(1,i);
}
int ContentCreator::doesContentExist(int id ) const{
    if(contents.isEmpty()){
        return -1;
    }
    else {
        int i=1;
        while(i<=contents.getLength()){
            if(contents.getEntry(i).getId()==id){
                return i;
            }

            i++;
        }
        return -1;

    }
}
int ContentCreator::doesFollowerExist(int id ) const{
    if(followerIds.isEmpty()){
        return -1;
    }
    else {
        int i=1;
        while(i<=followerIds.getLength()){
            if(followerIds.getEntry(i)==id){
                return i;
            }
            i++;
        }
        return -1;

    }
}
void ContentCreator::removeContent(int pos){
    contents.remove(pos);
}
void ContentCreator::removeFollower(int pos){
    followerIds.remove(pos);
}
int ContentCreator::getFollowerNumber(){
    return followerIds.getLength();
}
int ContentCreator::getContentNumber(){
    return contents.getLength();
}
int ContentCreator::getFollowerIdAt(int pos){
    return followerIds.getEntry(pos);
}
int ContentCreator::getContentIdAt(int pos){
    return contents.getEntry(pos).getId();
}
