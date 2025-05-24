
#ifndef __GRADEBOOK_H
#define __GRADEBOOK_H
#include <string>
#include <iostream>
using namespace std;
void function(int a);
class GradeBook {
     public:
         GradeBook( int no );
         GradeBook( );
         void setCourseNo( int no );
         int getCourseNo( );
         void displayMessage( string msg );
         void displayMessage();
         double computeAvg();
    private:
         int courseNo;
}; // end of class

#endif
