#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

    freopen("input.txt","rt",stdin);
    int n,m;
    cin >>n >>m;
    // n = 물건 종류 , m = max 무게
    vector<pair<int,int>>data;
    for(int i = 0 ; i<n ;i++){
        int weight , value , q;
        cin >> weight >> value >> q;
        int sum = 0;
        for(int j = 1 ; j<=q ; j*=2){
            sum+=j;
            if(sum > m){
                break;
            }else{
                data.push_back(make_pair(weight*j,value*j));
            }
        }
    }
    // 이러면 원래 배낭문제로 풀수 있음 여러개있는거를 걍 묶음 상품으로 바꿔버리는거지. 근데 이걸 2의 배수로 바꾸면 모든 경우의 수의 조합이 나온다는거임.
    vector<int>dp(m+1,0);
    for(int i = 0 ; i<data.size();i++){
        for(int j = m;j>=data[i].first;j--){
            dp[j] = max(dp[j],dp[j-data[i].first]+data[i].second);
        }
    }
    cout << dp[m];

    return 0;
}