#include<iostream>
using namespace std;
int dfs(int,int);

int dy[21][21];

int main(){
    freopen("input.txt","rt",stdin);

    int n,r;
    
    cin >> n >> r;
    int res = dfs(n,r);
    cout << res;
    // nCr = n!/(n-r)!*r! or nCr = n-1Cr-1 + n-1Cr

    return 0;
}

int dfs(int n,int r){
    if(dy[n][r]>0){
        return dy[n][r];
    }
    if(n==r||r==0){
        return 1;
    }else{
        dy[n][r] = dfs(n-1,r-1)+dfs(n-1,r);
        return dy[n][r];
        
    }
}