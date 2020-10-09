#include <iostream>
#include <time.h>
using namespace std;

int partition(int* A, int p, int r){
    //finish
}

int rpartition(int* A, int p, int r){
    int i = rand()%(r-p+1) + p;
    swap(A[i], A[r]);
    return partition(A, p ,r);
}

void rquicksort(int* A, int p, int r){
    if(p < r){
        int q = rpartition(A, p ,r);
        rquicksort(A,p,r-1);
        rquicksort(A,r+1,q);
    }
}

int main(){
    srand(time(NULL));

    int n = 0;
    cin >> n;

    int* arr= new int[n];
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    rquicksort(arr,0,n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << "i";
    }
    
    return 0;
}