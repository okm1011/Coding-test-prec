#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int n,m;
vector<int>arr;
int ch[10];
int cnt = 0;
int prt[10];

//일단 하나씩 출력하는거 해보기.

void dfs(int x){

    if(x==m){
        for(int i = 0 ; i<m;i++){
            cout<<prt[i];
        }cout << "\n";
        cnt ++;
        return;
    }else{
        
        // x =1 
        // 1 3 6 7
        for(int i = 0 ; i<n;i++){
            if(ch[i]==0){
                prt[x] = arr[i];
                ch[i] = 1;

                
                dfs(x+1);
                
                ch[i] = 0;
            }
        }
    }
} 
int main(){
    freopen("input.txt","rt",stdin);
    cin >> n >> m;
    for(int i = 0 ; i<n;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
        
    }
    
    dfs(0);
    cout << cnt;
    
    return 0;
}