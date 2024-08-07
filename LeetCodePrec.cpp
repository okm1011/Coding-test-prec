#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ch(words.size(),0);
        int length = words[0].size();
        vector<int>answer;
        int left = 0;
        int cnt = 0;
        //left가 answer에 들어가는 시작지점이 되는거임.
        for(int right = 0 ; right<s.size();right+=length){
            string temp = s.substr(right,length);
            cout << "ch: " << find(words.begin(),words.end(),temp)- words.begin() << "\n";
            if(find(words.begin(),words.end(),temp) == words.end()){
                left=right+length;
                fill_n(ch.begin(),ch.size(),0);
                cnt = 0;
            }else if(ch[find(words.begin(),words.end(),temp) - words.begin()] == 0){
                ch[find(words.begin(),words.end(),temp)- words.begin()] = 1;
                cnt++;
                if(cnt == words.size()){
                    answer.push_back(left);
                    ch[find(words.begin(),words.end(),s.substr(left,length))- words.begin()] = 0;
                    cnt--;
                    left+=length;
                }

            }else{
                left = right;
                fill_n(ch.begin(),ch.size(),0);
                cnt = 1;
                ch[find(words.begin(),words.end(),temp) - words.begin()] = 1;
            }
        }
        return answer;
    }
};
int main(){
    string input = "barfoothefoobarman";
    vector<string>input2 = {"foo","bar"};
    Solution s;
    vector<int>answer = s.findSubstring(input , input2);
    return 0;
}