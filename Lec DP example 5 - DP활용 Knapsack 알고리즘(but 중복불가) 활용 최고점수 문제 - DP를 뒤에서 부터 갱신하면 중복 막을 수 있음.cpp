
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    //와 뒤에서 부터 DP 풀면 당연히 중복 막을수 있지 업데이트가 뒤에서 부터 되니까.. 애초에 dp[j-t]를 참조할텐데 뒤에서 부터하면 중복이안됨..
    //이거 3시간 고민함...
    freopen("input.txt","rt",stdin);
    int n,m;
    cin >> n >>m;
    vector<int>dp(m+1,0);

    for(int i = 1; i<= n ; i++){
        int v,t;
        cin >> v >>t;
        for(int j = m ; j>=t ; j--){
            //dp 반대로 시작 v = 점수 t = 시간
            dp[j] = max(dp[j],dp[j-t]+v);
        }
    }
    cout << dp[m];
    return 0;
}




/*
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

//처음 냅색이랑 동일하게 풀면될 것 같음. DP의 변인은 제한시간 0분부터 m분까지.
//문제 추가될때마다 갱신.
//근데 한문제 푼거를 또풀수가 없다는 차이점.
int main(){
    freopen("input.txt","rt",stdin);
    int n,m;
    cin >> n >>m;
    // n = 문제 수 m= 제한 시간.
    // 중복값이 없어야 하니까 큰 DP에서 작은 DP 참조할때 어떤 문제 풀었는지에 대한 정보가 필요할 것 같은데.
    // v = 점수 t = 시간
    // 중복체크를 2차원 벡터로 할까??? -> 이게 정답인것같음
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    //이거를 dp[0]을 dp 최대값으로 쓰고 dp[1~n] 까지를 중복 체크용으로 쓰는거임.
    // 포인트가 dp[j-t] + v 할때 같은 문제가 두번 더해지는게 문제임..
    
    // dp[i][j] 일때 j가 최대무게 i[0] 이 dp i[1~n] ch배열
    for(int i = 1 ; i<=n; i++){
        int v, t;
        cin >> v >>t;

        for(int j = t ; j <=m ; j++){
            //기본적으로 dp가 갱신되려면 j가 t이상이여야기 때문에 t부터 시작
            if(dp[j][0]<dp[j-t][0]+v && dp[j-t][i] == 0){
                dp[j][0] = dp[j-t][0]+v;
                dp[j][i] = 1;
            }
        }
    }
    cout << dp[m][0];
    // 이것도 값이 안나온다....
    
}



*/

