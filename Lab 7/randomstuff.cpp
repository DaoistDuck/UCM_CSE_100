// lab 7 RadixSort
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> counting_sort(vector <vector<int>> A, int c, int n){
    int C[10];
    //first for loop here...

    // second for loop here...
    for(int j = 0; j < n; j++){
        C[A[j][c]] ++;
    }

    //third for loop here...


    //create another 2d vector for last loop
    vector <vector<int>> B = A;

    return B;
}

vector<vector<int>> radix_sort(vector <vector<int>> A, int n){
    int k = 9;
    vector <vector<int>> B = A;
    for(int i = k; i >= 0; i --){
       B =  counting_sort(B,i,n);
    }

    return B;
}

int main(){
    int arraySize = 0;
    cin >> arraySize;

    vector <vector<int>> Sequence;

    for(int i = 0; i < arraySize; i++){
        vector<int> row;
        for(int j = 0; j < 10; j++){
            int value;
            cin >> value;
            row.push_back(value);
        }
        Sequence.push_back(row);
    }

    vector <vector<int>> sorted = radix_sort(Sequence, arraySize);

    //print out sorted

    return 0;
}

