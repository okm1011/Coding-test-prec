#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<string>> book_time) {
    
    // step 1 string to int 배열로 변경.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    // 시작시간순으로 pq 사용 정렬하기위한 pq.

    for(int i = 0 ; i<book_time.size();i++){
        pair<int,int>tmp;
        for(int j = 0 ; j<2 ; j++){
            //:제외 하고 ss로 뽑아서 분으로 바꿔서 정렬
            stringstream ss;
            string temp = book_time[i][j];
            temp.replace(temp.find(":"),1," ");
            int a,b,time;
            ss.str(temp);
            ss>>a>>b;
            time = a*60 + b;
            if(j==0){
                tmp.first = time;
            }else{
                tmp.second = time;
            }
        }
        pq.push(tmp);
        
    }
    

    vector<int>rooms;
    int Max_cnt = -1000;
    int cnt = 0;
    // 방 사용  vector int 는 종료시간 +10 & max room사용 cnt 선언  

    
    
    while(!pq.empty()){
        pair<int,int>temp_c = pq.top();
        pq.pop();
        bool next = true; 
        bool no_room = true;
        for(int i = 0;i<rooms.size();i++){
            // 다음 손님 시작시간 기준으로 방 정리 끝난애들 전부 방 비우고 cnt --
            if(rooms[i] <= temp_c.first){
                no_room = false;
                if(next){
                    //다음 손님 빈방에 채워넣거나
                    next = false;
                    rooms[i] = temp_c.second +10;
                }else{
                    // 이미 채워놨으면 나머지 방 전부 비우는 과정.
                    rooms[i] = 0;
                    cnt --;
                }
            }

        }
        if(no_room){
            //방이 없다면 추가
            rooms.push_back(temp_c.second+10);
            cnt++; 
            if(Max_cnt<cnt){
                Max_cnt = cnt;
            }
        }

        

    }

    return Max_cnt;
}

int main(){
    vector<vector<string>> book_time = {{"09:10", "10:10"}, {"09:10", "10:10"}, {"10:20", "12:20"}, {"10:20", "12:20"}};
    int answer = solution(book_time);
    cout << answer;
    return 0;
}