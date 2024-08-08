#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 걍 각각 검사해야하나?
        int size = 9;

        for(int i = 0 ; i < size ; i++){
            vector<int>ch(size+1,0);
            for(int j = 0 ; j<size ; j++){
                if(board[i][j] != '.'){
                    if(ch[board[i][j]-'0'] != 0){
                        return false;
                    }else{
                        ch[board[i][j]-'0'] = 1;
                    }
                }
            }
        }
        // 여기까지가 가로
        for(int i = 0 ; i < size ; i++){
            vector<int>ch(size+1,0);

            for(int j = 0 ; j<size ; j++){
                if(board[j][i] != '.'){
                    if(ch[board[j][i]-'0'] != 0){
                        return false;
                    }else{
                        ch[board[j][i]-'0'] = 1;
                    }
                }
            }
        }
        //여기까지 세로
        pair<int,int>ptr = {0,0};
        while(1){
            if(ptr.first > size -1 || ptr.second > size -1)break;
            cout << "ptr f : " << ptr.first << "prt sec: " << ptr.second << "\n";
            vector<int>ch(size+1,0);
            for(int i = ptr.second ; i<ptr.second + 3 ; i++){
                
                
                for(int j = ptr.first ; j<ptr.first + 3 ; j++){
                    if(board[i][j] != '.'){
                        if(ch[board[i][j]-'0'] != 0){
                            return false;
                        }else{
                            ch[board[i][j]-'0'] = 1;
                        }
                    }                    
                }
            }
            
            if(ptr.first+3 >= size){
                ptr.second+=3;
                ptr.first = 0;
            }else{
                ptr.first+=3;
            }
            
        }
        return true;
        
    }
};
int main(){
    vector<vector<char>>input = {
    {'.', '.', '.', '.', '.', '.', '5', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'9', '3', '.', '.', '2', '.', '4', '.', '.'},
    {'.', '.', '7', '.', '.', '.', '3', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '3', '4', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '3', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '5', '2', '.', '.'}
    };
    Solution s;
    bool answer = s.isValidSudoku(input);
    cout <<answer;
    return 0;
}