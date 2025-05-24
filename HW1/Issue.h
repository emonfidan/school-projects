#ifndef ISSUE_H_INCLUDED
#define ISSUE_H_INCLUDED
#include <string>
class Issue{
public:
    Issue(const int issueId, const std::string description, const std::string
assigneeName,const int numOfOrder);
    int getId();
    int getNumOfOrder();
    std::string info();
private:
    const int issueId;
    const std::string description;
    const std::string assigneeName;
    const int numOfOrder;

};

#endif // ISSUE_H_INCLUDED
