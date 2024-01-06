#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;

int res = 2147000;

vector<vector<int>>map(21,vector<int>(21,0));
vector<vector<int>>dp(21,vector<int>(21,0));
vector<int>ch(21,0);

void dfs(int,int);

// dfs 로 한번 dp로 한번 풀어보자

int main(){
    freopen("input.txt","rt",stdin);
    cin >> n >> m;
    int from,to,value;

    for(int i = 0;i<m;i++){
        cin >> from >> to >> value;
        map[from][to]=value;
    }
    /*
    for(int i = 1; i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<map[i][j]<<" ";  
        }
        cout<<'\n';
    }
    */
    ch[1]=1;
    dfs(1,0);
    //cout << res;
    return 0;
} 

void dfs(int v,int sum){
    cout << sum << " ";
    if(v==n){
        
        if(res>sum){
            res = sum;
            
        }
    }
    for(int i =1;i<=n;i++){
        if(map[v][i]!=0&&ch[i]==0){
            
            ch[i]=1;
            dfs(i,sum+map[v][i]);
            ch[i]=0;
        }
    }
    
}