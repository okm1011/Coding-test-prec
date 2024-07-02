#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int cnt = 0;
    for(int i = 0 ; i<=myString.size();i++){
        if(myString[i]=='x'){
            answer.push_back(cnt);
            cnt = 0;
        }else if(myString[i]!='\0'){
            // 여기서 myString[i]!='\0' 넣어준거는 저것도 cnt로 쳐서 마지막이 틀리더라구
            cnt++;
        }
    }
    answer.push_back(cnt);
    return answer;
}