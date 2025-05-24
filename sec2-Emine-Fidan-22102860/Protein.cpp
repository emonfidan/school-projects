#include "Protein.h"
Protein::Protein(){
    //genes=nullptr;
}
Protein::Protein(int i){
    id=i;
    //genes=nullptr;
}
Protein::~Protein(){
    /*if(genes!=nullptr){
        delete genes;
        genes=nullptr;
    }*/
}
LinkedList<Gene>* Protein::getPtr(){
    return &genes;
}
bool Protein::operator<(const Protein& right){
    if(id<=right.id){
        return true;
    }
    else{
        return false;
    }
}
bool Protein::operator==(const Protein& right){
    if(id==right.id){
        return true;
    }
    else{
        return false;
    }
}
int Protein::getId(){
    return id;
}
void Protein::addGene(const int geneID, const string geneName){
    /*if(genes==nullptr)
        genes = new LinkedList<Gene>();*/
    Gene newGene(geneID,geneName);
    genes.sortInsert(1,newGene);
}
void Protein::removeGene(const int geneID){
    Gene* gene=findGeneById(geneID);
    if(gene!=nullptr)
        genes.removeItem(*gene);
    /*if(genes.getLength()==0){
        genes=nullptr;
    }*/
}
void Protein::removeAllGenes(){
    /*if(genes!=nullptr){
        delete genes;
        genes=nullptr;
    }*/
    genes=LinkedList<Gene>();
}
string Protein::toString(){
    string result="Protein ID : "+to_string(id)+", Gene IDs : ";
    if(genes.getLength()==0){
        result+="None";
    }
    else{
        result+=genes.toString();
    }
    return result;
}
void Protein::printGenes(){
    if(genes.getLength()==0){
        std::cout<<"There are no genes to show in protein "<<id<<".\n";
    }
    else{
        std::cout<<"Genes in protein "<<id<<":\n";
        for(int i=1;i<=genes.getLength();i++){
            Gene gene=genes.getEntry(i);
            std::cout<<"GENE "<<gene.getId()<<" : "<<gene.getName()<<"\n";
        }
    }
}
Gene* Protein::findGeneById(const int geneID){
    if(genes.getLength()==0){
        return nullptr;
    }
    int index = genes.getPosOf(geneID);
    if(index==-1){
        return nullptr;
    }
    return genes.getItemTypePtrAt(index)->getNodePtr();

}
int Protein::getGeneNumber(){
    return genes.getLength();
}
