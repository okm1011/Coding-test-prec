#include <iostream>
#include<vector>
using namespace std;

int find_sq(vector<vector<int>> board, int y , int x , int max_y,int max_x, int step){
    if(y+step >= max_y || x+step >= max_x)return step;

    for(int i = y ; i<y+step+1;i++){
        for(int j = x ; j<x+step+1 ; j++){
            if(board[i][j] == 0)return step;
        }
    }
    return find_sq(board,y,x,max_y,max_x,step+1);
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int y = board.size();
    int x = board[0].size();
    if(x==0 || y==0)return 0;
    for(int i = 0 ; i<y;i++){
        for(int j = 0 ; j<x ; j++){
            if(board[i][j] == 1){
                int temp = find_sq(board,i,j,y,x,1);
                if(temp*temp > answer)answer = temp*temp;
            }
        }
    }
    
    return answer;
}