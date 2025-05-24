/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#include "SocialMediaPlatform.h"
#include "LinkedList.h"
#include "RegularUser.h"
#include "ContentCreator.h"
#include "Content.h"
#include "Node.h"
#include <iostream>
using namespace std;
SocialMediaPlatform::SocialMediaPlatform(){
    regularUsers = LinkedList<RegularUser>();
}
SocialMediaPlatform::~SocialMediaPlatform(){

}
void SocialMediaPlatform::addRegularUser( const int regularUserId, const string name ){
    if(doesRegularUserIdExist(regularUserId)!=-1){
        cout<<"Cannot add regular user. There is already a regular user with ID "<<regularUserId<<"."<<endl;
    }
    else{
        regularUsers.sortInsert(1,RegularUser(regularUserId,name));
        cout<<"Added regular user "<<regularUserId<<"."<<endl;
    }
}
int SocialMediaPlatform::doesRegularUserIdExist(int id ) const{

    if(regularUsers.isEmpty()){
        return -1;
    }
    else {

        int i=1;
        while(i<=regularUsers.getLength()){
            if(regularUsers.getEntry(i).getId()==id){
                return i;
            }

            i++;
        }
        return -1;

    }
}
int SocialMediaPlatform::doesContentCreatorIdExist(int id ) const{
    if(contentCreators.isEmpty()){
        return -1;
    }
    else {
        int i=1;
        while(i<=contentCreators.getLength()){
            if(contentCreators.getEntry(i).getId()==id){
                return i;
            }

            i++;
        }
        return -1;

    }
}
int SocialMediaPlatform::doesContentIdExist(int id ) const{
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
void SocialMediaPlatform::removeRegularUser( const int regularUserId ){
    int pos=doesRegularUserIdExist(regularUserId);
    if(pos != -1){
        removeFromFollowerLists(regularUserId);
        regularUsers.remove(pos);
        cout<<"Removed regular user "<<regularUserId<<"."<<endl;
    }
    else{
        cout<<"Cannot remove regular user. There is no regular user with ID "<<regularUserId<<"."<<endl;
    }
}
void SocialMediaPlatform::removeFromFollowerLists(int id)const{
    int i=1;
    while(i<=contentCreators.getLength()){
        int j=1;
        ContentCreator* cc = contentCreators.getItemTypePtrAt(i)->getNodePtr();
        while (j<=cc->getFollowerNumber()){
            if(cc->getFollowerIdAt(j)==id){
                cc->removeFollower(j);
            }
            j++;
        }
        i++;
    }
}
void SocialMediaPlatform::addContentCreator( const int contentCreatorId, const string name ){
    if(doesContentCreatorIdExist(contentCreatorId)!=-1){
        cout<<"Cannot add content creator. There is already a content creator with ID "<<contentCreatorId<<"."<<endl;
    }
    else{
        contentCreators.sortInsert(1,ContentCreator(contentCreatorId,name));
        cout<<"Added content creator "<<contentCreatorId<<"."<<endl;
    }
}
void SocialMediaPlatform::removeContentCreator( const int contentCreatorId ){
    int pos=doesContentCreatorIdExist(contentCreatorId);
    if(pos != -1){
        removeAllContentsOf(contentCreatorId,pos);
        contentCreators.remove(pos);
        cout<<"Removed content creator "<<contentCreatorId<<"."<<endl;
    }
    else{
        cout<<"Cannot remove content creator. There is no content creator with ID "<<contentCreatorId<<"."<<endl;
    }
}
void SocialMediaPlatform::removeAllContentsOf(int contentorId, int contentorPos){
    ContentCreator c=contentCreators.getEntry(contentorPos);
    int i=1;
    while(i<=c.getContentNumber()){
        implicitlyRemoveContent(contentorId,c.getContentIdAt(i));
        i++;
    }
}

void SocialMediaPlatform::addContent( const int contentCreatorId, const int contentId, const string
title ){
    int contentorPos=doesContentCreatorIdExist(contentCreatorId);
    if(doesContentIdExist(contentId)!=-1){
        cout<<"Cannot add content. There is already a content with ID "<<contentId<<"."<<endl;
    }
    else if(doesContentCreatorIdExist(contentCreatorId)==-1){
        cout<<"Cannot add content. There is no content creator with ID "<<contentCreatorId<<"."<<endl;
    }
    else{
        Content content(contentId,title);
        contents.sortInsert(1,content);
        contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->addContent(content);
        cout<<"Added content "<<contentId<<"."<<endl;

    }
}
void SocialMediaPlatform::removeContent( const int contentCreatorId, const int contentId ){
    int contentorPos=doesContentCreatorIdExist(contentCreatorId);
    if(contentorPos==-1){
        cout<<"Cannot remove content. There is no content creator with ID "<<contentCreatorId<<"."<<endl;
    }
    else{
        int contentPos=contentCreators.getItemTypePtrAt(contentorPos)->getItem().doesContentExist(contentId);
        if(contentPos==-1){
            cout<<"Cannot remove content. There is no content with ID "<<contentId<<" shared by content creator with ID "<<contentCreatorId<<"."<<endl;
        }
        else{
            contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->removeContent(contentPos);
            contentPos=doesContentIdExist(contentId);
            contents.remove(contentPos);
            cout<<"Removed content "<<contentId<<"."<<endl;
        }
    }
}
void SocialMediaPlatform::implicitlyRemoveContent( const int contentCreatorId, const int contentId ){
    int contentorPos=doesContentCreatorIdExist(contentCreatorId);
    int contentPos=contentCreators.getItemTypePtrAt(contentorPos)->getItem().doesContentExist(contentId);
    contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->removeContent(contentPos);
    contentPos=doesContentIdExist(contentId);
    contents.remove(contentPos);

}
void SocialMediaPlatform::followContentCreator( const int regularUserId, const int contentCreatorId ){
    int userPos=doesRegularUserIdExist(regularUserId);
    int contentorPos=doesContentCreatorIdExist(contentCreatorId);
    if(userPos==-1 || contentorPos==-1){
        cout<<"Cannot follow. Regular user and/or content creator ID does not exist."<<endl;
    }
    else{
        int followerPos=contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->doesFollowerExist(regularUserId);
        if(followerPos!=-1){
            cout<<"Cannot follow. The user is already following the content creator."<<endl;
        }
        else{
            contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->addFollower(regularUserId);
            cout<<"Regular user with ID "<<regularUserId<<" followed content creator with ID "<<contentCreatorId<<"."<<endl;
        }
    }
}
void SocialMediaPlatform::unfollowContentCreator( const int regularUserId, const int contentCreatorId){
    int userPos=doesRegularUserIdExist(regularUserId);
    int contentorPos=doesContentCreatorIdExist(contentCreatorId);
    if(userPos==-1 || contentorPos==-1){
        cout<<"Cannot unfollow. Regular user and/or content creator ID does not exist."<<endl;
    }
    else{
        int followerPos=contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->doesFollowerExist(regularUserId);
        if(followerPos==-1){
            cout<<"Cannot unfollow. The user is not following the content creator."<<endl;
        }
        else{
            contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->removeFollower(followerPos);
            //contentCreators.getItemTypePtrAt(contentorPos)->getItem().removeFollower(regularUserId);
            cout<<"Regular user with ID "<<regularUserId<<" unfollowed content creator with ID "<<contentCreatorId<<"."<<endl;
        }
    }
}
void SocialMediaPlatform::showFollowersOf( const int contentCreatorId ) const{

    int contentorPos=doesContentCreatorIdExist(contentCreatorId);
    if(contentorPos==-1){
        cout<<"Cannot show. There is no content creator with ID "<<contentCreatorId<<"."<<endl;
    }
    else{
        cout<<"Regular users following content creator with ID "<<contentCreatorId<<":"<<endl;
        int length = contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->getFollowerNumber();
        if(length==0){
            cout<<"None"<<endl;
        }
        else{
            int i=1;
            while(i<=length){
                cout<<contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->getFollowerIdAt(i)<<endl;
                i++;
            }
        }
    }
}
void SocialMediaPlatform::showContentsOf( const int contentCreatorId ) const{
    int contentorPos=doesContentCreatorIdExist(contentCreatorId);
    if(contentorPos==-1){
        cout<<"Cannot show. There is no content creator with ID "<<contentCreatorId<<"."<<endl;
    }
    else{
        cout<<"Contents of content creator with ID "<<contentCreatorId<<":"<<endl;
        int length = contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->getContentNumber();
        if(length==0){
            cout<<"None"<<endl;
        }
        else{
            int i=1;
            while(i<=length){
                cout<<contentCreators.getItemTypePtrAt(contentorPos)->getNodePtr()->getContentIdAt(i)<<endl;
                i++;
            }
        }
    }
}
void SocialMediaPlatform::showAllRegularUsers( ) const{
    cout<<"Regular users in the social media platform:"<<endl;
    int length= regularUsers.getLength();
    if(length==0){
        cout<<"None"<<endl;
    }
    else{
        int i=1;
        while(i<=length){
            cout<<regularUsers.getEntry(i).getId()<<", "<<regularUsers.getEntry(i).getName()<<endl;
            i++;
        }
    }
}
void SocialMediaPlatform::showAllContentCreators( ) const{
    cout<<"Content creators in the social media platform:"<<endl;
    int length= contentCreators.getLength();
    if(length==0){
        cout<<"None"<<endl;
    }
    else{
        int i=1;
        while(i<=length){
            cout<<contentCreators.getEntry(i).getId()<<", "<<contentCreators.getEntry(i).getName()<<", "<<contentCreators.getEntry(i).getFollowerNumber()<<" follower(s), "<<contentCreators.getEntry(i).getContentNumber()<<" content(s)"<<endl;
            i++;
        }
    }
}
int main(){
    LinkedList<int> list1;
    list1.sortInsert(1,5);
    list1.sortInsert(1,3);
    list1.sortInsert(1,1);
    LinkedList<int> list2;
    list2.sortInsert(1,6);
    list2.sortInsert(1,4);
    list2.sortInsert(1,2);
    cout<<list1.toString()<<endl;
    cout<<list2.toString()<<endl;
    list1.merge(list2);
    cout<<list1.toString()<<endl;
    cout<<list2.toString()<<endl;
    int i=3;
    list1.removeItem(i);
    cout<<list1.toString()<<endl;
    list1.reverseOrder();
    list1.sortInsert(1,1);
    list1.sortInsert(1,1);
    list1.sortInsert(1,1);
    cout<<list1.toString();
    list1.unique();
    cout<<list1.toString();
    return 0;
}
