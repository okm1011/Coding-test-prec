#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

class Pt{
public:
    int x;
    int y;
    int cnt;
    Pt(int a, int b ,int c){
        x = a;
        y = b;
        cnt = c;
    }

};



int solution(vector<string> board) {
    
    int answer = 0;
    vector<vector<int>>map(101,vector<int>(101,-1));
    vector<vector<int>>ch(101,vector<int>(101,0)); // 중복 체크용 ch
    int s_x = 0 , s_y = 0;
    
    queue<Pt>q; // 진짜 바보인가 bfs는 큐쓰는 거였던걸 기억을 못해서 삽질 3시간했음... dfs가 재귀함수고

    // map 초기화 -1은 갈 수 없는 곳
    for(int i = 1 ; i<= board.size() ; i++){
        int i_b = i-1;
        for(int j = 1 ; j<=board[0].size() ; j++){
            int j_b = j-1;
            if(board[i_b][j_b]=='.'){
                map[i][j] = 0;
            }else if(board[i_b][j_b]=='D'){
                map[i][j] = 1;
            }else if(board[i_b][j_b]=='R'){
                map[i][j] = 0;
                s_x = j;
                s_y = i;
            }else if(board[i_b][j_b]=='G'){
                map[i][j] = 2;
                // goal in 지점
            }
        }
    }
    q.push(Pt(s_x,s_y,1));
    ch[s_y][s_x] = 1;
    //처음꺼 check

/*
-1-1-1-1-1-1-1-1
-1000100R
-10102000
-10000101
-11000010           
-10010000
*/  
    while(!q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        //정보 받아서 pop

        for(int i = 0 ; i<4;i++){
            int t_x = x;
            int t_y = y;
            int t_cnt = cnt;

            while(1){
                t_x += dx[i];
                t_y += dy[i];
                if(map[t_y][t_x] == -1 || map[t_y][t_x] == 1){
                    t_x -= dx[i];
                    t_y -= dy[i];
                    break;
                }
                // 상하좌우 이동
            }
            if(map[t_y][t_x] == 2){
                // 이동했는데 맞으면 끝.
                return cnt;
            }
            if(ch[t_y][t_x]!=1){
                ch[t_y][t_x]=1;
                
                q.push(Pt(t_x,t_y,t_cnt+1));
            }
        }

    }

    
    // q다써서 튀어 나온거면 -1반환
    return -1;
}

int main(){
    vector<string>board = {".D.R", "....", ".G..", "...D"};
    int answer = solution(board);
    cout<<answer;
    return 0;
}