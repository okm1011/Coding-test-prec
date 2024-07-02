#include<string>
#include<vector>
#include<iostream>

using namespace std;
vector<vector<int>> map;
// max 던전 갯수 8
vector<int>ch(8,0);
int Max_return = -1;

void dfs(int k , int cnt , int size){
    for(int i = 0 ; i<size ; i++){
        if(ch[i] == 0){
            
            if(map[i][0] <= k){
                ch[i] = 1;
                dfs(k-map[i][1] , cnt+1 , size);
                ch[i] = 0;
            }
        }
    }
    if(cnt > Max_return){
        Max_return = cnt;
        return;
    }else{
        return;
    }
}

int solution(int k, vector<vector<int>> dungeons){
    
    map = dungeons;
    dfs(k,0,dungeons.size());
    
    return Max_return;
}

int main(){
    int k = 80;
    vector<vector<int>> dungeons = {{80,20},{50,40},{30,10}};

    int answer = solution(k,dungeons);
    cout << answer;


    return 0;
}