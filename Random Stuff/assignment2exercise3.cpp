#include<iostream>
#include <math.h>

using namespace std;
int main(){

    int A = (sqrt(9) - 1)/2;
    int m = 10;

    int k;
    cout << "k value: ";
    cin >> k;

    int h = (2 * k + (3 * A)) % m;

    cout << "h value: " << h << "\n ";

    return 0;
}