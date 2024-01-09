#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(int);
vector<pair<int,int>>f;
vector<int>f_res;
int ch[1000];
int n,m;
int result;
bool flag = 0;

int main(){

    freopen("input.txt","rt",stdin);

    cin >> n>>m;
    
    //양방향이네... ?...?
    for(int i = 0; i<m;i++){
        int a,b;
        cin >> a>>b;
        f.push_back(make_pair(a,b));
    }
    int x;
    cin >> x >> result;
    
    dfs(x);
    for(int i = 0 ; i<f_res.size();i++){
       if(f_res[i] == result){
            flag = 1;
       }
    }
    if(flag){
        cout << "YES";
    }else{
        cout<<"No";
    }
    return 0;
}
void dfs(int x){
    
    if(ch[x]==1){
        return;
    }
    cout<< " x: "<<x<<" \n ";
    for(int i = 0 ; i<f.size();i++){
        
        if(f[i].first == x ){
            //cout << " first : " << f[i].first << " second: " << f[i].second << " i: "<<i<<" x: "<<x<<" \n ";
            f_res.push_back(f[i].second);
            ch[x] = 1;
            dfs(f[i].second);
        }else if(f[i].second == x){
            //cout << " first : " << f[i].first << " second: " << f[i].second << " i: "<<i<<" x: "<<x<<" \n ";
            f_res.push_back(f[i].first);
            ch[x] = 1;
            dfs(f[i].first);
        }else{

        }
    }


}