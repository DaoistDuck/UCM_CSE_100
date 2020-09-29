/*
resources used:

http://www.cplusplus.com/reference/ostream/endl/
learned how to use endl to make grader grade my work correctly

*/

#include <iostream>
using namespace std;

void fillingArray(int* linearArray, int sizeOfArray){
    int newElement;
     for(int i = 0; i < sizeOfArray; i++){
        cin >> newElement;
        linearArray[i] = newElement;
    }
}
/*
int linearSearch(int* linearArray, int sizeOfArray, int elementWanted){
    for(int i = 0; i < sizeOfArray; i++){
        if(linearArray[i] == elementWanted){
            return i;
        }
    }
    return -1;
}
*/

int linearSearch(int* linearArray, int sizeOfArray, int elementWanted){
    if(sizeOfArray < 0){
        return -1;
    } else if(linearArray[sizeOfArray] == elementWanted){
        return sizeOfArray;
    } else{
        linearSearch(linearArray, sizeOfArray - 1, elementWanted);
    }   
   
}

int main(){

    int sizeOfArray;
    int elementWanted;
    int elementLocation;

    cin >> sizeOfArray;
    int *linearArray = new int[sizeOfArray];

    cin >> elementWanted;    

    fillingArray(linearArray, sizeOfArray);

    elementLocation = linearSearch(linearArray, sizeOfArray, elementWanted);
    cout << elementLocation;

    endl(cout);
}