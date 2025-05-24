#include "Issue.h"
#include <string>
using namespace std;
Issue::Issue(const int issueI, const string descriptio, const string
assigneeNam,const int numOfOrde): issueId(issueI), description(descriptio), assigneeName(assigneeNam), numOfOrder(numOfOrde) {

}
int Issue::getId(){
    return issueId;
}
int Issue::getNumOfOrder(){
    return numOfOrder;
}
string Issue::info(){
    return issueId+" "+description+" "+assigneeName;
}
