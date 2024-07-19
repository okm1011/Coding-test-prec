#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        //stack 쓰면 되잖아
        stack<string> st;
        string temp ="";
        for(int i = 0 ; i<s.size();i++){
            if(temp != "" && s[i]==' '){
                if(st.empty()){
                    st.push(temp);
                    temp = "";
                }else{
                    st.push(temp+" ");
                    temp = "";
                }

            }else if(s[i] != ' '){
                temp += s[i];
            }
        }
        if(temp != "" && !st.empty()) st.push(temp+" ");
        else st.push(temp);
        string answer = "";
        while(!st.empty()){
            answer += st.top();
            st.pop();
        }
        return answer;

    }
};

int main(){
    Solution s;
    string input = "EPY2giL";
    string answer = s.reverseWords(input);
    return 0;
}