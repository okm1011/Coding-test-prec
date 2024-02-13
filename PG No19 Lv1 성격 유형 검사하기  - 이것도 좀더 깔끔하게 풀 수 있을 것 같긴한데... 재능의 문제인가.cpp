#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int>cnt(8,0);
    //0(R) ~ 7(N) 까지 count를 위한 cnt 배열
    string table = "RTCFJMAN";
    for(int i = 0 ; i<survey.size();i++){
        if(choices[i] > 4){
            int score = choices[i] -4;
            for(int j = 0 ; j<table.size();j++){
                if(table[j]==survey[i][1]){
                    cnt[j]+=score;
                }
            }
            
        }else if(choices[i] < 4){
            int score = 4-choices[i] ;
            for(int j = 0 ; j<table.size();j++){
                if(table[j]==survey[i][0]){
                    cnt[j]+=score;
                }
            }
        }else{
            //choices[i] == 4
        }
    }
    for(int i = 0 ; i<=6 ; i = i+2){
        if(cnt[i]>cnt[i+1]){
            answer += table[i];
        }else if(cnt[i]<cnt[i+1]){
            answer += table[i+1];
        }else{
            //cnt[i]==cnt[i+1]
            answer += table[i];
        }
    }
    return answer;
}
int main(){
    vector<string> survey = {"AN", "CF", "MJ", "RT", "NA"};
    vector<int> choices = {5, 3, 2, 7, 5};
    string answer = solution(survey,choices);
    cout << answer;
    return 0;
}