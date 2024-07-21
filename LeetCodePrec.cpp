#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string answer = "";
        if(numRows==1)return s;
        for(int i = 0 ; i < numRows ; i++){
            int ptr = i;
            bool flag = true;
            while(ptr<s.size()){
                answer+=s[ptr];
                if(i == 0 || i == numRows -1){
                    ptr+=(numRows + numRows - 2);
                }else{
                    if(flag){
                        ptr+=(2*numRows - (2*(i+1)));
                        flag = false;
                    }else{
                        ptr+=(2*numRows - (2*(numRows-i)));
                        flag = true;
                    }
                    // 이 사이가 문제네.
                    // 1 3 5 7 9 (row 3)
                    // 1 5 7 11 13 (row 4)
                }

            }
        }
        cout << answer;
        return answer;
    }
};

int main(){
    string input = "A";
    Solution s;
    string answer = s.convert(input,1);
}