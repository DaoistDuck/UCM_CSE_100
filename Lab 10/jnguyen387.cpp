#include <iostream>

const int m = 13;

int hashFunction(int key, int i){
    int h1 = key % m;
    int h2 = 1 + (key % 11);
    int h3 = (h1 + (i * h2)) % m;

    return h3;
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
            if(Table[h] == -1 || Table[h] == -2){
                Table[h] = key;
                break;   
            }         
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
        int index = -1;
        // 1. calc hash function
        for(int i = 0; i < m; i++){
            int h = hashFunction(key,i);
            if(Table[h] == key){
               index = h;
               break;
            }
            
        }
        //2. search the key in the hash table, print either index or message NOT_FOUND
        if(index != -1){
            std::cout<< index << std::endl;
        } else{
            std::cout << "NOT_FOUND" << std::endl;
        }
        
        std::cin >> key;
    }

    std::cout << "++++deleting++++" << std::endl;

    // Key Deleting
    std::cin >> key;
    while(key != -3){
        // 1. calc hash function
        for(int i = 0; i < m; i++){
            int h = hashFunction(key,i);
            if(Table[h] == key){
                Table[h] = -2;
                break;
            }
            
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