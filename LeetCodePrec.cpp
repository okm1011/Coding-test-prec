#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){

    freopen("input.txt","rt",stdin);
    int n,m;
    cin >>n >>m;
    // n = 물건 종류 , m = max 무게
    vector<pair<int,int>>data;
    data.push_back(make_pair(0,0));
    int w, c, k;
    for(int i=0; i<n ; ++i){
        cin>>w>>c>>k;

        //물건을 제곱 수로 나누어주자
        for(int i=k; i>0 ; i >>=1){
        int part = i -(i>>1);
        data.push_back({w*part, c*part});
        }
    }
    // 이러면 원래 배낭문제로 풀수 있음 여러개있는거를 걍 묶음 상품으로 바꿔버리는거지. 근데 이걸 2의 배수로 바꾸면 모든 경우의 수의 조합이 나온다는거임...
    vector<vector<int>>dp(m+1,vector<int>(data.size(),0));
    // for(int i = 0 ; i<n ;i++){
    //     int weight , value , q;
    //     cin >> weight >> value >> q;
    //     if(q>1){
    //         int sum = 0;
    //         for(int i = 1 ; i<=q; i*=2){
    //             sum+=i;
    //             if(sum > m){
    //                 break;
    //             }else{
    //                 int new_weight = weight * (i);
    //                 int new_value = value * (i);
    //                 data.push_back(make_pair(new_weight,new_value));
    //             }
    //         }
    //     }else{
    //         data.push_back(make_pair(weight,value));
    //     }
    // }    

    for(int j = 1 ; j<data.size();j++){
        for(int i = 1 ; i<=m ; i++){
            if(i>=data[j].first){
                dp[i][j] = max(dp[i][j-1],dp[i-data[j].first][j-1]+data[j].second);
            }else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout << dp[m][data.size()-1];

    return 0;
}