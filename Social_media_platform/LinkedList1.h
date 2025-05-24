#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "Node.h"
template<class ItemType>
class LinkedList{
public:
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);
    virtual ~LinkedList();
    bool isEmpty()const;
    int getLength()const;
    bool insert(int newPosition,const ItemType& newEntry);
    bool remove(int position);
    void clear();
    Node<ItemType>* getHeadPtr();
    int getItemCount();
    void sortInsert(Node*& headPtr, ItemType newItem);

private:
    Node<ItemType>* headPtr;
    int itemCount;
    Node<ItemType>* getNodeAt(int position) const;

};

#endif // LINKEDLIST_H_INCLUDED
