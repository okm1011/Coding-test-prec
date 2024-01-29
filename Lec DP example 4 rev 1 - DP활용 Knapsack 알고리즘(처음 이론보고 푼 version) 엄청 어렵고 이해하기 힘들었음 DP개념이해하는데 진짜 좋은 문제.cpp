// 이걸 그리디로 풀려면 경우의 수가 너무 많아짐 넣음 안넣음을 각각 물건마다 나눠서 거기에 또 각각물건들 경우 찾아봐야하니까 2의 n승개의 시간복잡도가 필요
// DP문제가 가능하려면 큰문제를 작은문제로 쪼갤수 있냐 없냐인데
// 만약 배낭이 6kg 고 내가 3kg짜리 넣는다고 생각하면 (6-3)3kg짜리 배낭의 최대가치 + 3kg를 하면되니까
// 이건 DP 문제가 맞다. 다만 어떤 구조로 해갈지를 생각하는게 중요한데 이사람들 머리 개좋네
// 세부적으로 들어가면 총 3가지 경우
// 1넣는다 2안넣는다 3다른거 빼고 넣는다

// 풀이법 - DP의 기준을 물건의 종류 , 가방의 최대 무게로 놓고 풀면된다고 함 일단 해보자.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n,m; // n = 물건 종류 , m = 가방 최대무게
    cin >> n >>m;

    vector<pair<int,int>>arr(30,make_pair(0,0));
    for(int i = 1; i<=n;i++){
        int a,b;
        cin >> a >> b;
        // a = 무게  b = 가치
        arr[i] = make_pair(a,b);
    }

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //dp의 초기값을 잡아줘야 하니까 가방 최대무게 0인것 부터 시작하자.
    
    // i = 물건종류 , j = 가방 최대 무게 로 보면될듯
    for(int i = 1 ; i<=n;i++){
        for(int j = 0 ; j<=m ; j++){
            // 무게를 늘려가면서 i-1쪽이랑 최대값 비교하면서 dp를 갱신하는거임
            if(j<arr[i].first){
                //안들어 가면 무조건 그 전에께 크겠지. max(전에꺼 , 0) 인거니까
                dp[i][j] = dp[i-1][j];
            }else{
                //j>=arr[i].first
                
                dp[i][j] = max(dp[i-1][j],(arr[i].second+dp[i][j-arr[i].first]));


            }
            
        }
    }
    
    for(int i = 1 ; i<=n;i++){
        for(int j = 0 ; j<=m ; j++){
            cout<<dp[i][j];
        }cout<<"\n";
    }
    /*
    0000012121212122424
    0008812161620242428
    0008812161620242428
    0008812161620242428
    */
    return 0;
}