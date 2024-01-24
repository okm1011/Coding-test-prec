#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n;
    cin >> n;

    vector<int>arr(n,0);
    vector<int>dp(n,1); // 전형적인 DP 문제 각 자리수에서 선택한다 치고 , DP 배열 다 1로 초기화
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }
    //이중 포문 && 조건 두가지 arr 하위 스캔하면서 자기보다 작은데 dp는 크거나 같다면 거기부터 하나 더올리면 되니까 dp[i]=dp[j] +1 
    for(int i = 0 ; i < n ; i++){
        
        
        for(int j = i-1 ; j>=0 ; j--){
            if(arr[i]>arr[j]){
                if(dp[i] <= dp[j]){
                    dp[i] = dp[j]+1;
                    
                }
                
            }
             
        }
        
    }
    //내림차순 정렬
    sort(dp.begin(),dp.end(),greater<int>());
    cout << dp[0];
    return 0;
}