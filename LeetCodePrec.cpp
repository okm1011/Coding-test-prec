#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<int>stat;
        
        int dx[] = {1,-1,0,0,-1,1,1,-1};
        int dy[] = {0,0,1,-1,1,-1,1,-1};
        for(int i = 0; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                int cnt = 0;
                for(int k = 0 ; k<8;k++){
                    int n_i = i+dy[k];
                    int n_j = j+dx[k];
                    if(n_i>=0 && n_i < n && n_j >= 0 && n_j<m){
                        if(board[n_i][n_j]==1)cnt++;
                    }
                }
                stat.push_back(cnt);
            }
        }
        int index = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(board[i][j] == 0){
                    if(stat[index] == 3)board[i][j] = 1;
                }else{
                    if(stat[index] <2 || stat[index]>3)board[i][j] = 0;
                }
                index++;
            }
        }        
    }
};

int main(){
    vector<vector<int>>input = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution s;
    s.gameOfLife(input);

    return 0;
}