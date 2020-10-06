#include <iostream>
using namespace std;

void swap(){
}

void max_heapify(int* A, int heapsize, int i){
    int l = 2*i;
    int r = 2*i + 1;
    int largest = i;
    if(l <= heapsize && A[l] > A[i]){
        
    }
    //finish
    if(i != largest){
        swap(A[i], largest);
        max_heapify(A, heapsize,largest);
    }
}

void build_heap(int* A, int n){
    int heapsize = n;
    //finish
}

void heapsort(int* A, int n){
    build_heap(A, n);
    int heapsize = n;
    for(int i = n; i > 1; i--){
        swap(A[1], A[i]);
        heapsize--;
        max_heapify(A, 1, heapsize);
    }
}

int main(){
    int n = 0;
    cin >> n;

    int* arr = new int[n+1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    heapsort(arr, n);

    for(int i = 1; i <= n; i++){
        cout << arr[i] << ";";
    }

    return 0;
}