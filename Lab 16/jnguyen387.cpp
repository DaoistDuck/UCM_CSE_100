#include <iostream>
#include <vector>
#include <climits>

int extract_min(int* Q, int n, bool* isInvalid){
    int min = INT_MAX;
    int u;
    for(int i = 0; i < n; i++){
        if(isInvalid[i] == false && Q[i] < min){
            min = Q[i];
            u = i;
        }
    }
    return u;
}

int main(){
    int n,m;
    std::cin>>n;
    std::cin>>m;

    std::vector<std::vector<std::pair<int,int>>> G;
    for(int i = 0; i < n; i++){
        std::vector<std::pair<int,int>> tmp;
        G.push_back(tmp);
    }

    for(int i = 0; i < m; i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        std::pair<int,int> p1(v,w);
        std::pair<int,int> p2(u,w);
        G[u].push_back(p1);
        G[v].push_back(p2);
    }

    int* Q = new int[n];
    bool* isInvalid = new bool[n];
    int* parents = new int[n]; //going to output
    for(int i = 0; i < n; i++){
        isInvalid[i] = false;
        Q[i] = INT_MAX;
        parents[i] = -1;
    }

    Q[0] = 0; 

    for(int i = 0; i < n - 1; i++){                  
        int u = extract_min(Q, n, isInvalid);
        isInvalid[u] = true;
        for(std::pair<int,int> p : G[u]){
            int v = p.first;
            int w = p.second;
            if(isInvalid[v] == false && w < Q[v]){
                Q[v] = w;
                parents[v] = u;
                
            }
        }
    }
    //print array parents starting from 1

    for(int i = 1; i < n; i++){
        std::cout<<parents[i]<<std::endl;
    }

    return 0;
}