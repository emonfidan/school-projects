#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <string>
using namespace std;
class Employee{
public:
    Employee(const string nam,const string tit,const int i);
    Employee(const Employee &another);
    Employee& operator=( const Employee& );
    string getName();
    int getId();
    int getNumOfIssues();
    void addIssue();
    void removeIssue();
    string info();
private:
    const string name;
    const string title;
    const int id;
    int numOfIssues;
};


#endif // EMPLOYEE_H_INCLUDED
