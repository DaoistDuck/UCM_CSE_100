#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

int MCM(int *p, int i, int j, std::vector<std::vector<int>> m){
    if( i == j){
        return 0;
    }

    if(m[i][j] >= 0){
        return m[i][j];
    }

    int q = INT_MAX;
    for(int k = i; k < j; k++){
        int mk = MCM(p,i,k,m) + MCM(p,k+1,j,m) + p[i - 1] * p[k] * p[j];
        if(mk < q){
            q = mk;
        }
    }

    return q;
}

int main(){

    int n;
    std::cin>>n;
    int*p = new int[n+2];
    for(int i = 1; i <= n+1;i++){
        std::cin>>p[i];
    }

    std::vector<std::vector<int>> m;
    //create s
    for(int i = 0; i <=n+1;i++){
        std::vector<int> tmp;
        for(int j = 0; j <=n+1;j++){
            tmp.push_back(-1);
        }
        m.push_back(tmp);
    }

    std::cout<< MCM(p,1,n,m) << std::endl;
    // print s using recursively

    return 0;
}