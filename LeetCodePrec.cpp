#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

    freopen("input.txt","rt",stdin);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>bag;
    for(int i = 0 ; i<n;i++){
        int w,v;
        cin >> w >> v;
        bag.push_back(make_pair(w,v));
    }
    vector<int>dp(100001,0);
    //똑같아 가로 물건이고 세로 맥스무게인데 어차피 끝에줄만 쓸거니까 세로 한줄에 계속 덮어씌우는느낌.
    for(int i = 0 ; i<n;i++){
        for(int j = 1 ; j<=k;j++){
            if(j>=bag[i].first){
                dp[j] = max(dp[j],dp[j-bag[i].first]+bag[i].second);
            }
        }
    }
    cout<<dp[k];

    return 0;
}