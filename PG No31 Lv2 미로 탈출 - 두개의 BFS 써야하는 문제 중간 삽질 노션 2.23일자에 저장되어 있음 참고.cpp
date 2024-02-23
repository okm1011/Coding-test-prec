#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

class Cor{
public:
    int x;
    int y;
    int cnt;
    Cor(int a, int b, int c){
        x=a;
        y=b;
        cnt=c;
    }
    
};


// 음... 중복 확인이 없으면 함수자체가 종료가 안될거같은데 레버 까지 한번 도착까지 한번 두번해서 중복 금지를 한다면??
// 그러면 중복으로 갈필요가 없잖아  
int solution(vector<string> maps) {
    int answer = 0;
    vector<vector<int>>map(102,vector<int>(102,-1));
    vector<vector<int>>ch(102,vector<int>(102,0));
    int s_x = 0 ,s_y = 0;
    // map 생성
    for(int i = 0;i<maps.size();i++){
        int m_i = i+1;
        for(int j = 0;j<maps[0].size();j++){
            int m_j = j+1;
            if(maps[i][j] == 'S'){
                map[m_i][m_j] = 0;
                s_x = m_j;
                s_y = m_i;
            }else if(maps[i][j] == 'O'){
                map[m_i][m_j] = 0;
            }else if(maps[i][j] == 'L'){
                map[m_i][m_j] = 1;
            }else if(maps[i][j] == 'E'){
                map[m_i][m_j] = 2;
            }else if(maps[i][j] == 'X'){
                map[m_i][m_j] = -1;
            }
        }
    }
    queue<Cor>q_l;//bfs queue 레버 당길때까지의 큐 
    queue<Cor>q_e;//bfs queue 종료지점까지의 큐
    q_l.push(Cor(s_x,s_y,0));
    
    ch[s_y][s_x] =1;
    bool l_c = false ; // 레버 당겨졌는지.
    Cor temp = Cor(0,0,2147000);
    while(!q_l.empty()){
 
        for(int i = 0 ; i<4;i++){
            int t_x = q_l.front().x;
            int t_y = q_l.front().y;
            int t_cnt = q_l.front().cnt;          

            if(map[t_y+dy[i]][t_x + dx[i]] == -1 || ch[t_y+dy[i]][t_x + dx[i]] == 1){
                //벽만난부분 or 왔던부분
                
            }else if(map[t_y+dy[i]][t_x + dx[i]] == 0 || map[t_y+dy[i]][t_x + dx[i]] == 2 ){
                // 통로거나 도착지점인 경우.
                
                ch[t_y+dy[i]][t_x + dx[i]] = 1;
                q_l.push(Cor(t_x+dx[i],t_y+dy[i],t_cnt+1));
            }else if(map[t_y+dy[i]][t_x + dx[i]] == 1){
                // 레버인 경우.
                l_c = true;
                //바로 break 하지말고 크기 비교해보자.
                if(temp.cnt > t_cnt+1){
                    temp = Cor(t_x + dx[i],t_y+dy[i],t_cnt+1);
                }
                
                

            }
        }
        q_l.pop();

    }
    if(!l_c){
        //레버가 안당겨졌다.
        return -1;
    }
   
    q_e.push(temp);
                
    for(int m = 0 ; m<ch.size();m++){
        for(int n = 0 ; n<ch[0].size();n++){
            ch[m][n] = 0;
        }
    }
    
                // ch 배열 초기화 >> 레버 당기고 부터는 다시 초기화 임.
    ch[temp.y][temp.x] = 1;
                // 처음꺼 다시 check
    
    while(!q_e.empty()){
        
        for(int i = 0 ; i<4;i++){
            int t_x = q_e.front().x;
            int t_y = q_e.front().y;
            int t_cnt = q_e.front().cnt;          
            
            if(map[t_y+dy[i]][t_x + dx[i]] == -1 || ch[t_y+dy[i]][t_x + dx[i]] == 1){
                //벽만난부분 or 왔던부분
                
            }else if(map[t_y+dy[i]][t_x + dx[i]] == 0 || map[t_y+dy[i]][t_x + dx[i]] == 1 ){
                // 통로거나 레버인 경우.
                
                ch[t_y+dy[i]][t_x + dx[i]] = 1;
                q_e.push(Cor(t_x+dx[i],t_y+dy[i],t_cnt+1));
            }else if(map[t_y+dy[i]][t_x + dx[i]] == 2){
                // 도착지점인 경우.
                return t_cnt+1;
                break;

            }
            
        }
        q_e.pop();

    }
    return -1;
}
/*
-1-1-1-1-1-1
-100001
-1-1-1-1-10
-100000
-10-1-1-1-1
-100002
s_x: 1 s_y: 1

*/
int main(){
    vector<string>maps = {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"};
    int answer = solution(maps);
    cout << answer;


    return 0;
}