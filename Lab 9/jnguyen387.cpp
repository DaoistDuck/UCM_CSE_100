#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

// part of deletion code i got from https://stackoverflow.com/questions/50868098/how-to-remove-only-one-element-from-a-vector-with-duplicates
// part of the search code https://stackoverflow.com/questions/7930887/find-index-of-iterator-in-stl-container-need-template-function
// part of printing code https://www.geeksforgeeks.org/c-program-hashing-chaining/


void print_hash_table(std::list<int>* hash_table, int m){
    //TODO: print hash table, follow the format
    for(int i = 0; i < m; i++){
        std::cout<< i << " : ";
        int count = 0;
        for(auto x : hash_table[i]){
            if(count == 0){
                std::cout << x; 
            }else{
                std::cout <<  "->" << x;
            }
            count++;                        
        }
        std::cout << std::endl;
    }
    
    std::cout << "++++++++++++++++++++"<< "\n";

}

int hash_function(int key, int m){

    return key % m;

}

void insert_key(std::list<int>* hash_table, int key, int m){

    //TODO: compute hash function, insert into table

    int idx = hash_function(key, m);
    hash_table[idx].push_front(key);

}

void delete_key(std::list<int>* hash_table, int key, int m){

    //TODO: compute hash function, delete from table

    int idx = hash_function(key, m);
    auto result = std::find(hash_table[idx].begin(), hash_table[idx].end(), key);
    if(result != hash_table[idx].end()){
        hash_table[idx].erase(result);
        std::cout << key << " : DELETED \n";            
    }else{
        std::cout << key << " : DELETE FAILED \n";
    }   
    
    std::cout << "++++++++++++++++++++"<< "\n";
}

void search_key(std::list<int>* hash_table, int key, int m){

    //TODO: compute hash function, search from table

    int idx = hash_function(key, m);
    //search inside list: hash_table[idx]
    int index = 0;
    bool missing = true;
    for(auto it = hash_table[idx].begin(); it != hash_table[idx].end(); ++it, ++index){
        if(*it == key){
            missing = false;
            break;
        }else{
            missing = true;
        }
    }

    if(missing){
        std::cout << key << " : NOT FOUND \n";
    }else{
        std::cout << key << " : FOUND AT " << idx << "," << index << "\n";
    }

    std::cout << "++++++++++++++++++++"<< "\n";
}

int main(){

    int m = 0;
    std::cin >> m;
    std::list<int>* hash_table = new std::list<int>[m];

    while(true){
        char c;
        std::cin >> c;

        if(c == 'e'){
            break;
        }
        else if(c == 'o'){
            print_hash_table(hash_table, m);
        }
        else if(c == 'i'){
            int key;
            std::cin >> key;
            insert_key(hash_table, key, m);
        }
        else if(c == 'd'){
            int key;
            std::cin >> key;
            delete_key(hash_table, key, m);

        }
        else if(c == 's'){
            int key;
            std::cin >> key;
            search_key(hash_table, key, m);
        }
    }
    return 0;
}