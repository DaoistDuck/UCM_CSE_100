#include <iostream>
#include <climits>
using namespace std;

void fillingArray(int* array, int sizeOfArray){
    int newElement;
     for(int i = 1; i <= sizeOfArray; i++){
        cin >> newElement;
        array[i] = newElement;
    }
}

void printArray(int *array, int sizeOfArray){
    for(int i = 1; i <= sizeOfArray; i++){
        cout <<  array[i] <<";";
    }
}

void swap(){
    
}

void maxHeapify(int *heapArray, int location, int heapSize){
    int leftNode = 2 * location;
    int rightNode = 2 * location + 1;
    int largest = location;
    
    if(leftNode <= heapSize && heapArray[leftNode] > heapArray[location]){
        largest = leftNode;
    } else{
        largest = location;
    }

    if(rightNode <= heapSize && heapArray[rightNode] > heapArray[largest]){
        largest = rightNode;
    }

    if(largest != location){
        swap(heapArray[location], heapArray[largest]);
        maxHeapify(heapArray,largest,heapSize);
    }

}

void buildMaxHeap(int* heapArray, int sizeOfArray){
    int heapSize = sizeOfArray;

    for(int i = (heapSize / 2); i > 0; i--){
        maxHeapify(heapArray, i, heapSize);
    }
}

void heapSort(int* heapArray, int sizeOfArray){
    buildMaxHeap(heapArray, sizeOfArray);

    int heapSize = sizeOfArray;
    for(int i = sizeOfArray; i > 1; i--){
        swap(heapArray[1], heapArray[i]);
        heapSize--;
        maxHeapify(heapArray, 1, heapSize);
    }
}

int main(){

    int sizeOfArray;
    cin >> sizeOfArray;

    int *heapArray = new int[sizeOfArray + 1];      

    fillingArray(heapArray, sizeOfArray);

    heapSort(heapArray, sizeOfArray);

    printArray(heapArray, sizeOfArray);

    return 0;
}