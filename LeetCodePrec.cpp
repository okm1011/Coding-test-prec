#include <iostream>
#include<vector>
using namespace std;
int cnt_same(vector<int>same){
    int temp = 0 ;
    int max = 0;
    for(int i = 0 ; i < same.size(); i++){
        if(same[i] == 1){
            temp++;
            if(temp>max) max = temp;
        }else{
            temp = 0;
        }
    }
    return max;
}
int solution(vector<vector<int>> board)
{
    int answer = 1;
    int y = board.size();
    int x = board[0].size();
    if(x == 0 || y == 0)return 0;
    vector<int>same (x,0);
    for(int i = 0 ; i < x ; i++){
        same[i] = board[0][i];
    }
    for(int i = 1 ; i<y;i++){
        int h = i+1;

        for(int j = 0 ; j<x ; j++){            
            if(same[j] == 1 && board[i][j] == 1){
                same[j] = 1;
            } 
            else{
                same[j] = 0;
            } 
        }
        int cnt = cnt_same(same);
        int temp_answer = 0;
        if(cnt >= h) temp_answer = h*h;
        if(temp_answer>answer)answer = temp_answer;

    }
    
    return answer;
}