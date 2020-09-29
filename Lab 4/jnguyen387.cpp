#include <iostream>
#include <climits>
using namespace std;

int max_crossing(int* arr, int low, int mid, int high){
  int left_sum = INT_MIN;
  int sum = 0;
  // finish ...

  int right_sum = INT_MIN;
  int sum = 0;
  // finish ...

  return left_sum + right_sum;
}

int max_subarray(int* arr, int low, int high){
  if (low == high){
    return arr[low];
  }
  int mid = (low + high) / 2;
  int left_sum = max_subarray(arr, low, mid);
  int right_sum = max_subarray(arr, mid+1, high);
  int cross_sum = max_crossing(arr, low, mid, high);
  
  if (left_sum >= right_sum && left_sum >= cross_sum){
    return left_sum;
  }
  // finish...

}

int main(){
  
  int n;
  cin>>n;

  int* arr = new int[n];
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }

  // maybe just n not (n-1)?
  int max_sum = max_subarray(arr, 0, n-1);
  cout<<max_sum;

  return 0;
}
