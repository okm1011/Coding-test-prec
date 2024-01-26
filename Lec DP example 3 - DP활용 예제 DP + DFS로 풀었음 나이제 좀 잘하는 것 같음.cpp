#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int dx[] = {1,0};
int dy[] = {0,1};
int n;
vector<vector<int>>map(20,vector<int>(20,0));
vector<vector<int>>dp(20,vector<int>(20,0));

// 와 진짜 dfs 지리게 만들었다 ch 필요없는이유 -> 어차피 오른쪽 , 아래 밖에 안되고 겹치는애가 꼭 있어야함.
void dfs(int x , int y){
    cout << x << " " << y << "\n";
    if(x>n-1 || y>n-1){
        return;
    }else{
        // dp의 값이 0이거나 다음칸의 dp칸의 값이 기존 dp값 + map의 다음칸 값보다 크다면 dp 값갱신 하고 다음칸 호출
        for(int i = 0 ; i<2;i++){
            if((dp[y+dy[i]][x+dx[i]]==0) || (dp[y+dy[i]][x+dx[i]] > dp[y][x]+map[y+dy[i]][x+dx[i]])){
                dp[y+dy[i]][x+dx[i]] = dp[y][x]+map[y+dy[i]][x+dx[i]];
                dfs(x+dx[i] ,y+dy[i] );
            }
            
        }
    }
}
/* 
3 7 2 1 9    
5 8 3 9 2
5 3 1 2 3
5 4 3 2 1
1 7 5 2 4    

3 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/
int main(){
    freopen("input.txt","rt",stdin);
    
    cin >> n;
    // NxN 의 정사각형 map / 2차원 배열 DP문제인 것 같음.

    for(int i = 0 ; i<n;i++){
        for(int j = 0 ; j<n;j++){
            int temp;
            cin >> temp;
            map[i][j] = temp;
            // 다 한번씩 밟는걸로 가정 하고 DP 초기화 시킴
        }
    }
    dp[0][0] = map[0][0];
    dfs(0,0);
    // 시작 좌표 x = 0 , y = 0

    // 방향 벡터 오른쪽 && 밑에.
    // 아 이거 DP + DFS 하고싶은데... 아무리봐도 DFS인데 해볼까
    cout << dp[n-1][n-1];

    return 0;
}