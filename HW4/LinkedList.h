/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "Node.h"
#include "Vertex.h"
#include "PrecondViolatedExcept.h"
#include <iostream>
template<class ItemType>
class LinkedList{
public:
    LinkedList():headPtr(nullptr),itemCount(0){

    }
    ~LinkedList() {
        clear(); // Call clear to delete all nodes
    }
    LinkedList(const LinkedList<ItemType>& aList){
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
    ItemType getEntry(int position) const{
        try{
            if (position < 1 || position > itemCount) {
            std::string msg = "getEntry() called with an empty list or invalid position. \n";
            throw PrecondViolatedExcept(msg);

            } else {
                Node<ItemType>* targetNode = getNodeAt(position);
                return targetNode->getItem();
            }
        }
        catch(const PrecondViolatedExcept& e){
            std::cerr << "Caught exception: " << e.what() << std::endl;
            return ItemType{};
        }

    }
    LinkedList<ItemType>& operator=(const LinkedList<ItemType>& right){
        if(&right != this){
            if(itemCount != right.itemCount){
                if(itemCount>0){
                    clear();
                }
                itemCount=right.itemCount;
                if(itemCount>0){
                    headPtr = new Node<ItemType>();
                }
                else{
                    headPtr = nullptr;
                }
            }
            for(int i=1;i<itemCount;i++){
                getNodeAt(i)->setItem(right.getEntry(i));
                getNodeAt(i)->setNext(new Node<ItemType>());
            }
            if(itemCount != 0){
                getNodeAt(itemCount)->setItem(right.getEntry(itemCount));
                getNodeAt(itemCount)->setNext(nullptr);

            }

        }
        return *this;
    }

    void sortInsert(int pos, ItemType newItem);
    bool isEmpty()const{
        if(headPtr==nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    int getLength()const{
        return itemCount;
    }
    int getPosOf(ItemType item)const{
        int i=1;
        Node<ItemType>* nodePtr = headPtr;
        while(i<=itemCount){
            if(*(nodePtr->getItem())==(*item)){
                return i;
            }
            nodePtr=nodePtr->getNext();
            i++;
        }
        return -1;
    }
    bool insert(int newPosition,const ItemType& newEntry){
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
                newNodePtr->setNext(posPtr);
            }
            itemCount++;
        }
        return ableToInsert;
    }
    bool remove(int position){
        bool ableToRemove=(position>=1)&&(position<=itemCount);
        if(ableToRemove){
            Node<ItemType>* curPtr=nullptr;
            if(position==1){
                curPtr=headPtr;
                headPtr=headPtr->getNext();

            }
            else{
                Node<ItemType>* prevPtr=getNodeAt(position-1);
                curPtr=prevPtr->getNext();
                prevPtr->setNext(curPtr->getNext());

            }
            itemCount--;
            delete curPtr;
            curPtr=nullptr;
        }
        return ableToRemove;
    }

    void clear(){
        while(!isEmpty())
            remove(1);
    }
    Node<ItemType>* getItemTypePtrAt(int position) const{
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
    void decreaseLength(){
        itemCount--;
    }
    std::string toString(){
        int i=1;
        std::string str;
        if(itemCount==0){
            return "";
        }
        Node<ItemType>* nodePtr = headPtr;
        str+= nodePtr->getItem()->getName();
        str+=", ";
        while(i<itemCount){
            nodePtr=nodePtr->getNext();
            str+= nodePtr->getItem()->getName();
            //str+=", ";
            if (i != itemCount - 1) {
                str += ", ";
            }
            else{
                str+=",";
            }
            i++;
        }
        if(str.back()==' '){
            str=str.substr(0, str.length() - 1);
        }
        str+="\n";
        return str;
    }
private:
    Node<ItemType>* headPtr;
    int itemCount;
    Node<ItemType>* getNodeAt(int position) const{
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

};
//#include "LinkedList.cpp"
#endif // LINKEDLIST_H_INCLUDED
