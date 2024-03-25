#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int dx[] ={1,-1,0,0};
int dy[] ={0,0,1,-1}; 

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;


    for(int i = 0 ; i<places.size();i++){
        int x = 0 , y = 0;
        vector<pair<int,int>>P;
        vector<pair<int,int>>X;
        vector<pair<int,int>>O;
        // 총 5개의 강의실
        for(int j = 0 ; j<places[i].size() ; j++){
            for(int k = 0 ; k<5 ; k++){
                x = k;
                y = j;
                if(places[i][j][k] == 'P'){
                    P.push_back(make_pair(x,y));
                }else if(places[i][j][k] == 'X'){
                    X.push_back(make_pair(x,y));
                }else{
                    O.push_back(make_pair(x,y));
                }

            }
            
        }
        vector<vector<int>>ch(P.size(),vector<int>(P.size(),0));
        bool flag = true;
        for(int j = 0 ; j<P.size();j++){
            for(int k = 0 ; k<P.size();k++){
                if(j==k)continue;
                if((abs(P[j].first-P[k].first) + abs(P[j].second-P[k].second))<=2 && (ch[j][k] == 0 && ch[k][j] == 0)){
                    ch[j][k] = 1;
                    ch[k][j] = 1;
                    queue<pair<int,int>>move;
                    move.push(P[j]);
                    while(!move.empty()){
                        int pos_x = move.front().first;
                        int pos_y = move.front().second;
                        move.pop();
                        for(int m = 0 ; m<5 ; m++){
                            if(0<=pos_x + dx[m] && 5>pos_x + dx[m] && 0<=pos_y + dy[m] && 5>pos_y + dy[m]){
                                int t_pos_x = pos_x + dx[m];
                                int t_pos_y = pos_y + dy[m];
                                if(t_pos_x == P[k].first && t_pos_y == P[k].second){
                                    flag = false;
                                    while(!move.empty()){
                                        move.pop();
                                    }
                                    break;                   
                                }
                                else if(places[i][t_pos_y][t_pos_x] == 'X'){
                                    continue;
                                }else{
                                    if(abs(t_pos_x-P[k].first) + abs(t_pos_y-P[k].second)<=2){
                                        move.push(make_pair(t_pos_x,t_pos_y));
                                    }                                   
                                }
                            }
                        }
                    }
                    /*
                    for(int m = 0 ; m<5;m++){
                        if(0<=P[j].first + dx[m] && 5>P[j].first + dx[m] && 0<=P[j].second + dy[m] && 5>P[j].second + dy[m]){
                            int temp_x = P[j].first + dx[m];
                            int temp_y = P[j].second + dy[m];
                            if(temp_x == P[k].first && temp_y == P[k].second){
                                flag = false;
                                break;
                            }else if(places[i][temp_y][temp_x] == 'X'){
                                continue;
                            }else{
                                for(int n = 0 ; n < 5 ; n++){
                                    if(0<=temp_x + dx[n] && 5>temp_x + dx[n] && 0<=temp_y + dy[n] && 5>temp_y + dy[n]){
                                        int d_temp_x = temp_x + dx[n];
                                        int d_temp_y = temp_y + dy[n];
                                        if(d_temp_x == P[k].first && d_temp_y == P[k].second){
                                            flag = false;
                                            break;
                                        }
                                    }

                                }
                            }
                        }

                    }
                    */
//places[i][temp_y][temp_x] == 
                }
            }
        }
        if(flag){
            answer.push_back(1);
        }else{
            answer.push_back(0);
        }


    }

    


    return answer;
}

int main(){
    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    vector<int>answer = solution(places);
    for(int i = 0 ; i<answer.size();i++){
        cout << answer[i] << " ";
    }
    return 0;
}