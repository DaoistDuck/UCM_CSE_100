#include <iostream>
#include <climits>
#include <vector>

//https://stackoverflow.com/questions/28663299/declaring-a-2d-vector used this to understand how to declare the 2d vector

void POP(std::vector<std::vector<int>> s, int i, int j){
    if(i == j){
        std::cout<<"A" << i-1;
    }else{
        std::cout<<"(";
        POP(s,i,s[i][j]);
        POP(s,s[i][j] + 1, j);
        std::cout<<")";
    }   
}

void MCO(int *p, int n,std::vector<std::vector<int>> m,std::vector<std::vector<int>> s){
    for(int i = 1; i < n; i++){
        m[i][i] = 0;
    }

    for(int l = 2; l < n; l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for(int k = i; k < j; k++){
                int q = m[i][k] + m[k+1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
                
            }            
        }
    }
    std::cout<< m[1][n-1] << std::endl;
    POP(s,1,n-1);
    std::cout<<std::endl;   
} 

int main(){
    int n;
    std::cin>>n;
    int p[n+1];
    for(int i = 0; i <= n;i++){
        std::cin>>p[i];
    }

    int N = sizeof(p)/sizeof(p[0]);
    std::vector<std::vector<int>> m(N, std::vector<int> (N));
    std::vector<std::vector<int>> s(N, std::vector<int> (N));

    MCO(p,N,m,s);
    return 0;
}