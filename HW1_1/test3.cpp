#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "IssueTrackingSystem.h"
//--------------------------------------------------------------------

TEST(employeeIssueAdd, employeeIssueAdd1) {
    string inputFile = BASE;
    inputFile += "/output3.txt";
    ifstream file( inputFile );
    string expectedOutput = "";
    string line;
    while ( getline( file, line ) ) {
        expectedOutput = expectedOutput + line + "\n";
    }
    stringstream ss;
    auto buffer = cout.rdbuf( ss.rdbuf() );

//--------------------------------------------------------------------
    IssueTrackingSystem ITS;

    ITS.showAllIssues();
    cout << endl;

    ITS.showAllEmployees();
    cout << endl;

    ITS.addEmployee("Robert", "Research Scientist");
    ITS.addEmployee("Ceren", "Software Engineer");
    ITS.addEmployee("Efe", "Product Manager");
    ITS.addEmployee("Robert", "Software Engineer");
    ITS.addEmployee("Merve", "Research Scientist");
    ITS.addEmployee("Batuhan", "Data Engineer");
    cout<<endl;

    ITS.showAllEmployees();
    cout<<endl;

    ITS.addIssue(1, "Code login page", "Batuhan");
    ITS.addIssue(2, "Create a new prediction algorithm for protein secondary structure using only amino acid sequence", "Robert");
    ITS.addIssue(3, "Create a new Naive Bayes based language model for protein sequences", "Ceren");
    ITS.addIssue(4, "Create a novel DNA sequencing method", "Merve");
    ITS.addIssue(5, "Plot results of the latest research experiment", "Merve");
    ITS.addIssue(6, "Fix 403 Forbidden Error", "Jonathan");
    ITS.addIssue(7, "Code logout page", "Efe");
    ITS.addIssue(8, "Fix 405 Method Not Allowed Error", "Batuhan");
    ITS.addIssue(9, "Fix 406 Not Acceptable Error","Ceren");
    ITS.addIssue(10, "Mine drug-target interaction data from web", "Robert");
    ITS.addIssue(8, "Fix 409 Conflict", "Robert");
    ITS.addIssue(9, "Fix 410 Gone Error", "Jonathan");
    ITS.addIssue(10, "Fix 411 Length Required Error", "Robert");
    cout<<endl;

    ITS.showAllEmployees();
    cout<<endl;

    ITS.showAllIssues();
    cout<<endl;

    ITS.showIssue(1);
    ITS.showIssue(4);
    ITS.showIssue(6);
//--------------------------------------------------------------------

    string testOutput = ss.str();
    EXPECT_EQ( testOutput, expectedOutput );
    cout.rdbuf( buffer );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
