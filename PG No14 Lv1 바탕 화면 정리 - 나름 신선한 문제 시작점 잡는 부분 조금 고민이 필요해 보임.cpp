#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<vector<int>>map(wallpaper.size(),vector<int>(wallpaper[0].size(),0));
    // wallpaper 변환 용 2차원 배열 vector
    int x_max = -2147000;
    int y_max = -2147000;
    // 끝점 잡는 max값
    int x_start = 0;
    int y_start = 0;
    // 시작점 좌표
    
    bool y_ch_flag = true;
    // 시작점 잡는 flag
    for(int i = 0 ; i < wallpaper.size() ; i++){
        bool y_flag = true;
        
        for(int j = 0 ; j < wallpaper[0].size() ; j++){
            if(wallpaper[i][j] == '#'){
                y_flag = false;
                map[i][j] = 1;
                
                if(i>y_max){
                    y_max = i;
                }
                if(j>x_max){
                    x_max = j;
                }
            }
        }
        if(y_flag&&y_ch_flag){
            y_start++;
        }else{
            y_ch_flag = false;
        }
    }

    // xy 반전해서 다시한번 scan for x_start
    bool x_ch_flag = true;
    for(int i = 0 ; i < wallpaper[0].size() ; i++){
        bool x_flag = true;
        
        for(int j = 0 ; j < wallpaper.size() ; j++){
            //cout << " i: " << i << " j "<<j<<"\n";
            cout << map[j][i];
            if(map[j][i] == 1){
                x_flag = false;
            }
        }cout << "\n";
        if(x_flag&&x_ch_flag==true){
            cout << "in";
            x_start++;
        }else{
            x_ch_flag = false;
            //여기서 끝나면 저거 해줘야겠네 ch_flag 반전 안해주면 뒤에서 계속 x_start 올려버리네.
        }
    }    
 
    answer.push_back(y_start);
    answer.push_back(x_start);
    answer.push_back(y_max+1);
    answer.push_back(x_max+1);
    /*
    여기까지
    011000110
    100101001
    100010001
    010000010
    001000100
    000101000
    000010000
    */

    return answer;
}
int main(){
    vector<string> wallpaper = {"..........", ".....#....", "......##..", "...##.....", "....#....."};
    vector<int> answer = solution(wallpaper);

    return 0;
}