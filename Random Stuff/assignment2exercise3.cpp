#include<iostream>
#include <math.h>

using namespace std;
int main(){

    int m = 6;

    int k;
    cout << "k value: ";
    cin >> k;

    int h =  k % m;

    cout << "h(k) value: " << h << "\n ";

    return 0;
}