#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    // s는 only 소문자 a 97 z 122 << 길이 26짜리 vector배열 만들면 됨
    vector<int>map(26,0);
    for(int i = 0 ; i < s.size();i++){
        int asc = s[i];
        map[asc - 97]++;
    }
    for(int i = 0 ; i < 26 ; i++){
        if(map[i]==1){
            char asc2 = i+97;
            answer = answer+asc2;
        }
    }
    return answer;
}
int main(){
    string a = "abcabcadc";
    string res = solution(a);
    cout << res;
}