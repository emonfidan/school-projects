/**
* Title: Binary Search Trees
* Author : Emine Fidan
* ID: 22102860
* Section : 2
* Homework : 1
* Description : bst source file
*/
#include "Stack.h"
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include "treeNode.h"

class BST{

public:

    BST(int keys[], int size);
    ~BST();
    void insertKey(int key);
    void insertKeyWithoutOutput(int key);
    void deleteKey(int key);
    void displayInorder();
    void findFullBTLevel();
    void lowestCommonAncestor(int A,int B);
    void maximumSumPath();
    void maximumWidth();
    void pathFromAtoB(int A,int B);
    int findHeight();
private:
    treeNode* treeRoot;
    Stack<treeNode*>* currentLevel;
    void insertKeyHelper(treeNode*& ptr,const int key);
    void insertKeyHelperWithoutOutput(treeNode*& ptr,const int key);
    void deleteKeyHelper(treeNode*& ptr,const int key);
    std::string displayInOrderHelper(treeNode*& ptr,std::string& str);
    Stack<treeNode*>* maximumSumPathHelper(treeNode* ptr,treeNode* rightMostKey,Stack<treeNode*>* currentPathStack,Stack<treeNode*>* maxSumPathStack,int& maxSum,std::string& str);
    treeNode* lowestCommonAncestorHelper(treeNode* ptr,int key1,int key2);
    int findFullBTLevelHelper(Stack<treeNode*>* givenStack,int&level);
    Stack<treeNode*>* pathFromAtoBHelper(treeNode* ptr,int A,Stack<treeNode*>* pathStack);
    void maximumWidthHelper(Stack<treeNode*>* givenStack,Stack<treeNode*>* maxLevelStack,int level,int maxWidth,bool& go,std::string& str);
    void deleteTree(treeNode*& ptr);
    int findHeight(treeNode* ptr);
};


#endif // BST_H_INCLUDED
