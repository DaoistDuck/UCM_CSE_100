/*
resources used

https://www.educative.io/edpresso/how-to-find-the-length-of-an-array-in-cpp
    this website helped me understand how to find the length of the array

http://www.cplusplus.com/reference/array/array/max_size/
    this website helped me refresh my c++ skills
    
textbook ch 2 page 18
    i referenced the pseudocode for the insertion sort

I asked in lecture 9/4/2020 to see how to get the numbers inputed and found out that it is user input 
*/
#include <iostream>
using namespace std;

void insertionSort(int insertionArray[], int sizeOfIArray){
    int i,j,key;
    for(j = 1; j < sizeOfIArray; j++){
        key = insertionArray[j];
        i = j -1;

        while(i >= 0 && insertionArray[i] > key){
            insertionArray[i + 1] = insertionArray[i];
            i = i - 1;
        }
        insertionArray[i + 1] = key;
    }
}

void printIArray(int insertionArray[], int sizeOfIArray){
    for(int i = sizeOfIArray - 1; i >= 0; i--){
        cout << insertionArray[i] <<";";
    }
}

void fillingIArray(int insertionArray[], int sizeOfIArray){
     for(int i = 0; i < sizeOfIArray; i++){
        cin >> insertionArray[i];
    }
}

int main ()
{
    int sizeOfIArray;    
    cin >> sizeOfIArray;
    int insertionArray[sizeOfIArray];

    fillingIArray(insertionArray, sizeOfIArray);  
    insertionSort(insertionArray, sizeOfIArray);
    printIArray(insertionArray, sizeOfIArray);   
    
}