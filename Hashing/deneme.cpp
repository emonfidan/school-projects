#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Tuple.h"
#include "TwoTuples.h"
void partition2(Tuple* theArray, int first, int last, int &pivotIndex)
{
	 int pivot=theArray[first].getHash1();
	 int lastS1 = first;           // index of last item in S1
	 int firstUnknown = first + 1; // index of first item in unknown
	 for (  ; firstUnknown <= last; ++firstUnknown) {

        if (theArray[firstUnknown].getHash1() < pivot) {  // belongs to S1
            ++lastS1;
            std::swap(theArray[firstUnknown], theArray[lastS1]);
        } // else belongs to S2
      }   // place pivot in proper position and mark its location
      std::swap(theArray[first], theArray[lastS1]);
      pivotIndex = lastS1;
}

void quicksort2(Tuple* theArray, int first, int last)
{
	int pivotIndex;
	if (first < last) {      // create the partition: S1, pivot, S2
        partition2(theArray, first, last, pivotIndex);      // sort regions S1 and S2
        quicksort2(theArray, first, pivotIndex-1);
        quicksort2(theArray, pivotIndex+1, last);   }
}
std::string reverseString(std::string str) {
    int n = str.length();
    for (int i=0; i<n/2;i++) {
        char temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
    return str;
}
int hashString2 (const std::string &key,int tableSize){

   int hashVal = 0;

   for (int i = 0; i < key.length(); i++)
       hashVal = 37 * hashVal + key[i];

   hashVal %=tableSize;
   if (hashVal < 0)   /* in case overflows occurs */
       hashVal += tableSize;

   return hashVal;
}
void shiftLeft(std::string &str) {
    char chr = str[0];
    for (int i = 1; i < str.length(); i++) {
        str[i - 1] = str[i];
    }
    str[str.length() - 1] = chr;
}
int searchForSubstring2(Tuple tupleArr[], int tupleArrSize, int interestHash1, int interestHash2){
    int lowerBound=0;
    int higherBound=tupleArrSize;
    while(higherBound>=lowerBound){
        int middleIndex = (higherBound-lowerBound)/2 + lowerBound;
        if(interestHash1 == tupleArr[middleIndex].getHash1()){
            if(interestHash2 == tupleArr[middleIndex].getHash2()){
                return middleIndex;
            }
        }
        else if(interestHash1 > tupleArr[middleIndex].getHash1()){
            lowerBound=middleIndex+1;
        }
        else{
            higherBound=middleIndex-1;
        }
    }
    return -1;

}
std::string subtask3(){
    int noOfStrings=2;
    std::string strings[2]={"ba","ab"};
    int sum=0;
    for(int i=0;i<noOfStrings;i++){
        sum+=strings[i].length();
    }
    std::cout<<sum;

    Tuple normalTuples[sum];
    int normalTuplesIndex=0;
    Tuple reversedTuples[sum];
    int reversedTuplesIndex=0;

    for(int i=0;i<noOfStrings;i++){

        std::string str=strings[i];
        std::string reversedStr =reverseString(str);

        Tuple newtuple1(hashString2(str,1000000007),hashString2(str,1000000009),str,0);
        normalTuples[normalTuplesIndex] = newtuple1;
        normalTuplesIndex++;

        Tuple newtuple2(hashString2(reversedStr,1000000007),hashString2(reversedStr,1000000009),reversedStr,0);
        reversedTuples[reversedTuplesIndex] = newtuple2;
        reversedTuplesIndex++;

        //std::cout<<newtuple1.getStr()<<newtuple1.getHash1()<<"/";
        for(int j=1;j<str.length();j++){

            shiftLeft(str);
            shiftLeft(reversedStr);

            Tuple newtuple1(hashString2(str,1000000007),hashString2(str,1000000009),str,j);
            normalTuples[normalTuplesIndex] = newtuple1;
            normalTuplesIndex++;

            Tuple newtuple2(hashString2(reversedStr,1000000007),hashString2(reversedStr,1000000009),reversedStr,j);
            reversedTuples[reversedTuplesIndex] = newtuple2;
            reversedTuplesIndex++;

            //std::cout<<newtuple1.getStr()<<newtuple1.getHash1()<<"/";
            //std::cout<<newTuple2.getStr()<<"/";
        }
    }
    quicksort2(normalTuples,0,sum-1);
    quicksort2(reversedTuples,0,sum-1);
    for(int i=0;i<sum;i++){
        std::cout<<normalTuples[i].getStr()<<"-";
    }
    std::cout<<"\n";
    for(int i=0;i<sum;i++){
        std::cout<<reversedTuples[i].getStr()<<"-";
    }

    int minSubset=noOfStrings;
    int reverseOp=0;

    for(int i=0;i<noOfStrings;i++){
        std::string str=strings[i];
        std::cout<<str<<":\n";
        int hash1=hashString2(str,1000000007);
        int hash2=hashString2(str,1000000009);
        //for normalTuples
        int id = searchForSubstring2(normalTuples,sum,hash1,hash2);
        int pre=-1;
        int post=-1;
        if(id>0){
            pre=id-1;
        }
        if(id<sum-1){
            post=id+1;
        }
        if((post != -1 && normalTuples[post].getHash1()==hash1 && normalTuples[post].getHash2()==hash2)|| (pre != -1 && normalTuples[pre].getHash1()==hash1 && normalTuples[pre].getHash2()==hash2)){ //then str is repeated in normalTuples list
            minSubset--;
            Tuple nullTuple;
            normalTuples[id]=nullTuple;
            std::cout<<id<<"normal";
            for(int i=0;i<sum;i++){
                std::cout<<normalTuples[i].getStr()<<"-";
            }
        }
        else{
            //for reversedTuples
            id = searchForSubstring2(reversedTuples,sum,hash1,hash2);
            minSubset--;
            reverseOp++;
            Tuple nullTuple;
            reversedTuples[id]=nullTuple;
            std::cout<<id<<"reversed";


        }
    }
    std::cout<<reverseOp<<"\n"<<minSubset;
    /*for(int i=0;i<noOfStrings;i++){
        std::string str=strings[i];

        std::string reversedStr =reverseString(str);
        Tuple tupleArray1[str.length()];
        Tuple tupleArray2[str.length()];
        Tuple newtuple1(hashString2(str,1000000007),hashString2(str,1000000009),str,0);
        tupleArray1[0] = newtuple1;
        Tuple newtuple2(hashString2(reversedStr,1000000007),hashString2(reversedStr,1000000009),reversedStr,0);
        tupleArray2[0] = newtuple2;
        std::cout<<newtuple1.getStr()<<newtuple1.getHash1()<<"/";
        for(int j=1;j<str.length();j++){
            shiftLeft(str);
            shiftLeft(reversedStr);
            Tuple newTuple1(hashString2(str,1000000007),hashString2(str,1000000009),str,j);
            tupleArray1[j]=newTuple1;
            Tuple newTuple2(hashString2(reversedStr,1000000007),hashString2(reversedStr,1000000009),reversedStr,j);
            tupleArray2[j]=newTuple2;
            std::cout<<newTuple1.getStr()<<newTuple1.getHash1()<<"/";
            std::cout<<newTuple2.getStr()<<"/";
        }
        quicksort2(tupleArray1,0,str.length()-1);
        quicksort2(tupleArray2,0,str.length()-1);

        TwoTuples newTwoTuples(tupleArray1,tupleArray2,str.length(),0);
        //twotuples[0]=newTwoTuples;
        std::cout<<"two tuples created\n";

    }
    std::cout<<"end";
    //std::cout<<twotuples[0].getLength();
    for(int j=0;j<twotuples[0].getLength();j++){
            Tuple* tupleArr= twotuples[0].getTupleArr1();

            std::cout<<tupleArr[j].getStr();
            tupleArr= twotuples[0].getTupleArr2();
            std::cout<<tupleArr[j].getStr();

    }
    int minSubset=noOfStrings;
    int reverseOp=0;
    for(int i=0;i<noOfStrings;i++){
        for(int j=0;j<noOfStrings;j++){
            if(i!=j){
                int hash1= hashString2(strings[i],1000000007);
                int hash2= hashString2(strings[i],1000000009);
                std::cout<<twotuples[j].getLength();
                for(int k=0;k<twotuples[j].getLength();k++){
                    Tuple* tupleArr= twotuples[k].getTupleArr1();
                    std::cout<<tupleArr[i].getStr();
                }
                std::cout<<"end\n";
                /*int index1= searchForSubstring2(twotuples[j].getTupleArr1(),strings[j].length(),hash1,hash2);
                if(index1==-1){
                    int index2= searchForSubstring2(twotuples[j].getTupleArr2(),strings[j].length(),hash1,hash2);
                    if(index2!=1){
                        reverseOp++;
                        minSubset--;
                    }
                }
                else{
                    minSubset--;
                }
            }
        }
    }*/

    //std::string result=std::to_string(reverseOp)+"*\n"+std::to_string(minSubset)+"*\n";
    //std::cout<<result;
    return "result";
}
int main(){
    subtask3();
    return 0;
}
