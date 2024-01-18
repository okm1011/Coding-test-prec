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
int ch[50];
int res_min = 2147000000;
// lv = 없앨 피자집 갯수
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
    // v를 기준으로 2를 하나씩 지워가면서 모든 지워진 2의 조합에서 cal_dist를 때리는거임.
    if(v>lv){
        int Min = 2147000000;
        int sum = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(map[i][j]==1){
                    sum = sum + cal_dist(j,i,map);
                    
                }
            }
        }
        if(res_min>sum){
            res_min = sum;
        }
        
        return;
    }else{
        
        for(int i =0;i<cd.size();i++){
            if(ch[i]==0){
                map[cd[i].first][cd[i].second] = 0;     // 여기서 2지워주고
                ch[i] = 1;
                dfs(v+1);
                map[cd[i].first][cd[i].second] = 2;     //dfs끝나면 다시 2넣어주고
                ch[i] = 0;
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
                //cd = 2인애들 좌표 저장
            } // 피자집 갯수
            map[i][j] = temp;
        }
    }
    lv = sr - m;
    dfs(1);
    cout << res_min;
    return 0;
}