#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


TEST(HEAP, HeapCheck) {
    string expectedinputFile;
    expectedinputFile = "expectedOutput3.txt";
    ifstream file1( expectedinputFile );
    string expectedOutput = "";
    string linea;
    while ( getline( file1, linea ) ) {
        expectedOutput = expectedOutput + linea + "\n";
    }

    string testinputFile;
    testinputFile = "output3.txt";
    ifstream file2( testinputFile );
    string testOutput = "";
    string lineb;
    while ( getline( file2, lineb ) ) {
        testOutput = testOutput + lineb + "\n";
    }


    EXPECT_EQ( testOutput, expectedOutput );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
