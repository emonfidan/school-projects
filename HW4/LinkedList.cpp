/*
Written by: Emine Fidan
Section: 2
Id: 22102860

*/
#include "LinkedList.h"
#include "Vertex.h"
#include "PrecondViolatedExcept.h"

template<>
void LinkedList<Vertex*>::sortInsert(int pos, Vertex* newItem) {

    try{
        if(newItem==nullptr){
            std::string msg = "sortInsert() called with an empty list or invalid position. \n";
            throw PrecondViolatedExcept(msg);
        }
        if ((getNodeAt(pos) == nullptr) || (newItem->getName() < getEntry(pos)->getName())) {
            insert(pos, newItem);
        } else {
            sortInsert(++pos, newItem);
        }

    }
    catch(const PrecondViolatedExcept& e){
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}
