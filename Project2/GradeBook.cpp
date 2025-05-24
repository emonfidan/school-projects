#include <iostream>
using namespace std;
#include "GradeBook.h"
GradeBook::GradeBook( int no ) {
    setCourseNo( no ); }
GradeBook::GradeBook( ) {
    courseNo = 0; }
void GradeBook::setCourseNo( int no ) {
    if ((no >= 100) && (no <= 999))
        courseNo = no;
    else {
        cout << "invalid grade" << endl;
        courseNo = 0;  }
    }
int GradeBook::getCourseNo() {
    return courseNo; }
void GradeBook::displayMessage( string msg ) {
    cout << msg << " ";
    cout << getCourseNo() << "!" << endl;
}
void GradeBook::displayMessage() {
    cout << "Welcome to CS ";
    cout << getCourseNo() << "!" << endl; }
double GradeBook::computeAvg(){
    cout << "enter grades(negative value to quit)";
    int a,sum=0,count=0;
    cin >> a;
    while(a>=0){
        sum+=a;
        count++;
        cout << "enter grades(negative value to quit)";
        cin >> a;
    }
    if(count==0){
        return 0;
    }
    else{
        return static_cast<double> (sum)/count;
    }

}
