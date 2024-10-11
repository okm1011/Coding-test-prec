#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dp[1001][1001]; // 최대 보드판의 크기

// 점화식을 구현한 부분
int getRectangleSize(int x, int y){
    return min(min(dp[x-1][y],dp[x][y-1]),dp[x-1][y-1])+1;
}
int solution(vector<vector<int>> board)
{   
    int answer = 0;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            // 해당 좌표가 0이라면 그 좌표를 
            // 오른쪽 아래 꼭짓점으로 하는 정사각형이 만들어질 수 없다.
            if(board[i][j] == 0) dp[i+1][j+1] = 0;
            
            // 점화식을 적용한다.
            else dp[i+1][j+1] = getRectangleSize(i+1,j+1);
            answer = max(answer,dp[i+1][j+1]); // 가장 큰 사이즈가 답
        }
    }
    return answer * answer; // 구해야하는 것은 넓이이기 때문에 길이x길이
}