#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>>map[21];
vector<int>ch(21,0);
int n,m;
int res = 2147000000;

void dfs(int , int);


int main(){
    
    freopen("input.txt","rt",stdin);
    cin>>n>>m;

    for(int i = 0;i<m;i++){
        int from,to,value;
        cin >> from >> to >> value;
        map[from].push_back(make_pair(to,value));

    }

    
    ch[1] = 1;
    dfs(1,0);
    cout << res;


    return 0;
}
void dfs(int v,int sum){
    
    if(v == n){
        if(sum<res){
            res = sum; 
        }
    }
    else{
        
        for(int i = 0;i<map[v].size();i++){
            
            if(ch[map[v][i].first]==0 ){
                
                ch[map[v][i].first] = 1;
                dfs(map[v][i].first,sum+map[v][i].second);
                ch[map[v][i].first] = 0;
            }
        }
    }
}




