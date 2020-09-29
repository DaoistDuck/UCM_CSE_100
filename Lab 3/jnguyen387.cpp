#include <iostream>
#include <climits>
using namespace std;

void fillingArray(int* mergeArray, int sizeOfArray){
    int newElement;
     for(int i = 0; i < sizeOfArray; i++){
        cin >> newElement;
        mergeArray[i] = newElement;
    }
}

void printMergeArray(int *mergeArray, int sizeOfArray){
    for(int i = 0; i < sizeOfArray; i++){
        cout <<  mergeArray[i] <<";";
    }
}
void mergeAll(int* mergeArray, int beginning, int middle, int end){
    int i,j,k;
    int length1 = middle - beginning + 1;
    int length2 = end - middle;
    int *leftArray = new int[length1 + 1];  
    int *rightArray = new int[length2 + 1];     

    for(i = 0; i < length1; i++){
        leftArray[i] = mergeArray[beginning + i];
    }

    for(j = 0; j < length2; j++){
        rightArray[j] = mergeArray[middle + j + 1];
    }

    leftArray[length1 + 1] = INT_MAX;
    rightArray[length2 + 1] = INT_MAX;

    i = 0;
    j = 0;
    
    for(k = beginning; k <= end && i < length1 && j < length2; k++){
        if(leftArray[i] <= rightArray[j]){
            mergeArray[k] = leftArray[i];
            i++;
        }else{
            mergeArray[k] = rightArray[j];
            j++;
        }
    }

    for(i = i; i < length1; i++){
        mergeArray[k] = leftArray[i];
        k++;
    }

    for(j = j; j < length2; j++){
        mergeArray[k] = rightArray[j];
        k++;
    }
}

void mergeSort(int* mergeArray, int beginning, int end){
    if(beginning < end){
        int middle = (beginning + end)/2;
        mergeSort(mergeArray, beginning, middle);
        mergeSort(mergeArray, middle + 1, end);
        mergeAll(mergeArray, beginning, middle, end);
    }
}

int main(){

    int sizeOfArray;
    cin >> sizeOfArray;

    int *mergeArray = new int[sizeOfArray];      

    fillingArray(mergeArray, sizeOfArray);

    int beginning = 0;
    int end = sizeOfArray;

    mergeSort(mergeArray, beginning, end-1);

    printMergeArray(mergeArray, sizeOfArray);

    return 0;
}