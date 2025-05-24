#include "Node.h"
#include <cstddef>
template<class ItemType>
Node<ItemType>::Node() : next(nullptr){

}
Node<ItemType>::Node(const ItemType& anItem){
    item=anItem;
    nextNode=nullptr;
}
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr){
    item=anItem;
    nextNode=nextNodePtr;
}
void Node<ItemType>::setItem (const ItemType& anItem){
    item=anItem;
}
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr){
    nextNode=nextNodePtr;
}
ItemType Node<ItemType>::getItem() const{
    return item;
}
Node<ItemType>* Node<ItemType>::getNext() const{
    return nextNode;
}
