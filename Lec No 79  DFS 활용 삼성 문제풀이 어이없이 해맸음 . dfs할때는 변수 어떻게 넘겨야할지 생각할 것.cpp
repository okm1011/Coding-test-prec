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
    cout << " v: " << v << " sum: " << sum  <<" Max: " <<Max<<"\n";
    if(v>n){
        return;
    }else{
        if(sum > Max){
            Max = sum;
        }
    }
    for(int i = 0;i<n;i++){
        //cout << " v: " << v << " sum: " << sum <<" i: " << i<<" CH[I]: "<<ch[i] <<" Max: " <<Max<<"\n";
        if(ch[i]==0){
            
            ch[i] = 1;
            //cout << " v: " << v << " sum: " << sum <<"\n";
            dfs(v + map[i].first,sum+map[i].second);
            // 와 여기서 더해서 위에같이 dfs로 넘겼어야 하는데 그전에 그앞단에서 v + map[i].first,sum+map[i].second 이지랄해서
            //두시간 해맸다 . 아무리 dfs가 return이 되어도 저렇게 넘기는게 아닌 for문 내부에서 더해버리면 계속 더해져서 망함.
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
    dfs(1,0);
    cout << Max;
    // level을 n으로 두고 for문으로dfs 때리면 될 듯한데
    

    return 0;
}