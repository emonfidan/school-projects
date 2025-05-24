#include "SocialMediaPlatform.h"
#include "LinkedList.h"
#include "RegularUser.h"
#include "ContentCreator.h"
#include "Content.h"
#include "Node.h"

SocialMediaPlatform::SocialMediaPlatform(){
    regularUsers = new LinkedList();
}
SocialMediaPlatform::~SocialMediaPlatform();
void SocialMediaPlatform::addRegularUser( const int regularUserId, const string name ){

}
void SocialMediaPlatform::removeRegularUser( const int regularUserId );
void SocialMediaPlatform::addContentCreator( const int contentCreatorId, const string name );
void SocialMediaPlatform::removeContentCreator( const int contentCreatorId );
void SocialMediaPlatform::addContent( const int contentCreatorId, const int contentId, const string
title );
void SocialMediaPlatform::removeContent( const int contentCreatorId, const int contentId );
void SocialMediaPlatform::followContentCreator( const int regularUserId, const int contentCreatorId );
void SocialMediaPlatform::unfollowContentCreator( const int regularUserId, const int contentCreatorId);
void SocialMediaPlatform::showFollowersOf( const int contentCreatorId ) const;
void SocialMediaPlatform::showContentsOf( const int contentCreatorId ) const;
void SocialMediaPlatform::showAllRegularUsers( ) const;
void SocialMediaPlatform::showAllContentCreators( ) const;
bool SocialMediaPlatform::doesRegularUserExist(int id){

}

