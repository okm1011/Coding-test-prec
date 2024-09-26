#include <iostream>
#include <vector>
using namespace std;
bool sucess =false;
int max_cost = 0;
void dfs(vector<vector<int>>road , vector<int>ch , int current, int goal,int cost){
    if(cost>max_cost)return;
    if(current == goal){
        sucess = true;
        return;
    }
    for(int i = 0; i<road.size();i++){
        if(ch[i] == 0 && road[i][0] == current){
            ch[i] = 1;
            dfs(road,ch,road[i][1],goal,cost+road[i][2]);
            ch[i] = 0;
        }
        if(ch[i] == 0 && road[i][1] == current){
            ch[i] = 1;
            dfs(road,ch,road[i][0],goal,cost+road[i][2]);
            ch[i] = 0;
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    max_cost = K;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // dfs + back tracking으로 풀 수 있지않을까
    // 1에서 시작하는거로 출발해서 
    for(int i = 1 ; i<=N ; i++){
        vector<int>ch(road.size(),0);
        dfs(road,ch,1,i,0);
        if(sucess){
            answer++;
            sucess = false;
        }
    }   
    return answer;
}