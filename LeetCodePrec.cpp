#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        //4가지 경우 +- or - or 숫자 or () or ' '
        // )) 부터 스택에 담으면 될텐데
        stack<int>st;
        vector<pair<int,int>>ptr;
        int left = 0;
        int right = s.size()-1;
        vector<int>left_vec;
        vector<int>right_vec;
        while(left<right){
            if(s[left] == '('){
                left_vec.push_back(left);
            }
            if(s[right] == ')'){
                right_vec.push_back(right);
            }
            left++;
            right--;
        }
        for(int i = 0 ; i < left_vec.size() ; i++){
            ptr.push_back({left_vec[i],right_vec[i]});
        }
        pair<int,int>last = {INT_MAX,-INT_MAX};
        for(int i = ptr.size()-1 ; i>=0 ; i--){
            for(int j = ptr[i].second-1; j> ptr[i].first ; j++){
                if(s[j] != ' ' && j>last.second && j<last.first){
                    st.push(s[j]);
                }
            }
            last = ptr[i];
        }
        
        return 0;
    }
};

int main(){
    string input = "(1+(4+5+2)-3)+(6+8)";
    Solution s;
    int answer =s.calculate(input);

    return 0;
}