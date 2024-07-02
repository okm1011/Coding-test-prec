#include <string>
#include <vector>
#include <iostream>
#include<map>

using namespace std;
/*
map은 각 노드가 key와 value 쌍으로 이루어진 트리입니다.  특히, 중복을 허용하지 않습니다.
따라서 map은 first, second가 있는 pair 객체로 저장되는 데 first- key로 second- value로 저장됩니다. 
C++의 map의 내부 구현은 검색, 삽입, 삭제가 O(logn) 인 레드블랙트리로 구성되어 있습니다.

여기서 포인트는 검색 삽입 삭제가 O(logn)이라는거
주의할점은 map쓸때 중복자료가 있으면 안된다는거.


*/
vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int> m;
    for(int i = 0 ; i < players.size();i++){
        m.insert({players[i],i});
        //요런 형태로 insert.
    }
    for(int i = 0 ; i < callings.size() ; i++){
        string temp = callings[i];
        int pos = m[temp]; // 이렇게 하면 알아서 탐색(O(logn)) 이후 temp 라는 key를 가진 value가 튀어나옴 >> 위치를 알 수가 있다

        string tp  = players[pos-1];
        players[pos-1] = players[pos];
        players[pos] = tp;
        m[temp] = pos-1;
        m[tp] = pos;
    }
    
    
    return players;
}
int main(){
    vector<string> players = {"mumu", "soe", "poe", "kai", "mine"};
    vector<string> callings = {"kai", "kai", "mine", "mine"};

    vector<string> answer = solution (players , callings);
    cout << answer[1];
    return 0;
}