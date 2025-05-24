#include "BiologicalPathway.h"

BiologicalPathway::BiologicalPathway(){
    //pathways=nullptr;
}
BiologicalPathway::~BiologicalPathway(){
    /*if(pathways.getLength()==0){
        for(int i=1;i<=pathways.getLength();i++){
            LinkedList<Protein>* ptr=pathways.getItemTypePtrAt(i)->getNodePtr()->getPtr();
            if(ptr!=nullptr){
                delete ptr;
                ptr=nullptr;
            }

        }
        //delete pathways;
        //pathways=nullptr;
    }*/
}

void BiologicalPathway::addPathway( const int pathwayId, const string pathwayName ){
    /*if(pathways==nullptr){
        pathways = new LinkedList<Pathway>();
    }*/
    Pathway* ptr = findPathwayById(pathwayId);
    if(ptr!=nullptr){
        std::cout<<"Cannot add pathway. There is already a pathway with ID "<<pathwayId<<".\n";
        return;
    }

    Pathway pathway(pathwayId,pathwayName);
    pathways.sortInsert(1,pathway);
    std::cout<<"Added pathway "<<pathwayId<<".\n";
}
void BiologicalPathway::removePathway( const int pathwayId ){
    Pathway* ptr = findPathwayById(pathwayId);
    if(ptr==nullptr){
        std::cout<<"Cannot remove pathway. There is no pathway with ID "<<pathwayId<<".\n";
    }
    else{
        pathways.removeItem(*ptr);
        std::cout<<"Removed pathway "<<pathwayId<<".\n";
        /*if(pathways->getLength()==0){
            pathways=nullptr;
        }*/
    }
}
void BiologicalPathway::printPathways() const{
    if(pathways.getLength()==0)
        std::cout<<"There are no pathways to show.\n";
    else{
        int i=1;
        string result="Pathways in the system:\n";
        while(i<=pathways.getLength()){
            result+=pathways.getEntry(i).toString();
            i++;
        }
        std::cout<<result;
    }

}

void BiologicalPathway::addProtein( const int proteinId, const int pathwayId ){
    Pathway* ptr;
    if(pathways.getLength()==0){
        std::cout<<"Cannot add protein. There is no pathway with ID "<<pathwayId<<".\n";
    }
    else{
        ptr = findPathwayById(pathwayId);
        if(ptr==nullptr){
            std::cout<<"Cannot add protein. There is no pathway with ID "<<pathwayId<<".\n";
            return;
        }
        else{
            bool doesIdExist=false;
            for(int i=1;i<=pathways.getLength();i++){
                if(pathways.getItemTypePtrAt(i)->getNodePtr()->doesProteinIdExist(proteinId)){
                    doesIdExist=true;
                }
            }
            if(doesIdExist){
                std::cout<<"Cannot add protein. There is a pathway having a protein with ID "<<proteinId<<".\n";
            }
            else{
                //Protein protein(proteinId);
                pathways.getItemTypePtrAt(pathways.getPosOf(pathwayId))->getNodePtr()->addProtein(proteinId);
                std::cout<<"Added protein "<<proteinId<<" to pathway "<<pathwayId<<".\n";
            }
        }
    }
}
void BiologicalPathway::removeProtein( const int proteinId, const int pathwayId ){
    Pathway* ptr;
    if(pathways.getLength()==0){
        std::cout<<"Cannot remove protein. There is no pathway with ID "<<pathwayId<<".\n";
    }
    else{
        ptr = findPathwayById(pathwayId);
        if(ptr==nullptr){
            std::cout<<"Cannot remove protein. There is no pathway with ID "<<pathwayId<<".\n";
            return;
        }
        else{
            bool doesIdExist=false;
            for(int i=1;i<=pathways.getLength();i++){
                if(pathways.getItemTypePtrAt(i)->getNodePtr()->doesProteinIdExist(proteinId)){
                    doesIdExist=true;
                }
            }
            if(!doesIdExist){
                std::cout<<"Cannot remove protein. Pathway "<<pathwayId<<" does not have a protein with ID "<<proteinId<<".\n";
            }
            else{
                pathways.getItemTypePtrAt(pathways.getPosOf(pathwayId))->getNodePtr()->removeProtein(proteinId);
                std::cout<<"Removed protein "<<proteinId<<" from pathway "<<pathwayId<<".\n";
            }
        }
    }
}
void BiologicalPathway::printProteinsInPathway( const int pathwayId ) const{
    Pathway* ptr;
    if(pathways.getLength()==0){
        std::cout<<"Cannot print proteins. There is no pathway with ID "<<pathwayId<<".\n";
    }
    else{
        ptr = findPathwayById(pathwayId);
        if(ptr==nullptr){
            std::cout<<"Cannot print proteins. There is no pathway with ID "<<pathwayId<<".\n";
            return;
        }
        else{
            Pathway pathway=pathways.getEntry(pathways.getPosOf(pathwayId));
            pathway.printProteins();
        }
    }
}
void BiologicalPathway::addGene( const int geneID, const string geneName, const int proteinId ){
    Pathway* pathwayPtr=nullptr;
    int proteinIndex=-1;
    if(pathways.getLength()!=0){
        bool doesGeneExist=false;
        for(int i=1;i<=pathways.getLength();i++){

            Pathway* pathway=pathways.getItemTypePtrAt(i)->getNodePtr();
            LinkedList<Protein>* proteinsList=pathway->getPtr();
            if(proteinsList!=nullptr){
                for(int j=1;j<=proteinsList->getLength();j++){

                    Protein* protein=proteinsList->getItemTypePtrAt(j)->getNodePtr();
                    if(protein->getId()==proteinId){
                        proteinIndex=j;
                        pathwayPtr=pathway;
                    }
                    Gene* genePtr=protein->findGeneById(geneID);
                    if(genePtr!=nullptr){
                        doesGeneExist=true;
                    }
                }
            }
        }
        if(doesGeneExist){
            std::cout<<"Cannot add gene. Gene "<<geneID<<" is already in use.\n";
        }
        else{
            if(pathwayPtr==nullptr || proteinIndex==-1){
                std::cout<<"Cannot add gene. There is no protein with ID "<<proteinId<<".\n";
            }
            else{
                //pathwayPtr->addProtein(2);
                Protein* proteinPtr=pathwayPtr->getPtr()->getItemTypePtrAt(proteinIndex)->getNodePtr();
                proteinPtr->addGene(geneID,geneName);
                std::cout<<"Added gene "<<geneID<<" to protein "<<proteinId<<".\n";
            }

        }
    }
}
void BiologicalPathway::removeGene( const int geneID, const int proteinId ){
    Pathway* pathwayPtr=nullptr;
    LinkedList<Protein>* proteinsList=nullptr;
    int proteinIndex=-1;
    if(pathways.getLength()!=0){
        bool doesGeneExist=false;
        for(int i=1;i<=pathways.getLength();i++){
            Pathway* pathway=pathways.getItemTypePtrAt(i)->getNodePtr();
            proteinsList=pathway->getPtr();
            if(proteinsList!=nullptr){
                for(int j=1;j<=proteinsList->getLength();j++){

                    Protein* protein=proteinsList->getItemTypePtrAt(j)->getNodePtr();
                    if(protein->getId()==proteinId){
                        proteinIndex=j;
                        pathwayPtr=pathway;
                    }

                    Gene* genePtr=protein->findGeneById(geneID);
                    if(genePtr!=nullptr){
                        doesGeneExist=true;
                    }
                }
            }
        }
        if(!doesGeneExist){
            std::cout<<"Cannot remove gene. There is no gene "<<geneID<<" encoding protein "<<proteinId<<".\n";
        }
        else{
            /*if(proteinsList!=nullptr){

                std::cout<<proteinsList->getLength();
            }*/
            if(pathwayPtr==nullptr || proteinIndex==-1){
                std::cout<<"Cannot remove gene. There is no protein with ID "<<proteinId<<".\n";
            }
            else{
                //pathwayPtr->addProtein(2);
                Protein* proteinPtr=pathwayPtr->getPtr()->getItemTypePtrAt(proteinIndex)->getNodePtr();
                proteinPtr->removeGene(geneID);
                std::cout<<"Removed gene "<<geneID<<" from protein "<<proteinId<<".\n";
            }

        }
    }
}
void BiologicalPathway::printGenesOfProtein( const int proteinId ) const{
    Protein* proteinPtr=nullptr;
    if(pathways.getLength()!=0){
        for(int i=1;i<=pathways.getLength();i++){
            //std::cout<<"print"<<pathways->getLength();
            proteinPtr=pathways.getItemTypePtrAt(i)->getNodePtr()->findProteinById(proteinId);
            if(proteinPtr!=nullptr){
                proteinPtr->printGenes();
                break;
            }
        }
    }
    if(proteinPtr==nullptr){
        std::cout<<"Cannot print genes. There is no protein with ID "<<proteinId<<".\n";
    }
}

Pathway* BiologicalPathway::findPathwayById( const int pathwayId )const{
    int index = pathways.getPosOf(pathwayId);
    if(index==-1){
        return nullptr;
    }
    return pathways.getItemTypePtrAt(index)->getNodePtr();


}
/*int main(){
    BiologicalPathway biologicalPathway;

 biologicalPathway.addPathway(915, "Apoptosis Signaling Pathway");
 biologicalPathway.addPathway(915, "Apoptosis Signaling Pathway");
 biologicalPathway.addPathway(908, "BLKNT Regulatory Pathway");
 biologicalPathway.addPathway(901, "Notch Signaling Pathway");
 cout << endl;

 biologicalPathway.addProtein(56,915);
 biologicalPathway.addProtein(51,915);
 biologicalPathway.addProtein(59,915);
 biologicalPathway.addProtein(59,999);
 cout << endl;

 biologicalPathway.addProtein(63,908);
 biologicalPathway.addProtein(67,908);

 biologicalPathway.addProtein(56,908);
 cout << endl;

 biologicalPathway.addGene(41,"TYUI",63);
 biologicalPathway.addGene(48,"BNMF",63);
 biologicalPathway.addGene(13,"CFTR",51);
 biologicalPathway.addGene(13,"TYOT",56);
 biologicalPathway.addGene(11,"TYQT",98);
 biologicalPathway.addGene(16,"RTYU",51);
 biologicalPathway.addGene(18,"REYU",59);
 biologicalPathway.addGene(21,"TYUJ",59);
 biologicalPathway.addGene(13,"YUIN",67);
 biologicalPathway.addGene(29,"BNMB",59);
 cout << endl;

 biologicalPathway.printProteinsInPathway(1005);
 biologicalPathway.printProteinsInPathway(915);
 biologicalPathway.printProteinsInPathway(901);
 cout << endl;
 biologicalPathway.printGenesOfProtein(59);
 biologicalPathway.printGenesOfProtein(56);
 biologicalPathway.printGenesOfProtein(11);
 cout << endl;

 biologicalPathway.removeGene(21,89);
 biologicalPathway.removeGene(21,59);
 cout<<"emonke\n";
 //biologicalPathway.printProteinsInPathway(915);
 biologicalPathway.removeGene(13,51);
 biologicalPathway.removeGene(895,51);
 cout << endl;

 biologicalPathway.removeProtein(63,908);
 biologicalPathway.removeProtein(63,908);
 biologicalPathway.removeProtein(56,1005);
 cout << endl;

 biologicalPathway.printPathways();
 cout << endl;

 biologicalPathway.removePathway(915);
 biologicalPathway.removePathway(915);
 cout << endl;

 biologicalPathway.printPathways();
 cout << endl;


 biologicalPathway.removePathway(901);
 biologicalPathway.removePathway(908);
 cout << endl;

 biologicalPathway.printPathways();

 return 0;
}*/

