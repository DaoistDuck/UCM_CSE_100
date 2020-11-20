#include <iostream>
#include <climits>

int cut_rod(int *p, int n, int*r, int*s){
    if(n == 0){
        return 0;
    }

    if(r[n] >= 0){
        return r[n];
    }

    int q = INT_MIN;
    for(int i = 1; i <= n; i++){
        int ri = p[i] + cut_rod(p, n-i, r,s);
        if(ri > q){
            q = ri;
            s[n] = i;
        }
    }
    r[n] = q;
    return q;
}

int main()
{
    int n;
    std::cin>>n;

    int*p = new int[n+1];
    int*r = new int[n+1];
    int*s = new int[n+1];
    for(int i = 1; i <= n; i++){
        std::cin>>p[i];
        r[i] = INT_MIN;
        s[i] = INT_MIN;
    }

    std::cout<<cut_rod(p,n,r,s)<<std::endl;

    while(n > 0){
        std::cout<<s[n] << " ";
        n = n - s[n];
    }
    std::cout<<"-1"<<std::endl;

    return 0;
}