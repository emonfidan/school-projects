#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

class treeNode{
    public:
        int data;
        treeNode* leftTreeNode{nullptr};
        treeNode* rightTreeNode{nullptr};
        bool isVisited;
        treeNode(const int key){
            data=key;
            isVisited=false;
        }
};

#endif // TREENODE_H_INCLUDED
