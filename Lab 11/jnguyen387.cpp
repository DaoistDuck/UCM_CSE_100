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

        void insertKey(BST&, Node*);

        bool searchKey(Node* , int);

        Node* searchKeyNode(Node*, int);

        void transplantNode(BST&, Node*, Node*);

        Node* treeMinimum(Node*);     

        void deleteKey(BST&, Node*);           

        void preOrder(Node*);

        void postOrder(Node* n);

        void inOrder(Node* n);

};

BST::BST(){
    root = nullptr;    
}

Node* newNode(int key){
    Node* tempNode = new Node;
    tempNode -> key = key;
    tempNode->left = tempNode->right = tempNode->parent = nullptr;

    return tempNode;    
}

void BST::insertKey(BST &T, Node* z){
    Node* y = nullptr;
    Node* x = T.root; 

    while(x != nullptr){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    z->parent = y;

    if(y == nullptr){
        T.root = z;
    }else if(z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }
}

bool BST::searchKey(Node* x, int key){
    while(x != nullptr){
        if(key == x->key){
            return true;
        }

        if(key < x->key){
            return searchKey(x->left, key);
        } else{
            return searchKey(x->right, key);
        }
    }
    return false;      
}

Node* BST::searchKeyNode(Node* x, int key){
    while(x != nullptr && key != x->key){
        if(key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    return x;
}

void BST::transplantNode(BST &T, Node* u, Node* v){
    if(u->parent == nullptr){ 
        T.root = v;
    }else if(u == u->parent->left){ 
        u->parent->left = v;
    }else{
        u->parent->right = v; 
    }
    if(v != nullptr){
         v->parent = u->parent;
    }
}

Node* BST::treeMinimum(Node* x){
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}

void BST::deleteKey(BST &T, Node* z){
    if(z->left == nullptr){
        transplantNode(T,z,z->right);
        delete z;
    } else if(z->right == nullptr){
        transplantNode(T,z,z->left);
        delete z;
    } else {
        Node* y = treeMinimum(z->right);

        if(y->parent != z){
            transplantNode(T,y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplantNode(T,z,y);
        y->left = z->left;
        y->left->parent = y;
        delete z;
    }          
} 

void BST::preOrder(Node* n){
    if(n != nullptr){
        std::cout << n->key<<std::endl;
        this->preOrder(n->left);
        this->preOrder(n->right);
    }
}

void BST::inOrder(Node* n){
    if(n != nullptr){
        inOrder(n->left);
        std::cout << n->key << std::endl;
        inOrder(n->right);
    }
}

void BST::postOrder(Node* n){
    if(n != nullptr){            
        this->postOrder(n->left);
        this->postOrder(n->right);
        std::cout << n->key<<std::endl;
    }
}   

int main(){

    char input[100];
    BST tree;

    bool found = false;

    std::cin.getline(input,100);

    while(true){

        std::string s(input);

        if(s[0] == 'e'){
            break;
        }else if(s.substr(0,3) == "pre"){
            tree.preOrder(tree.root);
            std::cout<< "++++++++++++++++++++" << std::endl;

        }else if(s.substr(0,2) == "in"){
            tree.inOrder(tree.root);
            std::cout<< "++++++++++++++++++++" << std::endl;

        }else if(s.substr(0,4) == "post"){
            tree.postOrder(tree.root);
            std::cout<< "++++++++++++++++++++" << std::endl;

        }else if(s[0] == 'i'){
            int key = stoi(s.substr(2,s.length()-2));
            Node* keyNode = newNode(key);
            tree.insertKey(tree,keyNode);

        }else if(s[0] == 'd'){
            int key = stoi(s.substr(2,s.length()-2));
            found = tree.searchKey(tree.root, key);
            if(found == true){
                Node* keyNode = tree.searchKeyNode(tree.root, key);
                tree.deleteKey(tree,keyNode);
            }            
        }        

        std::cin.getline(input,100);

    }    

    return 0;
}