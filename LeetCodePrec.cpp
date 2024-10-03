#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dfs(string name, int current , int cnt){
    if(cnt >= name.size()-1)return 3;

    if(name[current+cnt] != 'A' && name[name.size()-1-(cnt-1)] == 'A'){
        return 1;
    }else if(name[name.size()-1-(cnt-1)] != 'A' && name[current+cnt] == 'A' ){
        return 2;
    }else{
        return  dfs(name,current,cnt+1);
    }
}
int solution(string name) {
    int answer = 0;
    int all_cnt = 0;
    for(int i = 0 ; i<name.size();i++){
        if(name[i] !='A')all_cnt+=min((name[i]-'A'),('Z'-name[i]+1));
    }
    answer+=all_cnt;
    int index = 0;
    int direc = 0;
    int move_cnt = 0;
    while(all_cnt != 0){
        if(index == -1)index = name.size()-1;
        if(name[index] != 'A'){
            all_cnt-=min((name[index]-'A'),('Z'-name[index]+1));
            if(all_cnt == 0)break;
            direc = dfs(name,0,1);
            cout << "index: " << index << "direc: "<<direc <<"\n";
            if(direc == 1){
                index++;
                move_cnt++;
            }else if(direc == 2){
                index--;
                move_cnt++;
            }else{
                index++;
                move_cnt++;
            }       
        }else{
            if(direc == 1){
                index++;
                move_cnt++;
            }else if(direc == 2){
                index--;
                move_cnt++;
            }else{
                index++;
                move_cnt++;
            }            
        }
        
        // 1일때 직진 2일때 후진 3일때 노상관
    }
    answer += move_cnt;
    return answer;
}

int main(){

    string name = "BBBBAAAABA";
    int res = solution(name);
    cout << res;
    return 0;
}