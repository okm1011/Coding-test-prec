#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int>st;
    for(int i = 0 ; i<moves.size();i++){
        int temp = moves[i]-1;
        bool flag = false;
        // line이 0부터 시작하니까 1빼주자
        for(int j = 0; j<board.size();j++){
            for(int k = 0;k<board[j].size();k++){
                // j = y , k = x
                if(temp == k && board[j][k]!=0){
                    if(!st.empty()){
                        if(st.top() == board[j][k]){
                            //겹치는 부분 answer 추가후 최상단 pop 
                            answer = answer+2;
                            st.pop();
                            flag = true;
                            board[j][k]=0;
                            break;
                        }else{
                            st.push(board[j][k]);
                            board[j][k]=0;
                            flag = true;
                            break;
                        }
                    }else{
                            st.push(board[j][k]);
                            board[j][k]=0;
                            flag = true;
                            break;
                    }

                }
            }
            if(flag)break;
        }
        
    }
    return answer;
}

int main(){
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    int answer = solution(board,moves);
}