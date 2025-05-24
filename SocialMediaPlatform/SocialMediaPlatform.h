/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#ifndef SOCIALMEDIAPLATFORM_H_INCLUDED
#define SOCIALMEDIAPLATFORM_H_INCLUDED
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "RegularUser.h"
#include "ContentCreator.h"
using namespace std;

class SocialMediaPlatform {
public:
    SocialMediaPlatform();
    ~SocialMediaPlatform();
    void addRegularUser( const int regularUserId, const string name );
    void removeRegularUser( const int regularUserId );
    void addContentCreator( const int contentCreatorId, const string name );
    void removeContentCreator( const int contentCreatorId );
    void addContent( const int contentCreatorId, const int contentId, const string
    title );
    void removeContent( const int contentCreatorId, const int contentId );
    void followContentCreator( const int regularUserId, const int contentCreatorId );
    void unfollowContentCreator( const int regularUserId, const int contentCreatorId);
    void showFollowersOf( const int contentCreatorId ) const;
    void showContentsOf( const int contentCreatorId ) const;
    void showAllRegularUsers( ) const;
    void showAllContentCreators( ) const;
    int doesRegularUserIdExist(int id ) const;
    int doesContentCreatorIdExist(int id ) const;
    int doesContentIdExist(int id ) const;
    void removeFromFollowerLists(int id) const;
    void removeAllContentsOf(int id,int pos);
    void implicitlyRemoveContent( const int contentCreatorId, const int contentId );
private:
    LinkedList<RegularUser> regularUsers;
    LinkedList<ContentCreator> contentCreators;
    LinkedList<Content> contents;
};


#endif // SOCIALMEDIAPLATFORM_H_INCLUDED
