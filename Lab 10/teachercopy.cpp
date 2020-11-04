#include <iostream>

const int m = 13;

int hashFunction(int key, int i){
    return key % m;
}

int main(){
    int key;

    //create Hash Table
    int Table[m];

    //Initialize Hash Table
    for(int i = 0; i < m; i++){
        Table[i] = -1;
    }

    //Key Insertion
    std::cin >> key;
    while(key != -1){
        // 1. calc hash function
        for(int i = 0; i < m; i++){
            int h = hashFunction(key,i);
            if(Table[h] == -1){
                break;
            }
            Table[h] = key;
        }
        
        
        //2. put it into hash table

        std::cin >> key;
    }

    // ++++table printout++++
    std::cout << "++++table printout++++" << std::endl;
    for(int i = 0; i < m; i++){
        if(Table[i] >= 0){
            std::cout << Table[i] << std::endl;
        } else{
            std::cout << std::endl;
        }
    }

    std::cout << "++++searching++++" << std::endl;

    //Key Searching
    std::cin >> key;
    while(key != -2){
        // 1. calc hash function
        for(int i = 0; i < m; i++){
            int h = hashFunction(key,i);
            if(Table[h] == -1){
                break;
            }
            Table[h] = key;
        }
        //2. search the key in the hash table, print either index or message NOT_FOUND
        
        std::cin >> key;
    }

    std::cout << "++++deleting++++" << std::endl;

    // Key Deleting
    std::cin >> key;
    while(key != -3){
        // 1. calc hash function
        for(int i = 0; i < m; i++){
            int h = hashFunction(key,i);
            if(Table[h] == -1){
                break;
            }
            Table[h] = key;
        }
        //2. delete a key from your hash table
        
        std::cin >> key;
    }

    // ++++table printout++++
    std::cout << "++++table printout++++" << std::endl;
    for(int i = 0; i < m; i++){
        if(Table[i] >= 0){
            std::cout << Table[i] << std::endl;
        } else{
            std::cout << std::endl;
        }
    }

    return 0;
}