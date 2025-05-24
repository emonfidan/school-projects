#include "Pathway.h"
Pathway::Pathway(){
    id=-1;
    name="null";
    //proteins=nullptr;
}
Pathway::Pathway(const int pathwayid, const string pathwayname ){
    id=pathwayid;
    name=pathwayname;
    //proteins=nullptr;
}
Pathway::~Pathway(){
    /*if(proteins!=nullptr){
        for(int j=1;j<=proteins->getLength();j++){
            LinkedList<Gene>* ptr=proteins->getEntry(j).getPtr();
            if(ptr!=nullptr){
                //delete ptr;
                ptr=nullptr;
            }
        }
        delete proteins;
        proteins=nullptr;
    }*/
}
void Pathway::removeAllProteins(){
    /*if(proteins!=nullptr){
        for(int i=1;i<=proteins->getLength();i++){
            proteins->getItemTypePtrAt(i)->getNodePtr()->removeAllGenes();
        }
        delete proteins;
        proteins=nullptr;
    }*/
}
LinkedList<Protein>* Pathway::getPtr(){
    return &proteins;
}
bool Pathway::operator<(const Pathway& right){
    if(id<=right.id){
        return true;
    }
    else{
        return false;
    }
}
bool Pathway::operator==(const Pathway& right){
    if(id==right.id){
        return true;
    }
    else{
        return false;
    }
}
int Pathway::getId(){
    return id;
}
string Pathway::getName(){
    return name;
}
void Pathway::addProtein(const int proteinId){
    /*if(proteins==nullptr)
        proteins = new LinkedList<Protein>();*/
    Protein protein(proteinId);
    proteins.sortInsert(1,protein);
}
void Pathway::removeProtein(const int proteinId){
    Protein* ptr=findProteinById(proteinId);
    if(ptr!=nullptr)
        proteins.removeItem(*ptr);
    /*if(proteins->getLength()==0){
        proteins=nullptr;
    }*/
}
Protein* Pathway::findProteinById(const int proteinId){
    if(proteins.getLength()==0){
        return nullptr;
    }
    int index = proteins.getPosOf(proteinId);
    if(index==-1){
        return nullptr;
    }
    return proteins.getItemTypePtrAt(index)->getNodePtr();

}

bool Pathway::doesProteinIdExist(int id){
    if(proteins.getLength()!=0){
        int index=proteins.getPosOf(id);
        if(index==-1){
            return false;
        }
        else{
            return true;
        }
    }
    return false;
}
void Pathway::printProteins(){
    if(proteins.getLength()==0)
        std::cout<<"There are no proteins to show in pathway "<<id<<".\n";
    else{
        std::cout<<"Proteins in pathway "<<id<<":\n";
        string result="";
        for(int i=1;i<=proteins.getLength();i++){
            result+=proteins.getEntry(i).toString()+"\n";
        }
        std::cout<<result;
    }
}
string Pathway::toString(){
    int geneNumberSum=0;
    int proteinNumber=0;
    if(proteins.getLength()!=0){
        for(int i=1;i<=proteins.getLength();i++){
            geneNumberSum+=proteins.getEntry(i).getGeneNumber();
        }
        proteinNumber=proteins.getLength();
    }
    return "Pathway "+std::to_string(id)+" : "+name+" ("+std::to_string(proteinNumber)+" Proteins) ("+std::to_string(geneNumberSum)+" Genes)\n";
}
