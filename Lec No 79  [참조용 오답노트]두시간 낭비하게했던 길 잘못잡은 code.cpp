#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
int ch[15];
vector<pair<int,int>>map;
int Max = -2147000000;

// 
void dfs(int v,int sum){
    //cout << " v: " << v << " sum: " << sum <<"\n";
    if(v>n){
        return;
    }
    for(int i = 0;i<n;i++){
        cout << " v: " << v << " sum: " << sum <<" CH[I]: "<<ch <<"\n";
        if(ch[i]==0){
            ch[i] = 1;
            sum = sum + map[i].second;
            v = v + map[i].first;
		// 여기 이부분 for문에서 sum 이랑 v에 더해버리면 어떡해 dfs의 변수에 더해서 넘겨야지 dfs(a+b,c+d) 안그럼 for문에서 계속 더해짐
            if(v<=n && sum > Max){
                Max = sum;
            }
            //cout << " v: " << v << " sum: " << sum <<"\n";
            dfs(v,sum);
            ch[i] = 0;
        }
        
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    
    cin >> n;

    
    for(int i = 0 ; i<n;i++){
        int a,b;
        cin >> a >> b;
        map.push_back(make_pair(a,b));
    }
    dfs(0,0);
    cout << Max;
    // level을 n으로 두고 for문으로dfs 때리면 될 듯한데
    

    return 0;
}