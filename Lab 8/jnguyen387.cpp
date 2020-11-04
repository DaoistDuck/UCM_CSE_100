#include <iostream>
#include <vector>
#include <cmath>

void insertion_sort(std::vector<float> &bi){
    
    float i,j,key;
    for(j = 1; j < bi.size(); j++){
        key = bi[j];
        i = j - 1;

        while(i >= 0 && bi[i] > key){
            bi[i + 1] = bi[i];
            i = i - 1;
        }
        bi[i + 1] = key;
    }

    for(int i = 0; i < bi.size(); i++){
        std::cout << bi[i] << "\n";
    }
}

void bucket_sort(float* A, int n){

    std::vector<float>* B = new std::vector<float>[n];

    for(int i = 0; i < n; i++){
        
        int f = floor(n*A[i]); 

        B[f].push_back(A[i]);

    }

    for(int i = 0; i < n; i++){
        insertion_sort(B[i]);
    }
}

int main(){
    int n;
    std::cin >> n;

    float* A = new float[n];

    for(int i = 0; i < n; i++){
        std::cin >> A[i];
    }

    bucket_sort(A,n);

    delete(A);

    return 0;
}