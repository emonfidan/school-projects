#include "Employee.h"
#include <string>
Employee::Employee(const string nam,const string tit,const int i): name(nam), title(tit), id(i) {

    numOfIssues=0;
}
Employee::Employee(const Employee &another): name(another.name), title(another.title), id(another.id), numOfIssues(another.numOfIssues){

}
Employee& Employee::operator=(const Employee& another) {
    if (this == &another) {
        return *this;
    }
    numOfIssues = another.numOfIssues;
    return *this;
}
string Employee::getName(){
    return name;
}
int Employee::getId(){
    return id;
}
int Employee::getNumOfIssues(){
    return numOfIssues;
}
void Employee::addIssue(){
    numOfIssues++;
}
void Employee::removeIssue(){
    numOfIssues--;
}
std::string Employee::info(){
    return name+" "+title+" "+std::to_string(numOfIssues)+" issues.";
}
