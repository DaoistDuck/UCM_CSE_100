#include <iostream>
#include <vector>
#include <climits>
bool check_empty(int *Q, int n){
    for(int i = 0; i < n; i++){
        if(Q[i] != -1){
            return false;
        }
    }
    return true;
}

int extract_min(int* Q, int n){
    int min = INT_MAX;
    int u;
    for(int i = 0; i < n; i++){
        if(Q[i] != -1 && Q[i] < min){
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
    int* parents = new int[n]; //going to output
    for(int i = 0; i < n; i++){
        Q[i] = INT_MAX;
    }

    Q[0] = 0;

    while(check_empty(Q, n)){
        int u = extract_min(Q, n);
        for(std::pair<int,int> p : G[u]){
            int v = p.first;
            int w = p.second;
            if(Q[v] != -1 && w < Q[v]){
                parents[v] = u;
                Q[v] = w;
            }
        }
    }
    //print array parents starting from 1

    for(int i = 1; i < n; i++){
        std::cout<<parents[i]<<std::endl;
    }

    int i = 0;
    if(i % n == 0){
        
    }

    return 0;
}