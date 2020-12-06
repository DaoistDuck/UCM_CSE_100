#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

std::vector<int> bitCodeHolder;

//https://stackoverflow.com/questions/15643319/how-can-i-create-min-stl-priority-queue-of-node-structure-type this showed me how to use priority min queue, but for nodes

struct Node{
    int freq;
    bool isLeaf;
    Node* left;
    Node* right;
    Node(bool isLeaf,  int freq){
        left = right = nullptr;
        this->freq = freq;
        this->isLeaf = isLeaf;
    }
};

struct Compare{
    bool operator()(Node* l, Node* r){
        return (l->freq > r->freq);
    }
};

void printBits(int*b, int location, int tmp){   
    bitCodeHolder.push_back(-1); // puts a placeholder to find this freq 
    bitCodeHolder.push_back(tmp);
       
    for(int i = 0; i < location; i++){
        bitCodeHolder.push_back(b[i]);
    }      
}

void placeHuffmanCodeIntoVector(Node* root, int* b, int location){  //this puts 0 or 1 into b array if you are traveling left or right on the tree and prints out the binary code if the node is a leaf node
    
    if(root == nullptr){
        return;
    }
     if(root->isLeaf == true){
        printBits(b, location,root->freq);
    } 
    if(root->left){
        b[location] = 0;                              
        placeHuffmanCodeIntoVector(root->left,b,location+1);
    }
    if(root->right){
        b[location] = 1;
        placeHuffmanCodeIntoVector(root->right, b,location+1);   
    }                  
}

Node* huffmanCode(int* c, int n){
    std::priority_queue<Node*, std::vector<Node*>,Compare> minPrioQueue;
    for(int i = 0; i < n; i++){
        minPrioQueue.push(new Node(true, c[i])); // mark all the node that are leaf nodes
    } 
    for(int i = 0; i < n - 1 ; i++){  
        Node* z; Node* x; Node* y;      
        x = minPrioQueue.top();
        minPrioQueue.pop();
        y = minPrioQueue.top();
        minPrioQueue.pop();
        z = new Node(false, x->freq + y->freq); // mark that this node isnt a leaf node
        z->left = x;
        z->right = y;        
        minPrioQueue.push(z);       
    }
    return minPrioQueue.top();
}


int main(){
    int n;
    std::cin>>n;
    int c[n];
    int counter = 0;

    for(int i = 0; i < n; i++){
        std::cin>>c[i];
        counter++;      
    }
    
    int size = sizeof(c)/sizeof(c[0]);  
    Node* rootPointer = huffmanCode(c,size);
    int bits[n];
    int leafLocation = 0;
    placeHuffmanCodeIntoVector(rootPointer, bits, leafLocation);    

    int matchingIndex = 0;
    int tmpIndex = 0;
    std::vector<int>::iterator it;
    int endPositionLocation = 0;

    while(counter != 0){
        it = std::find(bitCodeHolder.begin(),bitCodeHolder.end(), c[tmpIndex]); // goes through the vector to find where c[tmpIndex] is

        matchingIndex = std::distance(bitCodeHolder.begin(), it) + 1;

        for(int i = matchingIndex; i < bitCodeHolder.size(); i++){            
            if(bitCodeHolder[i] == -1){
                endPositionLocation = i;
                bitCodeHolder.erase(bitCodeHolder.begin() + matchingIndex - 2, bitCodeHolder.begin() + endPositionLocation); // after printing out the bits, delete the -1, the freq, and the bits
                break;
            }                    
            std::cout<< bitCodeHolder[i];
        }        
        std::cout<<std::endl;           
        tmpIndex++;
        counter--;
    }    
    return 0;
}