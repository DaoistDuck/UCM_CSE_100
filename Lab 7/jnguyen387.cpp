#include<iostream>
#include<vector>

using namespace std;

void printVector(vector <vector<int>> &allVectors){
    for(int i = 0; i < allVectors.size(); i++){ 
        for(int j = 0; j < allVectors[i].size(); j++){ 
            cout << allVectors[i][j] << ";";
        }
        cout << "\n";
    }
}

void bubbleSort(vector<vector<int>> &allVectors, int k){ //stable sort
    for( int j = 0; j < allVectors.size() - 1; j++){
        for(int l = allVectors.size() - 1; l > j; l--){
            if(allVectors[l][k] < allVectors[l-1][k]){
                allVectors[l].swap(allVectors[l-1]);
            }
        }
    }
}

void radixSort(vector <vector<int>> &allVectors){
    int index = 9;
    for(int i = index; i >= 0; i--){
       bubbleSort(allVectors,i);
    }
}

int main(){
    int numOfVectors = 0;
    cin >> numOfVectors;

    vector <vector<int>> allVectors;

    for(int i = 0; i < numOfVectors; i++){
        vector<int> row;                  
        for(int j = 0; j < 10; j++){
            int value;
            cin >> value;
            row.push_back(value);
        }
        allVectors.push_back(row);    
    }

    radixSort(allVectors);

    printVector(allVectors);

    allVectors.clear();
    allVectors.shrink_to_fit();
    return 0;
}