#include <iostream>
#include <time.h>
using namespace std;

void fillingArray(int* array, int sizeOfArray){
    int newElement;
     for(int i = 0; i < sizeOfArray; i++){
        cin >> newElement;
        array[i] = newElement;
    }
}

void printArray(int *array, int sizeOfArray){
    for(int i = 0; i < sizeOfArray; i++){
        cout <<  array[i] <<";";
    }
}

void swap(){
    
}

int partitionArray(int* quickArray, int left, int right){
    int x = quickArray[right];
    int i = left - 1;

    for(int j = left; j <= right - 1; j++){
        if(quickArray[j] <= x){
            i++;
            swap(quickArray[i], quickArray[j]);
        }
    }
    swap(quickArray[i + 1], quickArray[right]);

    return (i + 1);
}

int randomPartition(int* quickArray, int left, int right){
    int randomLocation = rand()%(right - left + 1) + left;
    swap(quickArray[right], quickArray[randomLocation]);
    return partitionArray(quickArray, left, right);
}

void randomQuickSort(int* quickArray, int left, int right){
    if(left < right){
        int randomLocation = randomPartition(quickArray, left, right);
        randomQuickSort(quickArray, left, randomLocation - 1);
        randomQuickSort(quickArray, randomLocation + 1, right);
    }
}

int main(){
    srand(time(NULL));

    int sizeOfArray = 0;
    cin >> sizeOfArray;

    int *quickArray = new int[sizeOfArray];      

    fillingArray(quickArray, sizeOfArray);

    randomQuickSort(quickArray, 0, sizeOfArray - 1);

    printArray(quickArray, sizeOfArray);

    return 0;
}