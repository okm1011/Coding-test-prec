#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //map 은 못써 중복이름이 있어서
    //사전 순 정리하면 좀 더 빠르긴 하겠다 break 갈기면
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    vector<pair<string,char>>tp;
    
    for(int i = 0 ; i<completion.size();i++){
        if(participant[i]!=completion[i]){
            answer = participant[i];
            break;
        }
    }
    //이거 마지막꺼 참조하면 completion 배열 크기때문에 참조 오류나니까 추가해준 부분임.
    if(answer==""){
        answer = participant[participant.size()-1];
    }


    
    
    return answer;
}   

int main(){
    vector<string> participant = {"marina", "josipa", "nikola","filipa","vinko"};
    vector<string> completion = {"marina", "josipa", "nikola", "filipa"};
    string answer = solution(participant,completion);
    cout << answer;
    return 0;
}