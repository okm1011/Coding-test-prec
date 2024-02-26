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
    int Max_cnt = 0;
    // 방 사용  vector int 는 종료시간 +10 & max room사용 cnt 선언  

    // 다시해보자 1분1분 지나가는 기준으로 rooms 재설정 및 cnt 갱신
    
    for(int i =pq.top().first;i<=1440 ; i++){
        if(pq.empty())return Max_cnt;
        for(int j = 0;j<rooms.size();j++){
            if(rooms[j]<=i){
                rooms.erase(rooms.begin()+j);
                j--;
            }
        }
        while(!pq.empty()){
            if(pq.top().first == i){
                rooms.push_back(pq.top().second + 10);
                pq.pop();
            }else{
                break;
            }

        }

        
        if(Max_cnt < rooms.size()){
            Max_cnt = rooms.size();
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