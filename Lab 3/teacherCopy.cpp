#include <iostream>
#include <climits>
//#define MAX_INT 2147483647

using namespace std;

void Merge(int *array, int p, int q, int r){
  //int myinf = INT_MAX;
  int n1 = ...;
  int n2 = ...;
  int* L;
  int* R;
  // copy elements from p to q in 'array' into L
  // copy elements from q to r in 'array' into R

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  // complete

}

void MergeSort(int *array, int p, int r) {
  if (p < r){
    int q = (p + r) / 2;
    MergeSort(array, p, q);
    MergeSort(array, q+1, r);
    Merge(array, p, q, r);
  }
}
  

int main(int argc,char **argv) {

  int arraySize = 10;

  // Get the size of the sequence
  cin >> arraySize;
  int* Sequence = new int[arraySize];
    
  // Read in the sequence
  for(int i=0; i<arraySize; i++)
    cin >> Sequence[i];

    // Run the merge sort algorithm on the sequence
  int p = 0;
  int r = arraySize;
  MergeSort(Sequence,p,r);
    
  // Print the sorted sequence
  //  for(int i=0; i<arraySize; i++)
  //    cout << Sequence[i] << endl;
    
    // Free 
