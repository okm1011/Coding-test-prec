#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n;
    int cnt = 0;
    int dx[] = {1,1,0,-1,-1,-1,0,1};
    int dy[] = {0,1,1,1,0,-1,-1,-1};
    cin >> n;
    vector<vector<int>>map(n+2,vector<int>(n+2,0));
    vector<vector<int>>ch(n+2,vector<int>(n+2,0));
    for(int i = 1; i<=n;i++){
        for(int j = 1;j<=n;j++){
            int temp;
            cin >> temp;
            map[i][j] = temp;
        }
    }
    //끝에서 끝까지 스캔 하다가 1나오면 상하좌우 대각선 돌리고 끝나면 cnt ++ && ch 갱신 
    //다시 스캔
    queue<pair<int,int>>q;
    for(int i = 1; i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(map[i][j]==1 && ch[i][j]==0){
                cnt++;
                ch[i][j] = 1;
                q.push(make_pair(i,j)); // i , j 좌표 큐에 넣고
                while(!q.empty()){
                    int t_i = q.front().first;
                    int t_j = q.front().second;
                    q.pop();
                    for(int i = 0 ; i <8;i++){
                        int t_i2 = t_i + dy[i];
                        int t_j2 = t_j + dx[i];
                        //cout<< " new t_i: " << t_i2 << " new t_j: "<<t_j2<<"\n";
                        if((0<t_i2<n+1)&&(0<t_j2<n+1)&&(map[t_i2][t_j2]==1)&&(ch[t_i2][t_j2] == 0)){
                            ch[t_i2][t_j2] = 1;
                            q.push(make_pair(t_i2,t_j2));
                        }
                    }
                }
            }
        }
    }
    cout << cnt;   

    return 0;
}