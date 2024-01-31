#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    //다익스트라 (한정점에서 다른 모든 정점까지의 최소비용)
    //플로이드 와샬 (모든 정점에서 다른 모든 정점까지의 최소비용 DP 필수)

    freopen("input.txt","rt",stdin);
    int n,m; 
    // n 도시 수 m 도로 수

    cin >>n >> m;
    vector<vector<int>>dp(101,vector<int>(101,21470000));
    //dp의 변인 = 거쳐가는 각정점 1 to n [i]
    for(int i = 1; i<=m;i++){
        int a,b,c;
        cin >> a>>b>>c;
        dp[a][b] = c;
        dp[i][i] = 0;
        //여기서 DP초기화 해줘야함 일단 다이렉트의 경우가 나와있으니
        
    }
    /* 
    x to y 까지 가는데 여러 경우가 있을꺼임 예를 들어 (x 1 2 3 y ) (x 3 2 y)
    (x 1 y) 이런 경우를 모두 생각을해봐야하는데 이걸 간단하게 DP로 풀어서 푸는게 포인트
    dp의 변인 = 거쳐가는 각정점 1 to n [i], 간선의 수 [j]. 

    그리고 dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]) 하면 어쨋든 DP 의 k중점을 1~n까지 
    도는 거니까 1번거치는거 1번2번 거치는거 1번...n번 거치는걸 다 고려를 한다고 볼 수 있음
    그러면 순서는 ?? 1,2,3은 생각하겠지만 3,1,2는? -> 이거는 이미 DP[i][k] 나 DP[k][j] 할때
    최소값으로 갱신이 되어있는 상태임 이전에 예를들어 dp[5][4] 계산때 k 가 3이면 
    dp[5][3] + dp[3][4] 인데 각 DP들은 1~n까지 돌면서 최소를 맟춰놓은 애들인거임.
    

    


    */
    for(int k = 1 ; k <=n; k++){
        // k 번째 도시를 경유하는 경우를 계산
        for(int i = 1; i<=n;i++){
        //2차원 배열 dp[i][j] 갱신
            for(int j =1;j<=m;j++){
                dp[i][j] = min(dp[i][j],(dp[i][k]+dp[k][j]));
            }
        }
    }


    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n;j++){
            if(dp[i][j]==21470000){
                cout<<"M";
            }else{
                cout << dp[i][j];
            }
            
        }cout << "\n";
    }





    return 0;
}