#include "GradeBook.h"
#include <iostream>
using namespace std;
static int a=0;
int findLargest(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
void computeSumProduct( const int x, const int y, int& sum, int& product ){
    sum = x + y;
    product = x * y;
    cout<<sum<<" "<<product;
}
int main(){
    int x;
    cin>>x;
    int* arr= new int[3];

    for(int i=0;i<x;i++){
        cout<<arr[i]<<endl;
    }

    delete[] arr;

    for(int i=0;i<x;i++){
        cout<<arr[i]<<endl;
    }

    return 0; }

void function(int a){
    cout << a;
}

