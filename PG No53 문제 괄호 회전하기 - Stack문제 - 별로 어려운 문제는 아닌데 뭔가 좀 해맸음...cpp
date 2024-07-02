#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

int solution(string s) {
    int answer = 0;
    if(s.size()%2 != 0){
        return 0;
    }
    for(int i = 0 ; i<s.size();i++){
        vector<int>temp;
        for(int j = 0 ; j <s.size() ; j++){
            switch(s[j]){
                case '[' :
                    temp.push_back(1);
                    break;
                case ']' :
                    temp.push_back(-1);
                    break;
                case '(' :
                    temp.push_back(2);
                    break;
                case ')' :
                    temp.push_back(-2);
                    break;
                case '{' :
                    temp.push_back(3);
                    break;
                case '}' :
                    temp.push_back(-3);
                    break;
                default:
                break;
            }
        }
        stack<int>st;
        bool flag =true;
        for(int j = 0;j<temp.size();j++){
            if(st.empty()){
                if(temp[j] < 0){
                    flag = false;
                    break;
                }else{
                    st.push(temp[j]);
                }

            }else{
                if((st.top()>0 && temp[j]>0) || (st.top()<0 && temp[j]<0)){
                    st.push(temp[j]);
                }else{
                    if(st.top() == -(temp[j])){
                        st.pop();
                    }else{
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag)answer++;
        s = s + s[0];
        s.erase(0,1);
    }

    return answer;
}

int main(){
    string s = "[)(]";
    int answer = solution(s);
    cout << answer;

    return 0;
}