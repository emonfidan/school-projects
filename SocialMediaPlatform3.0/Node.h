#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
template<class ItemType>
class Node{
public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem (const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
private:
    ItemType item;
    Node<ItemType>* nextNode;
};


#endif // NODE_H_INCLUDED
