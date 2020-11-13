#include <iostream>
#include <sstream>
#include <string>

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* parent;
};

class BST{        
    public:
        BST();
        Node* root;

        void insertKey(int key){
            Node* y;
            Node* x = this->root;
            while(x != NULL){
                y = x;
                if(key < x->key){
                    x = x->left;
                }else{
                    x = x->right;
                }
            }

            Node* z;
            z->key = key;
            z->parent = y;

            if(y == NULL){
                this->root = z;
            }else if(z->key < y->key){
                y->left = z;
            }else{
                y->right = z;
            }
        }

        void deleteKey(int key){

        }

        void preOrder(Node* n){
            if(n != NULL){
                std::cout << n->key<<std::endl;
                this->preOrder(n->left);
                this->preOrder(n->right);
            }
        }

        void postOrder(Node* n){

        }

        void inOrder(Node* n){

        }
};

int main(){

    char input[100];
    BST tree;

    std::cin.getline(input,100);

    while(true){

        std::string s(input); 

        if(s[0] == 'e'){
            break;
        }else if(s.substr(0,3) == "pre"){
            tree.preOrder(tree.root);
            std::cout<< "+++++++++++++++" << std::endl;

        }else if(s.substr(0,2) == "in"){
            tree.inOrder(tree.root);

        }else if(s.substr(0,4) == "post"){
            tree.postOrder(tree.root);

        }else if(s[0] == 'i'){
            int key = stoi(s.substr(2,s.length()-2));
            tree.insertKey(key);

        }else if(s[0] == 'd'){
            int key = stoi(s.substr(2,s.length()-2));
            tree.deleteKey(key);
        }

        std::cin.getline(input,100);

    }    

    return 0;
}