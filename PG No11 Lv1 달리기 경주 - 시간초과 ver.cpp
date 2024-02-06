#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 생각나는대로 풀었던 부분인데 시간초과로 Fail이 났음.
vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    for(int i = 0 ; i < callings.size();i++){
        string temp = callings[i];
        for(int j = 0 ; j<players.size();j++){
            //이부분에서 2중 포문이 돌아가기 떄문에 시간초과 >> 이를 해결하려면 map을써야한다고함.
            if(players[j] == temp){
                string tp;
                if(j!=0){
                    tp = players[j-1];
                    players[j-1] = players[j];
                    players[j] = tp;
                }

            }
        }
    }
    answer = players;
    return answer;
}
int main(){
    vector<string> players = {"mumu", "soe", "poe", "kai", "mine"};
    vector<string> callings = {"kai", "kai", "mine", "mine"};

    vector<string> answer = solution (players , callings);
    cout << answer[1];
    return 0;
}