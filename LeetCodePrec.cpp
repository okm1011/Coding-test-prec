#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
int max_cost = 0;
vector<int>conf;
void dfs(vector<vector<int>>road , vector<int>ch , int current,int cost){
    if(conf[current] == 0 && cost<=max_cost){
        conf[current] = 1;
        //cout << "cureent: " << current << "cost : "<<cost <<"\n";
        cnt++;

    }else if(cost>max_cost){
        return;
    }
    
    for(int i = 0; i<road.size();i++){
        if(road[i][0] == current){
            if(ch[road[i][1]] == 0){
                ch[road[i][1]] = 1;
                dfs(road,ch,road[i][1],cost+road[i][2]);
                ch[road[i][1]] = 0;
            }
        }else if(road[i][1] == current){
            if(ch[road[i][0]] == 0){
                ch[road[i][0]] = 1;
                dfs(road,ch,road[i][0],cost+road[i][2]);
                ch[road[i][0]] = 0;
            }
        }
    }
    return;
    
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    conf.resize(N+1,0);
    conf[1] = 1;
    max_cost = K;
    vector<int>ch(N+1,0);
    dfs(road,ch,1,0);
    
    
    // 무조껀 1번마을 출발인거임.
    // 그리고 양방향인점.
    answer = cnt+1;
    

    return answer;
}