#include "Node.h"
#include "LinkedList.h"
#include <iostream>
template<class ItemType>
LinkedList<ItemType>::LinkedList():headPtr(nullptr),itemCount(0){

}
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
    if(position<1 || position>itemCount){
        return nullptr;
    }
    else{
        int i=1;
        Node<ItemType>* nodePtr = headPtr;
        while(i<position){
            nodePtr=nodePtr->getNext();
            i++;
        }
        return nodePtr;
    }
}
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
    //copy constructor
    itemCount = aList.itemCount;
    Node<ItemType>* preHead = aList.headPtr;

    if(preHead==nullptr){
        headPtr=nullptr;
    }
    else{
        headPtr = new Node<ItemType>();
        headPtr->setItem(preHead->getItem());
        Node<ItemType>* newPtr = headPtr;
        preHead = preHead->getNext();
        while (preHead != nullptr){
            ItemType nextItem = preHead->getItem();
            Node<ItemType>* newNode = new Node<ItemType>(nextItem);
            newPtr->setNext(newNode);
            newPtr= newPtr->getNext();
            preHead = preHead->getNext();
        }
        newPtr->setNext(nullptr);
    }

}
template<class ItemType>
void LinkedList<ItemType>::sortInsert(Node<ItemType>*& headPtr, ItemType newItem){
    if((headPtr==nullptr) || (newItem < headPtr->item)){
        Node<ItemType>* newPtr = new Node<ItemType>();
        newPtr->setItem(newItem);
        newPtr->setNext(headPtr);
        headPtr=newPtr;
    }
    else{
        sortInsert(headPtr->getNext(), newItem);
    }
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
    clear();
}
template<class ItemType>
bool LinkedList<ItemType>::isEmpty()const{
    if(headPtr==nullptr){
        return true;
    }
    else{
        return false;
    }
}
template<class ItemType>
int LinkedList<ItemType>::getLength()const{
    return itemCount;
}
template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition,const ItemType& newEntry){
    bool ableToInsert=(newPosition>=1)&&(newPosition<=itemCount+1);
    if(ableToInsert){
        Node<ItemType>* newNodePtr= new Node<ItemType>(newEntry);
        if(newPosition==1){
            newNodePtr->setNext(headPtr);
            headPtr=newNodePtr;
        }
        else{
            Node<ItemType>* prevPtr = getNodeAt(newPosition-1);
            Node<ItemType>* posPtr = getNodeAt(newPosition);
            prevPtr->setNext(newNodePtr);
            newNodePtr->setNext(posPtr);//???
        }
        itemCount++;
    }
    return ableToInsert;
}
template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
    bool ableToRemove=(position>=1)&&(position<=itemCount);
    if(ableToRemove){
        Node<ItemType>* curPtr=nullptr;
        if(position==1){
            curPtr=headPtr;
            headPtr=headPtr->getNext();
            delete curPtr;
            curPtr=nullptr;
        }
        else{
            Node<ItemType>* prevPtr=getNodeAt(position-1);
            curPtr=prevPtr->getNext();
            prevPtr->setNext(nullptr);
            delete curPtr;
            curPtr=nullptr;

        }
        itemCount--;
    }
    return ableToRemove;
}
template<class ItemType>
void LinkedList<ItemType>::clear(){
    while(!isEmpty())
        remove(1);
}

int main(){
    //LinkedList<double> list;
    //list.insert(1,1);
    //std::cout<<list.getLength();
    Node<int> node;
    node.setItem(1);

    return 0;
}

