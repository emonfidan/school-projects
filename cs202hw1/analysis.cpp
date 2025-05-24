/**
* Title: Binary Search Trees
* Author : Emine Fidan
* ID: 22102860
* Section : 2
* Homework : 1
* Description : analysis implementation file
*/
#include <ctime>
#include <chrono>
#include <cstdlib>
#include "analysis.h"
#include "BST.h"
void analysis::timeAnalysis(){

    const int totalNumbers = 10000;
    const int step = 1000;
    BST bst(nullptr,0);
    std::srand(std::time(nullptr));
    auto startTime=std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= totalNumbers; ++i) {

        int randomNumber = std::rand() % i-(i*1000) + 1;
        bst.insertKeyWithoutOutput(randomNumber);

        if (i % step == 0) {
            auto endTime = std::chrono::high_resolution_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

            std::cout << "Time taken for " << i << " insertions: " << elapsedTime.count() << " milliseconds" << std::endl;
            std::cout << "Height of the tree: " << bst.findHeight() << std::endl;
            startTime=std::chrono::high_resolution_clock::now();
        }
    }

}
/*int main(){
    analysis t;
    t.timeAnalysis();

    return 0;
}*/
