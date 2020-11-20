#include <iostream>
#include <climits>
#include <algorithm>

int cutRod(int*p, int n){
    if(n == 0){
        return 0;
    }
    int q = INT_MIN;
    for(int i = 1; i <= n; i++){
        q = std::max(q, p[i] + cutRod(p, n - i));
    }
    return q;
}

int memCutRodAux(int*p, int n, int*r){
    int q;
    if(r[n] >= 0){
        return 0;
    }
    if(n == 0){
        q = 0;
    }else{
        q = INT_MIN;
        for(int i = 1; i <= n; i++){
            q = std::max(q, p[i] + memCutRodAux(p, n - i, r));
        }
    }
    r[n] = q;
    return q;
}

int memCutRod(int*p, int n){
    int*r = new int[n+1];
    for(int i = 1; i <= n; i++){
        r[i] = INT_MIN;
    }
    return memCutRodAux(p,n,r);
}

int botUpCutRod(int*p, int n){
    int*r = new int[n+1];
    r[0] = 0;
    for(int j = 1; j <=n; j++){
        int q = INT_MIN;
        for(int i = 1; i <=j; i++){
            q = std::max(q, p[i] + r[j-1]);
        }
        r[j] = q;
    }
    return r[n];
}

void extBotUpCutRod(int*p, int n, int*r, int*s){
    r[0] = 0;
    for(int j = 1; j <= n; j++){
        int q = INT_MIN;
        for(int i = 1; i <= j; i++){
            int ri = p[i] + r[j - 1];
            if(q < ri){
                q = ri;
                s[j] = i;
            }
        }
        r[j] = q;
    }
}

void printCutRodSol(int*p, int n, int*r, int*s){

    extBotUpCutRod(p, n, r, s);

    while(n > 0){
        std::cout<<s[n] << " ";
        n = n - s[n];
    }
    std::cout<<"-1"<<std::endl;
}

int main(){
    int n;
    std::cin>>n;

    int*p = new int[n+1];
    int*r = new int[n + 1];
    int*s = new int[n + 1];
    for(int i = 1; i <= n; i++){
        std::cin>>p[i];
    }    

    std::cout<< r[n] << std::endl;

    printCutRodSol(p, n, r ,s);

    return 0;
}