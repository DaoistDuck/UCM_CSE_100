/*
resources used

referenced my notes from class to see the pseudocode of a binary search and understand how it works

*/

#include <iostream>
using namespace std;

void fillingArray(int* binaryArray, int sizeOfArray){
    int newElement;
     for(int i = 0; i < sizeOfArray; i++){
        cin >> newElement;
        binaryArray[i] = newElement;
    }
}

int binarySearch(int* binaryArray, int sizeOfArray, int elementWanted){
    int firstElement, lastElement, middleElement;

    firstElement = 0;
    lastElement = sizeOfArray - 1;

    while(firstElement <= lastElement){    

        middleElement = (firstElement + lastElement)/2;

        if(binaryArray[middleElement] == elementWanted){
            return middleElement;
        }else if(binaryArray[middleElement] < elementWanted){
            firstElement = middleElement + 1;
        } else{
            lastElement = middleElement - 1;
        }   
    }
    return -1;
}

int main(){

    int sizeOfArray;
    int elementWanted;
    int elementLocation;

    cin >> sizeOfArray;
    int *binaryArray = new int[sizeOfArray];    

    cin >> elementWanted;    

    fillingArray(binaryArray, sizeOfArray);

    elementLocation = binarySearch(binaryArray, sizeOfArray, elementWanted);
    cout << elementLocation;
}