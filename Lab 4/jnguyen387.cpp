#include <iostream>
#include <climits>
using namespace std;

void fillingArray(int* maxArray, int sizeOfArray){
    int newElement;
     for(int i = 0; i < sizeOfArray; i++){
        cin >> newElement;
        maxArray[i] = newElement;
    }
}

int maxCrossingArray(int* maxArray, int beginning, int middle, int end){
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int tempSum = 0;

    for(int i = middle; i >= beginning; i--){
        tempSum = tempSum + maxArray[i];

        if(tempSum > leftSum){
            leftSum = tempSum;
        }
    }

    tempSum = 0;

    for(int j = middle + 1; j <= end; j++){
        tempSum = tempSum + maxArray[j];

        if(tempSum > rightSum){
            rightSum = tempSum;
        }
    }

    return leftSum + rightSum;
}

int maxSubArray(int* maxArray, int beginning, int end){
    if(beginning == end){
        return maxArray[beginning];
    } 

    int middle = (beginning + end)/2;
    int leftSum = maxSubArray(maxArray, beginning, middle);
    int rightSum = maxSubArray(maxArray, middle + 1, end);
    int crossSum = maxCrossingArray(maxArray, beginning, middle, end);

    if(leftSum >= rightSum && leftSum >= crossSum){
        return leftSum;
    } else if(rightSum >= leftSum && rightSum >= crossSum){
        return rightSum;
    } else{
        return crossSum;
    }   
}

int main(){

    int sizeOfArray;
    cin >> sizeOfArray;

    int *maxArray = new int[sizeOfArray];      

    fillingArray(maxArray, sizeOfArray);

    int beginning = 0;
    int end = sizeOfArray - 1;

    int maxSum = maxSubArray(maxArray, beginning, end);

    cout<<maxSum;

    return 0;
}