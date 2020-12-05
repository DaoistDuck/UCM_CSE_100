#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

std::vector<int> bitholder;
std::vector<int> tmpbitholder;
int oneLocation = 0;

//https://stackoverflow.com/questions/15643319/how-can-i-create-min-stl-priority-queue-of-node-structure-type

/*
    while(counter != 0){
        for(int i = 0; i < bitholder.size();i++){    
            if(c[matchingIndex] == 1){
                matchingLocation = oneLocation + 1;
                bitLocation[positionIndex] = matchingLocation;
                //std::cout<<matchingLocation<<std::endl;
                matchingIndex++;
                positionIndex++;
            }   
            if(c[matchingIndex] == bitholder[i]){
                //std::cout<<bitholder[i];
                matchingLocation = i + 1;
                bitLocation[positionIndex] = matchingLocation;
                //std::cout<<matchingLocation<<std::endl;
                matchingIndex++; 
                positionIndex++;   
            }           
        }
        counter--;
    }

    for(int i = 0; i < n; i++){
        //std::cout<<bitLocation[i] << " ";
    }
    //std::cout<<std::endl;

    int it = 0;
    int positionLocation = 0;
        
    while(printingCounter != 0){
        positionLocation = bitLocation[it];
        
        for(int i = positionLocation; i < bitholder.size(); i++){
            if(bitholder[i] == -1){
                break;
            }
            std::cout<<bitholder[i];
        }
        std::cout<<"\n";

        it++;
        printingCounter--;
    }
    */

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
        return (l->freq >= r->freq);
    }
};

void printBits(int*b, int location, int tmp){
    
    
    bitholder.push_back(-1);
    if(tmp == 1){
        oneLocation = bitholder.size();
    }     
     
    bitholder.push_back(tmp);
     
     
    
    for(int i = 0; i < location; i++){
        bitholder.push_back(b[i]);
    }
    for(int j = 0; j < bitholder.size(); j++){
            //std::cout<<bitholder[j]<< " ";
        }
        //std::cout<<std::endl;
    
}

void printHuffmanCode(Node* root, int* b, int location){
    int tmp;
    if(root->left){
        b[location] = 0;
        printHuffmanCode(root->left,b,location+1);
    }
    if(root->right){
        b[location] = 1;
        printHuffmanCode(root->right, b,location+1);   
    }   
   
    if(root->isLeaf == true){
        printBits(b, location,root->freq);
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

    Node* code = huffmanCode(c,size);

    std::string bit = "";

    int b[n];

    int leafLocation = 0;

    printHuffmanCode(code, b, leafLocation);

    int matchingIndex = 0;
    int positionIndex = 0;
    int matchingLocation = 0;

    tmpbitholder = bitholder;

    for(int j = 0; j < bitholder.size(); j++){
            std::cout<<bitholder[j]<< " ";
        }
        std::cout<<std::endl;
    int printingCounter = counter;

    int bitLocation[n];

    while(counter != 0){
        for(int i = 0; i < tmpbitholder.size();i++){    
            if(c[matchingIndex] == 1){
                matchingLocation = oneLocation + 1;
                bitLocation[positionIndex] = matchingLocation;
                //std::cout<<matchingLocation<<std::endl;
                matchingIndex++;
                positionIndex++;
            }   
            if(c[matchingIndex] == tmpbitholder[i]){
                //std::cout<<tmpbitholder[i];
                matchingLocation = i + 1;
                bitLocation[positionIndex] = matchingLocation;
                //std::cout<<matchingLocation<<std::endl;
                matchingIndex++; 
                positionIndex++;   
            }           
        }
        counter--;
    }

    for(int i = 0; i < n; i++){
        std::cout<<bitLocation[i] << " ";
    }
    std::cout<<std::endl;

    int it = 0;
    int positionLocation = 0;
    int endPositionLocation = 0;
        
    while(printingCounter != 0){
        positionLocation = endPositionLocation = bitLocation[it];
        
        for(int i = positionLocation; i < tmpbitholder.size(); i++){
            if(tmpbitholder[i] == -1){
                endPositionLocation = i;
                //std::cout<<endPositionLocation;
                break;
            }
            std::cout<<tmpbitholder[i];
        }
        std::cout<<"\n";
        it++;
        printingCounter--;
    }
  

    return 0;
}