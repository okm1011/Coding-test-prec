#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    freopen("input.txt","rt",stdin);
    int n , k;
    cin >> n >> k;
    vector<pair<int,int>>data;
    for(int i = 0 ; i < n ; i++){
        int weight , value;
        cin >> weight >>value;
        data.push_back(make_pair(weight,value));
    }
    vector<vector<int>>dp(k+1,vector<int>(n,0));
    //dp니까 첫줄은 채워줘야함
    for(int i = 1 ; i<=k ; i++){
        if(i>=data[0].first){
            dp[i][0] = data[0].second;
        }
    }
    for(int j = 1 ; j<n ; j++){
        for(int i = 1 ; i <= k ; i++){
            if(i >= data[j].first){
                dp[i][j] = max(dp[i][j-1] , dp[i-data[j].first][j-1]+data[j].second);
            }else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout << dp[k][n-1];

    return 0;
}