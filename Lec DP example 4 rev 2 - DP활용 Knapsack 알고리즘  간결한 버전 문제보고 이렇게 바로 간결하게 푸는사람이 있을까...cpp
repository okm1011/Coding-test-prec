//인프런 강의에서 설명한 Ver 2차원 DP 배열을쓰지않고
//어차피 바로 전 DP 배열이 Reference니까 한줄짜리를 계속 갱신해서 풀었음
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n,m ; // n = 물건 종류 수 m = 최대 가방 무게
    cin >> n >> m;

    
    vector<int>dp(m+1,0);
    // dp 1줄 

    // i = 물건 종류 j= 최대 무게
    for(int i = 1 ; i<=n;i++){
        int a,b; // a = 무게 b = 가치
        cin >>a >>b;
        for(int j = a ; j<=m ; j++){
            //어차피 j,최대 무게가 물건의 무게보다 커야지 0이아니기때문에 j=a부터 갱신 시작임.
            //문제의 포인트는 3가지 1.안넣는다 2.넣는다 3.빼고 넣는다 
            //m무게의 가방의 최대는 새로들어간 물건 k 라고 할때 k의 가치 + dp[m-k] 또는 원래 dp[m] 중 최대값
            //걍 한줄이면 끝나버리는 건데 이걸 이해해서 코드로 이렇게 간결하게 짜는게 진짜 힘듦.
            dp[j] = max(dp[j],b+dp[j-a]);
        }
    }
    cout << dp[m];
    return 0;
}