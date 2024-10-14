#include <string>
#include <vector>
#include <stack>

using namespace std;
vector<vector<int>>min_answer;

void dfs(vector<stack<int>>towers,vector<vector<int>>steps,int n ){
    if(towers[0].size() == n){
        if(steps.size()>min_answer.size())min_answer = steps;
    }
    for(int i = 0 ; i<3;i++){
        if(!towers[i].empty()){
            int right = i+1;
            int left = i-1;
            if(right > 2) right = 0;
            if(left<0) left = 2;
            if(towers[right].empty() || towers[right].top()>towers[i].top() ){
                int top = towers[i].top();
                towers[i].pop();
                towers[right].push(top);
                steps.push_back({i,right});
                dfs(towers,steps,n);
            }
            if( towers[left].empty() || towers[left].top()>towers[i].top()){
                int top = towers[i].top();
                towers[i].pop();
                towers[left].push(top);
                steps.push_back({i,left});
                dfs(towers,steps,n);                
            }
            
        }
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    // 음............... 그냥 중복 가능 모든 경우의수 다 때려박으면 될 듯.
    vector<vector<int>> temp;
    vector<stack<int>>towers;
    stack<int>tower1;
    for(int i = n ; i >= 1 ; i--){
        tower1.push(i);
    }
    stack<int>tower2;
    stack<int>tower3;
    towers.push_back(tower1);
    towers.push_back(tower2);
    towers.push_back(tower3);
    dfs(towers,temp,n);
    answer = min_answer;
    return answer;
}
int main(){
    int n = 2;
    vector<vector<int>>answer =solution(n);



}