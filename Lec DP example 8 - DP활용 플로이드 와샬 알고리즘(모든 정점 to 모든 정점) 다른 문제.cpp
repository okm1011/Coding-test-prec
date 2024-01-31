#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n ;
    // n = 회원수
    cin >> n;
    /*
    플로이드 - 와샬 응용인데 이거는 양방향이라는점. 가중치 1고정이라는점
    음 ... dp 테이블로 12345 해서 1번이랑 1번 1번이랑 2번 요거를 경유점 k로 갱신한다?.
                      12345
                      .....                
    */
    int x,y;
    // x = from y = to
    vector<vector<int>>dp(n+1,vector<int>(n+1,2147000));
    while(1){
        cin >> x >> y;
        if(x==-1&&y==-1){
            break;
        }
        dp[x][y] = 1;
        dp[y][x] = 1;
    }
    for(int i = 1;i<=n;i++){
        dp[i][i] = 0;
    }
    // 여기 까지 DP 초기화
    //01MMM
    //1011M
    //M1011
    //M1101
    //MM110
    /*
    여기서 포인트는 이거임 DP 초기화 이후에 경유점 k를 두고 i에서 k 갈수 있고 k에서 j 갈수있다면
    두개 dp더한거 vs 기존dp값 비교해서 작은걸 넣어 주는거임'
    와 근데 이걸 플로이드 와샬을 써야한다는 힌트없이 풀수가있나
    */
    for(int k = 1; k<=n ; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
            }
        }
    }
    for(int i = 1; i<=n;i++){
        for(int j =1; j<=n ; j++){
            if(dp[i][j]==2147000){
                cout << "M" <<" ";
            }else{
                cout << dp[i][j] <<" ";
            }
            
        }cout << "\n";
    }
    return 0;
}