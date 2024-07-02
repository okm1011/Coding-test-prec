#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dx[] = {1,0,-1,0,1,-1,1,-1};
int dy[] = {0,1,0,-1,-1,-1,1,1};
// 상하좌우 대각선 방향 벡터
int solution(vector<vector<int>> board) {
    int answer = 0;
    for(int i = 0 ; i < board.size();i++){
        for(int j = 0 ; j < board[i].size(); j++){
            if(board[i][j] == 1){
                for(int k = 0; k<8 ; k++){
                    int t_x = j+dx[k] , t_y = i+dy[k];
                    if(t_x>=0 && t_x<board[i].size() && t_y>=0 && t_y<board.size()){
                        if(board[t_y][t_x] == 0)board[t_y][t_x] = -1;
                        // 이렇게 해줘야 기존 1을 살릴 수 있음.
                    }
                }
            }
        }
    }
    for(int i = 0 ; i < board.size();i++){
        for(int j = 0 ; j < board[i].size(); j++){
            if(board[i][j] == 0){
                answer++;
            }
        }
    }    
    return answer;
}
int main(){
    vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}};
    int res = solution(board);
    cout << res;

    return 0;
}