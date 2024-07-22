#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:

    string space(vector<string>& words, int maxWidth) {
        string answer = "";
        if(words.size() == 1){
            answer += words[0];
            for(int i = 0 ; i<maxWidth - words[0].size() ; i++){
                answer += ' ';
            }
            return answer;
        }else if(words.size() == 2){
            answer += words[0];
            for(int i = 0 ; i<maxWidth - words[0].size() - words[1].size()  ; i++){
                answer += ' ';
            }
            answer += words[1];
            return answer;
        }else{
            // over 3
            answer += words[0];
            int div = words.size() -1;
            vector<int>space(div,maxWidth/div);
            for(int i = 0 ; i < maxWidth%div ; i++){
                space[i] +=1;
            }
            int i_cnt = 0;
            for(int i = 1 ; i<words.size()-1; i++){
                answer += ' ' * space[i_cnt];
                answer += words[i];
                answer += ' ' * space[i_cnt+1];
                i_cnt += 2;
            }
            answer += words[words.size()-1];
            return answer;
        }

    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> temp;
        vector<string> answer;
        int cnt = 0;
        for(int i = 0 ; i<words.size() ; i++){
            cnt += words[i].size();
            if(temp.size()<2){
                cnt += 1;
            }else{
                cnt += 2;
            }
            if(cnt <= maxWidth){
                temp.push_back(words[i]);
            }else{
                string temp_answer = space(temp,maxWidth);
                answer.push_back(temp_answer);
                cnt = 0;
                vector<string>temp_re;
                temp = temp_re;
            }
        }
        return answer;



    }
};

int main(){
    vector<string>input = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    Solution s;
    vector<string>answer = s.fullJustify(input,maxWidth);


    return 0;
}

// ' '로 초기화 되어있는 2차원 배열에다가 word left 넣고 right 넣고 추가로 넣으면 앞으로 밀리고 이렇게 가야할 것같긴한데 음
// space로 even이 안되면 왼쪽이 space 더 가져가는게 규칙. 
// 두가지 기능으로 나눈다? maxwidth에 최대한 넣을수 있는 단어 뽑고 >> 1단어 왼쪽 정렬 스페이스 1 1단어 오른쪽 스페이1 나머지 양쪽 스페이스 2 해서 max word 뽑아서 배치 따로?? 이거 왜케 하기가 싫냐..