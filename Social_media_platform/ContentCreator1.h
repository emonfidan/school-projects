#ifndef CONTENTCREATOR_H_INCLUDED
#define CONTENTCREATOR_H_INCLUDED
class ContentCreator{
public:
    ContentCreator();

private:
    int id;
    LinkedList<int> followerIds;
    LinkedList<Content> contents;
};


#endif // CONTENTCREATOR_H_INCLUDED
