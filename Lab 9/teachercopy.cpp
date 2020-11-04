#include <iostream>
#include <list>
#include <vector>

void print_hash_table(std::list<int>* hash_table, int m){

//TODO: print hash table, follow the format

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
hash_table[idx].remove(key);

}

void search_key(std::list<int> hash_table, int key, int m){

//TODO: compute hash function, search from table

int idx = hash_function(key, m);
//search inside list: hash_table[idx]
for (std::list<int>::iterator i = hash_table.begin(); i != hash_table.end(); ++i)
    std::cout << ' ' << *i;
  std::cout << '\n';

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
            //finish
        }
    }


    return 0;
}