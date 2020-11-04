#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int insertion_sort(vector<float> bi){

    //use code from lab 0 bi[0]

    int bi_sorted;
    //can print my sorted array bi separated by newline
    return bi_sorted;
}

void bucket_sort(float* A, int n){

    vector<float>* B = new vector<float>[n];

    for(int i = 0; i < n; i++){
        
        int f = floor(n*A[i]); 

        B[f].push_back(A[i]);

    }

    for(int i = 0; i < n; i++){
        insertion_sort(B[i]); // use lab 0 and modify it 
    }

    // you can print the result here

}

int main(){
    int n;
    cin >> n;

    float* A = new float[n];

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    bucket_sort(A,n);

    delete(A);

    return 0;
}