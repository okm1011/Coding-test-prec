#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class St{
public:
    int s;
    int h;
    int w;
    St(int a, int b, int c){
        s = a;
        h = b;
        w = c;
    }
    bool operator<(const St&b)const{
        return s>b.s;
    }
};

int main(){
    freopen("input.txt","rt",stdin);
    //위로 갈수록 밑면이 좁아지고 , 무게가 가벼워지는 탑
    //밑면 넓이 , 벽돌 높이 , 무게 순으로 주어짐 이것도 DP로 풀면될 듯함. 단 인자가 3개라서 Class 해야할듯
    //아 순서대로 꼽아서 하는게 아니고 걍 다 주어진 벽돌을 가지고 내가 골라서 쌓으면 되는거임..
    //그러면 일단 Class 에서 sort해서 넓이 순으로 정렬해놓고, 무게만 보고 DP 돌리면 됨.
    int n;
    cin >> n;
    vector<St>map;
    vector<int>dp;

    for(int i = 0 ; i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        map.push_back(St(a,b,c));
    }
    sort(map.begin(),map.end());
    for(int i = 0;i<n;i++){
        dp.push_back(map[i].h);
    }

    for(int i = 1 ; i<n ; i++){
        int temp = dp[i];
        for(int j = i-1;j>=0;j--){
            if((map[i].w<map[j].w)){
                if((temp + dp[j]) > dp[i] ){
                    dp[i] = temp + dp[j];
                }
            }
        }
        
    }
    sort(dp.begin(),dp.end(),greater<>());
    cout << dp[0];
    return 0;
}