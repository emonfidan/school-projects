#include "LinkedList.h"
template<class ItemType>
LinkedList<ItemType>::LinkedList():headPtr(nullptr),itemCount(0){

}
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
    //copy constructor
    itemCount = aList.getItemCount();
    Node<ItemType>* preHead = aList.getHeadPtr();

    if(aList.getHeadPtr()==nullptr){
        headPtr=nullptr;
    }
    else{
        headPtr = new Node<ItemType>();
        headPtr.setItem(preHead->getItem());
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
void LinkedList<ItemType>::sortInsert(Node*& headPtr, ItemType newItem){
    if((headPtr==nullptr) || (newItem < headPtr->item)){
        Node* newPtr = new Node;
        newPtr->setItem(newItem);
        newPtr->setNext(headPtr);
        headPtr=newPtr;
    }
    else{
        sortInsert(headPtr->getNext(), newItem);
    }
}
int LinkedList<ItemType>::getItemCount(){
    return itemCount;
}
Node<ItemType>* LinkedList<ItemType>::getHeadPtr(){
    return headPtr;
}
virtual LinkedList<ItemType>::~LinkedList(){
    clear();
}
bool LinkedList<ItemType>::isEmpty()const{
    if(headPtr==nullptr){
        return true;
    }
    else{
        return false;
    }
}
int LinkedList<ItemType>::getLength()const{
    return itemCount;
}
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
void LinkedList<ItemType>::clear(){
    while(!isEmpty())
        remove(1);
}
int main(){
    LinkedList list = LinkedList();
    list.insert(1,1);
    cout<<list.getItemCount();
}
