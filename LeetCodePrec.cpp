#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
long long target = 0;
vector<int>dfs_answer;
bool flag = false;
void dfs(vector<int>ch ,stack<int>temp, int turns,int n,int k){
    
    if(flag) return;
    if(temp.size() == n){
        target++;
        if(target == k){
            flag = true;
            while(!temp.empty()){

                dfs_answer.push_back(temp.top());
                temp.pop();
            }
        }
        return;
    }
    for(int i = 1; i<ch.size();i++){
        if(ch[i] == 0){
            ch[i] = 1;
            temp.push(i);
            dfs(ch,temp,turns+1,n,k);
            ch[i] = 0;
            temp.pop();
        }
    }
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> ch(n+1,0);
    stack<int> temp;
    dfs(ch,temp,0,n,k);
    for(int i = dfs_answer.size()-1;i>=0 ;i--){
        answer.push_back(dfs_answer[i]);
    }
    return answer;
}