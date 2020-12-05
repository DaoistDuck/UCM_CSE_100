#include <iostream>
#include <vector>
#include <queue>
#include <functional>

//https://stackoverflow.com/questions/15643319/how-can-i-create-min-stl-priority-queue-of-node-structure-type

struct Node{
    int freq;
    char addedFreq;
    Node* left;
    Node* right;
    Node(char addedFreq, int freq){
        left = right = nullptr;
        this->freq = freq;
        this->addedFreq = addedFreq;
    }
};

struct Compare{
    bool operator()(Node* l, Node* r){
        return l->freq > r->freq;
    }
};

void printHuffmanCode(Node* root, std::string bit){
    if(root == nullptr){
        return;
    }
    if(root->addedFreq != '&'){
        std::cout << root->freq << " " << bit << std::endl;
    }    

    printHuffmanCode(root->left, bit + "0");
    printHuffmanCode(root->right, bit + "1");
}

Node* huffmanCode(int* c, int n){
    std::priority_queue<Node*, std::vector<Node*>,Compare> minPrioQueue;
    for(int i = 0; i < n; i++){
        minPrioQueue.push(new Node('*' , c[i])); // mark all the node so I know which ones are the ones added in later
    }    
    for(int i = 0; i < n - 2; i++){
        Node* z; Node* x; Node* y; Node* tmp;
        x = minPrioQueue.top();
        minPrioQueue.pop();
        y = minPrioQueue.top();
        minPrioQueue.pop();
        z = new Node( '&', x->freq + y->freq); // mark that this node isnt an original one
        z->left = x;
        z->right = y;        
        minPrioQueue.push(z);       
    }
    return minPrioQueue.top();
}


int main(){

    int n;

    std::cin>>n;

    int c[n+1];

    for(int i = 0; i < n; i++){
        std::cin>>c[i];        
    }
    
    int size = sizeof(c)/sizeof(c[0]);    

    Node* code = huffmanCode(c, size);

    printHuffmanCode(code, "");

    return 0;
}