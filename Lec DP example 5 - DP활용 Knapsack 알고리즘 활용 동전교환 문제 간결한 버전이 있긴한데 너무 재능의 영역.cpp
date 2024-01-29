#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n ;
    cin >> n;
    // 이것도 Knapsack처럼 1원 거슬러줄때 ...  n원 거슬러줄때로 생각을 해봐야할 것 같은데.
    vector<int>dp(501,0);
    vector<int>coin(n+1,0);
    for(int i = 1;i<=n;i++){
        cin >> coin[i];
    }
    int m ; 
    int x,y ; // x 는 몫 , y는 나머지
    cin >> m;
    for(int i = 1; i<=m ; i++){
        x = i/coin[1];
        y = i%coin[1];
        if(y==0){
            //나누어떨어질때.
            dp[i]=x;
        }else{
            //나누어 떨어지지 않을때.
            dp[i] = 2147000000;
        }
        // DP 초기화 with 첫번째 코인 
    }
    //이게 Min 값을 찾는거다보니까 첫번째 코인에서 DP 초기화를 해놓고
    //거슬러 줄 수 있으면 min(dp[j],x+dp[y]) 하는거고
    //거슬러 줄 수가 없으면 어차피 MAX 값이 들어가기 때문에 다음동전으로 다시 dp갱신
    for(int i = 2; i<=n;i++){
        for(int j = 1; j<=m;j++){
            
            x = j/coin[i];
            y = j%coin[i];
            dp[j] = min(dp[j],x+dp[y]);
            //cout << " j: " << j << " dp[j]: " << dp[j] <<" x: "<<x<<" y: "<<y<< "\n";
        }
    }
    cout << dp[m];

    return 0;
}