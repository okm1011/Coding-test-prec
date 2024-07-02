#include <string>
#include <vector>

using namespace std;

//공백으로 구분하기 1과의 차이점은 단어 사이사이에 공백이 중복으로 들어갈 수 있다는점
vector<string> solution(string my_string) {
    vector<string> answer;
    string temp;
    for(int i = 0 ; i<my_string.size();i++){
        if(my_string[i] != ' '){
            temp += my_string[i];
        }else if(temp.size()>0){
            // temp 가 비어있지 않을때만 push_back 실행
            answer.push_back(temp);
            temp = "";
        }else{

        }
    }
    // temp 가 비어있지 않을때만 push_back 실행
    if(temp.size()>0)answer.push_back(temp);
    return answer;
}