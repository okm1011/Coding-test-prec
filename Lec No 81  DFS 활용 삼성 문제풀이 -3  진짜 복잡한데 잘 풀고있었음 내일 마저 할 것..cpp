#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
vector<vector<int>>map(13,vector<int>(13,0));
vector<vector<int>>dist(13,vector<int>(13,0));
vector<pair<int,int>>cd;

int n,m;
int sr = 0;
int lv = 0;

//n-m = 없앨 피자집 갯수
// second = x= j // first = y = i

//cal_dist = x,y 좌표에 들어간 1기준으로 최소 피자 배달거리 return.
int cal_dist(int x,int y,vector<vector<int>>temp){
    int Min = 2147000000;
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=n;j++){
            if(temp[i][j] == 2){
                int temp = abs(x-j) + abs(y-i);
                if(temp<Min){
                    Min = temp;
                }
            }
        }
    }
    
    return Min;
}

void dfs(int v){
    if(v>lv){
        return;
    }else{
        vector<vector<int>>temp(13,vector<int>(13,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1; j<=n;j++){
                temp[i][j] = map[i][j];
            }
        }// 여기서 cd에 있는애들 dfs로 순차적으로 0으로 만들어줘야할듯
        
        // 최소거리 계산 , map or temp가지고 dist채워야함.
        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=n;j++){
                if(temp[i][j]==1){
                    int res = cal_dist(j,i,temp);
                }
            }
        }   

    }    
 
    
}

int main(){
    freopen("input.txt","rt",stdin);
    cin>>n>>m;
    
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=n;j++){
            int temp;
            cin >> temp;
            if(temp == 2){
                sr++;
                cd.push_back(make_pair(i,j));
            } // 피자집 갯수
            map[i][j] = temp;
        }
    }
    lv = sr - m;
    //dfs(1);

    return 0;
}