/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
template<class ItemType>
class Node{
public:
    Node(): nextNode(nullptr){

    }
    Node(const ItemType& anItem){
        item=anItem;
        nextNode=nullptr;
    }
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr){
        item=anItem;
        nextNode=nextNodePtr;
    }
    void setItem (const ItemType& anItem){
        item=anItem;
    }
    void setNext(Node<ItemType>* nextNodePtr){
        nextNode=nextNodePtr;
    }
    ItemType getItem() const{
        return item;
    }
    ItemType* getNodePtr() {
        return &item;
    }
    Node<ItemType>* getNext() const{
        return nextNode;
    }

private:
    ItemType item;
    Node<ItemType>* nextNode;
};

#endif // NODE_H_INCLUDED
