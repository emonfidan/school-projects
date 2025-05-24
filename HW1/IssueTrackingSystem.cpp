#include "IssueTrackingSystem.h"
#include <string>
#include <iostream>
IssueTrackingSystem::IssueTrackingSystem(){
    numOfEmployees=0;
    employees=nullptr;
    numOfIssues=0;
    issues=nullptr;
}
IssueTrackingSystem::~IssueTrackingSystem(){

}
/*void IssueTrackingSystem::addEmployee( const std::string name, const std::string title ){
    if(doesEmployeeExist(name)){
        cout<<"Employee already exists!"<<endl;
    }
    else{
        Employee e(name,title,numOfEmployees);
        Employee *newEmployees=new Employee[numOfEmployees+1];
        if(employees){
            for(int i=0;i<numOfEmployees;i++){
                newEmployees[i]=employees[i];
            }
            delete[] employees;
        }
        newEmployees[numOfEmployees]=e;
        employees=newEmployees;
        numOfEmployees++;
    }

}
void IssueTrackingSystem::removeEmployee( const string name ){
    if(!doesEmployeeExist(name)){
        cout<<"Employee you wanna delete does not exist!"<<endl;
    }
    else{
        int split=getIdByName(name);
        Employee *newEmployees=new Employee[numOfEmployees-1];
        for(int i=0;i<split;i++){
            newEmployees[i]=employees[i];
        }
        for(int i=split;i<numOfEmployees-1;i++){
            newEmployees[i]=employees[i+1];
        }
        delete[] employees;
        employees=newEmployees;
    }
}*/
void IssueTrackingSystem::addIssue( const int issueId, const std::string description, const std::string
assigneeName ){
    if(doesIssueExist(issueId)){
        cout<<"issue exists"<<endl;
    }
    else{
        int employeeId=getIdByName(assigneeName);
        Employee e=getEmployeeByName(assigneeName);
        int oldNumOfIssues=e.getNumOfIssues();
        if(*issues[employeeId]){
            Issue* newIssues=new Issue[oldNumOfIssues+1];
            for(int i=0;i<oldNumOfIssues;i++){
                newIssues[i]=*issues[employeeId][i];
            }
            newIssues[oldNumOfIssues]=Issue(issueId,description,assigneeName,e.getNumOfIssues);
            delete[]*issues[employeeId];
            *issues[employeeId]=newIssues;
        }
        else{
            *issues[employeeId]=new Issue[1];
            *issues[employeeId][0]=Issue(issueId,description,assigneeName,0);
        }
        e.addIssue();

    }
}
void IssueTrackingSystem::removeIssue( const int issueId ){
    int issueOrder=doesIssueExist(issueId);
    if(issueOrder==-1){
        cout<<"issue does not exist"<<endl;
    }
    else{
        int employeeId=getIdByName(assigneeName);
        Employee e=getEmployeeByName(assigneeName);
        int oldNumOfIssues=e.getNumOfIssues();
        if(oldNumOfIssues>1){
            Issue* newIssues=new Issue[oldNumOfIssues-1];

            for(int i=0;i<issueOrder;i++){
                newIssues[i]=*issues[employeeId][i];
            }
            for(int i=split;i<oldNumOfIssues-1;i++){
                newIssues[i]=*issues[employeeId][i+1];
            }
            delete[]*issues[employeeId];
            *issues[employeeId]=newIssues;
        }
        else{
            *issues[employeeId]=nullptr;
        }
        e.removeIssue();
    }
}
IssueTrackingSystem::changeAssignee( const std::string previousAssignee, const std::string newAssignee ){

}
void IssueTrackingSystem::showAllEmployees() const{
    for(int i=0;i<numOfEmployees;i++){
        cout<<employees[i].info()<<endl;
    }
}
void IssueTrackingSystem::showAllIssues() const{
    for(int i=0;i<numOfEmployees;i++){
        for(int j=0;j<employees[i].getNumOfIssues;j++){
            if(issues[i][j].getId()==issueId){
                cout<<issues[i][j].info()<<endl;
            }
        }

    }
}
void IssueTrackingSystem::showEmployee( const std::string name ) const{
    cout<<getEmployeeByName(name).info()<<endl;
}
void IssueTrackingSystem::showIssue( const int issueId ) const{
    cout<<getIssueById(issueId).info()<<endl;
}
bool IssueTrackingSystem::doesEmployeeExist(std::string name){
    for(int i=0;i<numOfEmployees;i++){
        if(employees[i].getName()==name){
            return true;
        }
    }
    return false;
}
int IssueTrackingSystem::doesIssueExist(const int issueId){
    for(int i=0;i<numOfEmployees;i++){
        for(int j=0;j<employees[i].getNumOfIssues;j++){
            if(issues[i][j].getId()==issueId){
                return issues[i][j].getNumOfOrder();
            }
        }

    }
    return -1;
}
int IssueTrackingSystem::getIdByName(std::string name){
    for(int i=0;i<numOfEmployees;i++){
        if(employees[i].getName()==name){
            return employees[i].getId();
        }
    }
    return -1;
}
Employee IssueTrackingSystem::getEmployeeByName(std::string name){
    for(int i=0;i<numOfEmployees;i++){
        if(employees[i].getName()==name){
            return employees[i];
        }
    }
    return nullptr;
}
Issue IssueTrackingSystem::getIssueById(int id){
    for(int i=0;i<numOfEmployees;i++){
        for(int j=0;j<employees[i].getNumOfIssues;j++){
            if(issues[i][j].getId()==issueId){
                return issues[i][j];
            }
        }

    }
    return nullptr;
}

/*int main() {
    IssueTrackingSystem issueTracker;

    // Add employees
    issueTracker.addEmployee("John Doe", "Developer");
    issueTracker.addEmployee("Alice Smith", "QA Engineer");

    // Show all employees
    issueTracker.showAllEmployees();

    // Add issues
    issueTracker.addIssue(1, "Bug in the login system", "John Doe");
    issueTracker.addIssue(2, "UI glitch on homepage", "Alice Smith");

    // Show all issues
    issueTracker.showAllIssues();

    // Remove an employee
    issueTracker.removeEmployee("John Doe");

    // Remove an issue
    issueTracker.removeIssue(2);

    return 0;
}*/
