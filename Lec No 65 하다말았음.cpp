
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int cnt = 0;
vector<int>arr[21];
vector<int>ch(21,0);
void dfs(int);

// linked_list 처럼 푼거임 이거 vector n열에 to 숫자 추가해서 링크

int main(){

    freopen("input.txt","rt",stdin);
    cin >> n >> m;
    cout << n << m;
    for(int i = 1;i<=m;i++){
        int from , to;
        cin >> from >> to;
        arr[from].push_back(to);
    }
    ch[1] = 1;
    dfs(1);
    
    //cout << cnt;
    return 0;
}

void dfs(int x){
    cout << x;
    if(x == n){
        cnt++;
    }
    for(int i = 0;i<arr[x].size();i++){
        if(ch[arr[x][i]] == 0){
            ch[arr[x][i]] =1;
            dfs(arr[x][i]);
            ch[arr[x][i]] =0;
        }
    }

}