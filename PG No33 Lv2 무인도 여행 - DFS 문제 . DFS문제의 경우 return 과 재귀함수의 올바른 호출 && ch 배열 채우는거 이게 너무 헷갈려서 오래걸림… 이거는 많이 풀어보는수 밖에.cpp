#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<vector<int>>m(101,vector<int>(101,0));
vector<vector<int>>ch(101,vector<int>(101,0));
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int x_size = 0;
int y_size = 0;

bool compare(int a, int b){
    return a<b;
}

int dfs(int x , int y,int cnt){
    //이건 ch 초기화는 필요없겠는데?
    
    bool all_x = true;
    for(int i = 0 ; i<4 ; i++){
        int temp_x = x + dx[i] , temp_y = y + dy[i];
        if(temp_x>=0 && temp_x<x_size && temp_y >= 0 && temp_y<y_size && ch[temp_y][temp_x] == 0){
            //범위 내의 X,Y값
            if(m[temp_y][temp_x] != -1){
                ch[temp_y][temp_x] = 1;
                all_x = false;
                // 이부분 생각해 내는데 오래걸렸음 1 >> DFS 에서 refurn과 재귀함수 호출 이거는 많이 해보는 수밖에..
                cnt = cnt + dfs(temp_x,temp_y,m[temp_y][temp_x]);

            }
        }
    }
    // 이부분 생각해 내는데 오래걸렸음 2
    return cnt;


}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<int> tp;
    for(int i = 0 ; i<maps.size();i++){
        for(int j = 0 ; j<maps[0].size();j++){
            if(maps[i][j] == 'X'){
                m[i][j] = -1;
            }else{
                m[i][j] = maps[i][j] - 48;
                // char to int
            }
        }
    }

    x_size = maps[0].size();
    y_size = maps.size();

    //여기 까지 mapping

    for(int i = 0 ; i<maps.size();i++){
        for(int j = 0 ; j<maps[0].size();j++){  
            if(ch[i][j] == 0 && m[i][j]!=-1){
                ch[i][j] = 1;
                tp.push_back(dfs(j,i,m[i][j]));
            }

        }
    } 
    sort(tp.begin(),tp.end(),compare);
    answer = tp;
    if(answer.empty()){
        answer.push_back(-1);
        return answer;
    }else{
        return answer;
    }
    
}

int main(){
    vector<string> maps = {"X591X","X1X5X","X231X", "1XXX1"};
    vector<int> answer = solution(maps);
    
    for(int i = 0 ; i<answer.size();i++){
        cout << answer[i] << " ";
    }
    return 0;
}