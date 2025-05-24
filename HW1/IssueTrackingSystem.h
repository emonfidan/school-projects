#ifndef ISSUETRACKINGSYSTEM_H_INCLUDED
#define ISSUETRACKINGSYSTEM_H_INCLUDED
#include <string>
#include "Employee.h"
#include "Issue.h"
class IssueTrackingSystem {
public:
    IssueTrackingSystem();
    ~IssueTrackingSystem();
    void addEmployee( const std::string name, const std::string title );
    void removeEmployee( const std::string name );
    void addIssue( const int issueId, const std::string description, const std::string assigneeName );
    void removeIssue( const int issueId );
    void changeAssignee( const std::string previousAssignee, const std::string newAssignee );
    void showAllEmployees() const;
    void showAllIssues() const;
    void showEmployee( const std::string name ) const;
    void showIssue( const int issueId ) const;
    bool doesEmployeeExist(std::string name);
    int doesIssueExist(const int issueId);
    int getIdByName(std::string name);
    Issue getIssueById(int id);
private:
    Employee* employees;
    int numOfEmployees;
    Issue** issues;
    int numOfIssues;
};

#endif // ISSUETRACKINGSYSTEM_H_INCLUDED
