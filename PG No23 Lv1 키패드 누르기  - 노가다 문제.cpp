#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<vector<int>>map(4,vector<int>(3,0));
    int cnt = 1;
    for(int i = 0 ; i <4 ; i++){
        for(int j = 0  ; j<3;j++){
            if(cnt == 11){
                map[i][j] = 0;
                cnt++;                   
            }else{
                map[i][j] = cnt;
                cnt++;                    
            }
            
        }
        
    }
    int l_x = 0 , l_y = 3 , r_x = 2 , r_y = 3;
    //init value for left , right
    // value10 = '*' value12 = '#'
    for(int i = 0 ; i<numbers.size();i++){
        
        int tg = numbers[i];
        int tg_x , tg_y;
        for(int j = 0 ; j <4;j++){
            for(int k = 0 ; k < 3 ; k++){
                
                if(tg == map[j][k]){
                    
                    tg_x = k;
                    tg_y = j;
                }
            }
        }
        
        if(tg == 1 || tg == 4 || tg == 7 ){
            answer = answer + "L";
            l_x = tg_x;
            l_y = tg_y;
        }else if(tg == 3 || tg == 6 || tg == 9 ){
            answer = answer + "R";\
            r_x = tg_x;
            r_y = tg_y;
        }else{
            int l_d = abs(tg_x - l_x) + abs(tg_y - l_y);
            int r_d = abs(tg_x - r_x) + abs(tg_y - r_y);
            if(l_d>r_d){
                answer = answer + "R";
                r_x = tg_x;
                r_y = tg_y; 
            }else if(l_d<r_d){
                answer = answer + "L";
                l_x = tg_x;
                l_y = tg_y; 
            }else{
                if(hand == "right"){
                    answer = answer + "R";
                    r_x = tg_x;
                    r_y = tg_y; 
                }else{
                    answer = answer + "L";
                    l_x = tg_x;
                    l_y = tg_y; 
                }
            }
        }

        

    }
    return answer;
}
    //1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5
    


int main(){
    vector<int> numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    string hand = "right";
    string answer = solution(numbers,hand);
    cout << answer;
    return 0;
}