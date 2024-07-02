#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n,m;
    cin >> n >> m;
    // n = 전체 일의 수 , m = 일 순서 정보.
    
    priority_queue<int,vector<int>,greater<int>>q[n+1];
    // 큐 배열을 놓고 to의 큐에 from을 넣으면 되지. 오름차순 정렬 priority q
    int Max = 0;
    for(int i = 1; i <= m ; i++){
        int from , to;
        cin >> from >> to;
        q[to].push(from);
        if(q[to].size() > Max){
            
            Max = q[to].size(); 
            // for문 돌리기위한 Max치 갱신.
        }
    }
    vector<int>ch(n+1,0);
    
    for(int i=0;i<=n-1;i++){
        for(int k = 1; k<=n;k++){
            if(q[k].empty()&&ch[k]==0){
                ch[k] = 1;
                cout << k<<" ";
            }
        }
        for(int j = 1; j<=n;j++){
            while(!q[j].empty()){

                    if(ch[q[j].top()]==1){
                        q[j].pop();
                    }else{
                        break;
                    }
                }
            }

        }

    
    




    return 0;
}