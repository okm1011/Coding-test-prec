#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n,m,v;
    cin >> n >> m;
    vector<int>map[n+1];
    int ch[n+1] = {0};
    int dis[n+1] = {0};
    queue<int> Q;

    for(int i = 0 ; i<m;i++){
        int from , to;
        cin >> from >> to;
        map[from].push_back(to);
    }
    Q.push(1);
    ch[1] = 1;
    
    while(!Q.empty()){
        //cout << Q.size();
        v = Q.front();
        Q.pop();
        for(int i = 0 ; i < map[v].size();i++){
            
            if(ch[map[v][i]]==0){
                
                ch[map[v][i]]=1;
                Q.push(map[v][i]);
                dis[map[v][i]] = dis[v]+1;
            }
        }

    }
    for(int i = 2; i<=n;i++){
        cout << dis[i]<<" ";
    }

    return 0;
}