#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
//이거 저번  DP  문제랑 똑같이 풀면될 거같은데.
// 걍똑같은 거지만 그 이게 똑같다고 아는게 포인트인듯

int main(){
    freopen("input.txt","rt",stdin);
    int n;
    cin >> n;
    vector<int>tg(n+1,0);
    vector<int>dp(n+1,1);
    for(int i = 1; i<=n;i++){
        cin >> tg[i];
        
    }
    for(int i = 2 ; i<=n ; i ++){
        for(int j =i;j>0 ; j--){
            if((tg[i]>tg[j]) &&(dp[i]<=dp[j])){
                dp[i] = dp[j] + 1;
                
            }
        }
    }
    sort(dp.begin(),dp.end(),greater<>());
    cout << dp[0];

    return 0;
}