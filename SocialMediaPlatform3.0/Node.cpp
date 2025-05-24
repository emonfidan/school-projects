#include "Node.h"
#include <iostream>
template<class ItemType>
Node<ItemType>::Node() : nextNode(nullptr){

}
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem){
    item=anItem;
    nextNode=nullptr;
}
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr){
    item=anItem;
    nextNode=nextNodePtr;
}
template<class ItemType>
void Node<ItemType>::setItem (const ItemType& anItem){
    item=anItem;
}
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr){
    nextNode=nextNodePtr;
}
template<class ItemType>
ItemType Node<ItemType>::getItem() const{
    return item;
}
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const{
    return nextNode;
}
/*int main(){
    Node<int> n;
    n.setItem(15);
    cout<<n.getItem()<<endl;
    Node<int> n2;
    n2.setItem(30);
    Node<int>* ptr=&n2;
    n.setNext(ptr);
    cout<<(n.getNext()->getItem())<<endl;
    return 0;
}*/
