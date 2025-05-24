/**
* Title: Binary Search Trees
* Author : Emine Fidan
* ID: 22102860
* Section : 2
* Homework : 1
* Description : bst implementation file
*/
#include "BST.h"
#include "Stack.h"
#include "treeNode.h"
#include <iostream>
//#include <string>

BST::BST(int keys[],int size){
    treeRoot=nullptr;
    for(int i=0;i<size;i++){
        insertKeyWithoutOutput(keys[i]);
    }
    std::cout<<"BST with size "<<size<<" is created."<<std::endl;

}
BST::~BST() {
    deleteTree(treeRoot);
}

void BST::deleteTree(treeNode*& ptr) {
    if (ptr != nullptr) {
        deleteTree(ptr->leftTreeNode);
        deleteTree(ptr->rightTreeNode);
        delete ptr;
        ptr = nullptr;
    }
    //delete currentLevel;
}
void BST::insertKey(int key){
    insertKeyHelper(treeRoot,key);
}
void BST::insertKeyWithoutOutput(int key){
    insertKeyHelperWithoutOutput(treeRoot,key);
}
void BST::insertKeyHelper(treeNode*& ptr,const int key){
    if(ptr==nullptr){
        ptr=new treeNode(key);
        std::cout<<"Key "<<key<<" is added."<<std::endl;
    }
    else if(ptr->data<key){
        insertKeyHelper(ptr->rightTreeNode,key);
    }
    else if(ptr->data>key){
        insertKeyHelper(ptr->leftTreeNode,key);
    }
    else{
        std::cout<<"Key "<<key<<" is not added. It exists!"<<std::endl;
    }
}
void BST::insertKeyHelperWithoutOutput(treeNode*& ptr,const int key){
    if(ptr==nullptr){
        ptr=new treeNode(key);
    }
    else if(ptr->data<key){
        insertKeyHelperWithoutOutput(ptr->rightTreeNode,key);
    }
    else if(ptr->data>key){
        insertKeyHelperWithoutOutput(ptr->leftTreeNode,key);
    }
    else{
        //std::cout<<"Duplicated key: "<<key<<std::endl;
    }
}
void BST::deleteKey(const int key){

    deleteKeyHelper(treeRoot,key);
}
void BST::deleteKeyHelper(treeNode*& ptr,const int key){
    if(ptr==nullptr){
        std::cout<<"Key "<<key<<" is not deleted. It does not exist!"<<std::endl;
    }
    else if(ptr->data==key){

        if(ptr->rightTreeNode==nullptr && ptr->leftTreeNode==nullptr){
            delete ptr;
            ptr=nullptr;

        }
        else if(ptr->rightTreeNode==nullptr){
            treeNode* temp=ptr->leftTreeNode;
            delete ptr;
            ptr=temp;

        }
        else if(ptr->leftTreeNode==nullptr){
            treeNode* temp=ptr->rightTreeNode;
            delete ptr;
            ptr=temp;

        }
        else{
            //successor'u bul ve ptr ile swapla
            treeNode* successor=ptr->rightTreeNode;
            treeNode* preSuccessor=ptr;
            int i=0;
            while(successor->leftTreeNode!=nullptr){
                preSuccessor=successor;
                successor=successor->leftTreeNode;
                i++;
            }
            if(i>0){
                //deleteKeyHelper(ptr->rightTreeNode,successor->data);
                preSuccessor->leftTreeNode=nullptr;
                successor->rightTreeNode=ptr->rightTreeNode;
            }
            treeNode* temp=ptr;
            successor->leftTreeNode=ptr->leftTreeNode;
            ptr=successor;
            successor=temp;


        }
        std::cout<<"Key "<<key<<" is deleted."<<std::endl;
    }
    else if(ptr->data<key){
        deleteKeyHelper(ptr->rightTreeNode,key);
    }
    else{
        deleteKeyHelper(ptr->leftTreeNode,key);
    }
}
void BST::displayInorder() {
    std::cout << "Inorder display is: ";
    std::string str = "";
    str = displayInOrderHelper(treeRoot, str);
    if (!str.empty()) {
        std::cout << str.substr(0, str.length() - 2) << std::endl;
    }
}

std::string BST::displayInOrderHelper(treeNode*& ptr, std::string& str) {
    if (ptr == nullptr) {
        return str;
    }

    displayInOrderHelper(ptr->leftTreeNode, str);
    str += std::to_string(ptr->data)+ ", ";
    displayInOrderHelper(ptr->rightTreeNode, str);
    return str;
}
void BST::findFullBTLevel(){
    Stack<treeNode*>* currentLevelStack=new Stack<treeNode*>(1);
    currentLevelStack->push(treeRoot);
    int level=1;
    std::cout<<"Full binary tree level is: "<<findFullBTLevelHelper(currentLevelStack,level)<<std::endl;

}
int BST::findFullBTLevelHelper(Stack<treeNode*>* givenStack,int& level){
    if(givenStack->isEmpty()){
        return level;
    }
    int height=findHeight(treeRoot)-1;
    int product=1;
    for(int i=0;i<height;i++){
        product*=2;
    }
    currentLevel= new Stack<treeNode*> (product);
    bool go=true;
    treeNode** ptr=givenStack->peek();
    givenStack->pop();
    while(go){
        if(((*ptr)->leftTreeNode!=nullptr && (*ptr)->rightTreeNode==nullptr)||((*ptr)->leftTreeNode==nullptr && (*ptr)->rightTreeNode!=nullptr) ){
            go=false;
            return level;
        }
        else{
            if((*ptr)->leftTreeNode!=nullptr){//both child nodes exist
                currentLevel->push((*ptr)->leftTreeNode);
                currentLevel->push((*ptr)->rightTreeNode);
            }
            if(givenStack->isEmpty()){
                if(!currentLevel->isEmpty()){
                    level++;
                }
                go=false;
                return findFullBTLevelHelper(currentLevel,level);
            }
            else{
                ptr=givenStack->peek();
                givenStack->pop();
            }
        }
    }
}
void BST::lowestCommonAncestor(int A,int B){
    std::cout<<"Lowest common ancestor of "<<A<<" and "<<B<<" is: "<<lowestCommonAncestorHelper(treeRoot,A,B)->data<<std::endl;
}
treeNode* BST::lowestCommonAncestorHelper(treeNode* ptr,int key1,int key2){
    if(ptr==nullptr){
        return nullptr; //??
    }
    else if(ptr->data>key1 && ptr->data>key2){
        return lowestCommonAncestorHelper(ptr->leftTreeNode,key1,key2);
    }
    else if(ptr->data<key1 && ptr->data<key2){
        return lowestCommonAncestorHelper(ptr->rightTreeNode,key1,key2);
    }
    else{
        return ptr;
    }
}
void BST::maximumSumPath(){
    Stack<treeNode*>* currentPathStack= new Stack<treeNode*> (findHeight(treeRoot));
    Stack<treeNode*>* maxSumPathStack= new Stack<treeNode*> (findHeight(treeRoot));
    treeNode* rightMostKey=treeRoot;
    while(rightMostKey!=nullptr && rightMostKey->rightTreeNode!=nullptr){
        rightMostKey=rightMostKey->rightTreeNode;
    }
    int maxSum=0;
    std::string str="";
    maximumSumPathHelper(treeRoot,rightMostKey,currentPathStack,maxSumPathStack,maxSum,str);
    std::cout<<"Maximum sum path is: "<<str;
    delete currentPathStack;
    currentPathStack=nullptr;
    delete maxSumPathStack;
    maxSumPathStack=nullptr;
}
Stack<treeNode*>* BST::maximumSumPathHelper(treeNode* ptr,treeNode* rightMostKey,Stack<treeNode*>* currentPathStack,Stack<treeNode*>* maxSumPathStack,int& maxSum,std::string& str){

    if(ptr==rightMostKey){

        return maxSumPathStack;


    }
    if(ptr!=nullptr){
        if( currentPathStack->isEmpty() || (*currentPathStack->peek())->data != ptr->data){
            currentPathStack->push(ptr);
        }

        if(ptr->leftTreeNode!=nullptr && !(ptr->leftTreeNode->isVisited)){
            maximumSumPathHelper(ptr->leftTreeNode,rightMostKey,currentPathStack,maxSumPathStack,maxSum,str);
        }
        else if(ptr->rightTreeNode!=nullptr && !(ptr->rightTreeNode->isVisited)){
            maximumSumPathHelper(ptr->rightTreeNode,rightMostKey,currentPathStack,maxSumPathStack,maxSum,str);
        }
        else if((ptr->leftTreeNode==nullptr || (ptr->leftTreeNode->isVisited))&&(ptr->rightTreeNode==nullptr || (ptr->rightTreeNode->isVisited)) ){
            ptr->isVisited=true;
            //stacktekileri topla ve max m� diye kontrol et
            int currentSum=currentPathStack->sumOfStackItems();
            if(currentSum>maxSum){
                // operator = should be overloaded

                maxSumPathStack=currentPathStack; //??
                maxSum=currentSum;
                str=maxSumPathStack->toString2();
            }

            currentPathStack->pop();
            //treeNode* ptr2=*currentPathStack.peek();
            //while(ptr2)
            maximumSumPathHelper(*(currentPathStack->peek()),rightMostKey,currentPathStack,maxSumPathStack,maxSum,str);
        }
        else{
            ptr->isVisited=true;
            currentPathStack->pop();
            maximumSumPathHelper(*(currentPathStack->peek()),rightMostKey,currentPathStack,maxSumPathStack,maxSum,str);

        }

    }
    else{
        std::cout<<"Empty Tree!";
    }
    return maxSumPathStack;

}
int BST::findHeight(treeNode* ptr){
    if(ptr==nullptr){
        return 0;
    }
    else{
        int leftDepth=findHeight(ptr->leftTreeNode);
        int rightDepth=findHeight(ptr->rightTreeNode);
        if(rightDepth>leftDepth){
            return rightDepth+1;
        }
        else{
            return leftDepth+1;
        }

    }
}
int BST::findHeight(){
    return findHeight(treeRoot);
}
void BST::maximumWidth(){

    bool go=true;
    int product=1;
    for(int i=0;i<findHeight(treeRoot)-1;i++){
        product*=2; //product=max num of nodes in a level
    }
    Stack<treeNode*>* maxLevelStack=new Stack<treeNode*>(product);
    Stack<treeNode*>* currentLevelStack=new Stack<treeNode*>(product);
    currentLevelStack->push(treeRoot);
    std::string str="";
    maximumWidthHelper(currentLevelStack,maxLevelStack,1,0,go,str);
    std::cout<<"Maximum level is: "<<str;
    delete maxLevelStack;
    maxLevelStack=nullptr;
    delete currentLevelStack;
    currentLevelStack=nullptr;
}
void BST::maximumWidthHelper(Stack<treeNode*>* givenStack,Stack<treeNode*>* maxLevelStack,int level,int maxWidth,bool& go,std::string& str){
    Stack<treeNode*>* nextLevelStack=nullptr;
    if(!go){
        if(maxLevelStack!=nullptr){
            str=maxLevelStack->toString3();
        }
        delete nextLevelStack;
        nextLevelStack=nullptr;
        return;
    }
    //if givenStack is empty{if maxWidth>2^(level-1)else{go recursion}},else{}
    Stack<treeNode*> thisLevelStack=*givenStack;

    int width=0; //current level's width
    int product=1;
    for(int i=0;i<level;i++){
        product*=2; //product=max num of nodes in next level
    }
    nextLevelStack=new Stack<treeNode*>(product); //next levels' nodes
    treeNode** ptr;
    while(!givenStack->isEmpty()){
        ptr=givenStack->peek();
        givenStack->pop();
        width++;
        if((*ptr)->rightTreeNode!=nullptr){
            nextLevelStack->push((*ptr)->rightTreeNode);
        }
        if((*ptr)->leftTreeNode!=nullptr){
            nextLevelStack->push((*ptr)->leftTreeNode);
        }

    }
    if(width>maxWidth){
        maxWidth=width;
        *maxLevelStack=thisLevelStack;
    }
    level++;
    //delete thisLevelStack;
    if(nextLevelStack->isEmpty()){
        go=false;
        maximumWidthHelper(nextLevelStack,maxLevelStack,level,maxWidth,go,str);
    }
    maximumWidthHelper(nextLevelStack,maxLevelStack,level,maxWidth,go,str);
    
    //std::cout<<"given: "<<givenStack.toStringInReverse()<<std::endl;
    return;
}
void BST::pathFromAtoB(int A,int B){
    treeNode* ancestor=lowestCommonAncestorHelper(treeRoot,A,B);
    Stack<treeNode*>* pathStackA= new Stack<treeNode*> (findHeight(ancestor));
    Stack<treeNode*>* pathStackB= new Stack<treeNode*> (findHeight(ancestor));
    pathFromAtoBHelper(ancestor,A,pathStackA);
    pathFromAtoBHelper(ancestor,B,pathStackB);
    //converge paths
    std::cout<<"Path from "<<A<<" to "<<B<<" is: "<<pathStackA->toStringInReverse()+pathStackB->toString();
    delete pathStackA;
    pathStackA=nullptr;
    delete pathStackB;
    pathStackB=nullptr;

}
Stack<treeNode*>* BST::pathFromAtoBHelper(treeNode* ptr,int A,Stack<treeNode*>* pathStack){

    if(ptr==nullptr){
        return pathStack;
    }
    else if(ptr->data<A){

        pathStack->push(ptr);
        pathFromAtoBHelper(ptr->rightTreeNode,A,pathStack);
    }
    else if(ptr->data>A){

        pathStack->push(ptr);
        pathFromAtoBHelper(ptr->leftTreeNode,A,pathStack);
    }
    else{
        pathStack->push(ptr);

        return pathStack;
    }
    return nullptr;
}
/*int main(){
    int keys[]={10,7,20,5,9,15,21,2,12,18,24,3,19,1};
    BST bst(keys,14);
    bst.displayInorder();
    bst.lowestCommonAncestor(3,9);
    bst.lowestCommonAncestor(12,15);
    bst.findFullBTLevel();

    bst.pathFromAtoB(2,21);
    bst.deleteKey(11);
    bst.displayInorder();
    bst.insertKey(7);
    bst.deleteKey(21);
    bst.deleteKey(20);
    bst.displayInorder();
    bst.deleteKey(10);
    bst.displayInorder();
    bst.insertKey(4);
    bst.displayInorder();
    bst.maximumWidth();
    bst.maximumSumPath();
    return 0;
}*/
