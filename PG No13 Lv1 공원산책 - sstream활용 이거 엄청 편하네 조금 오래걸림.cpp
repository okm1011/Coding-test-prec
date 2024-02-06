#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
// dxy[0] = 동쪽 E dxy[1] = 남쪽 S  dxy[2] = 서쪽 W dxy[3] = 북쪽 N
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x , y;
    // xy좌표
    vector<vector<int>>map(park.size(),vector<int>(park[0].size(),0));
    // map 작성 based on park string
    for(int i = 0 ; i < park.size() ; i++){
        for(int j = 0 ; j < park[i].size();j++){
            if(park[i][j] == 'S'){ 
                x = j ;
                y = i ;
            }
            else if(park[i][j] == 'X'){
                map[i][j] = 1;
            }
        }
    }



    for(int i = 0;i<routes.size();i++){
        stringstream ss;
        ss.str(routes[i]);
        string dir;
        int dis;
        ss >> dir;
        ss >> dis;
        int cop = 0;
        // cop == 방향
        
        if(dir == "E"){
            cop = 0;
        }else if(dir == "S"){
            cop = 1;
        }else if(dir == "W"){
            cop = 2;
        }else if(dir == "N"){
            cop = 3;
        }else{

        }
        
        int t_x = x , t_y = y;
        bool flag = true;
        for(int j = 0 ; j<dis ; j++){
            if(t_x+dx[cop]>=0 && t_y+dy[cop]>=0 && t_x+dx[cop] < park[0].size() && t_y+dy[cop] < park.size()){
                if(map[t_y+dy[cop]][t_x+dx[cop]]!=1){
                    // 여기서 맨날 x,y 좌표 헷갈려서 틀리는데 조심할 것
                    t_x = t_x+dx[cop];
                    t_y = t_y+dy[cop];
                }else{
                    flag = false;
                }
                
            }else{
                flag = false;
            }
        }
        if(flag){
            x = t_x;
            y = t_y;
        }


    }
    answer.push_back(y);
    answer.push_back(x);

    return answer;
}
int main(){
    vector<string> park = {"SOO","OXX","OOO"};
    vector<string> routes = {"E 2","S 2","W 1"};
    vector<int> answer = solution(park,routes);
    cout << answer[0];
    return 0;
}