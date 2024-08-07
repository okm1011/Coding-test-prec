#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>ch(200,0);
        int answer = 0;
        int left = 0;
        for(int right = 0; right<s.size();right++){
            ch[s[right]]++;
            if(ch[s[right]]==1){
                answer = max(answer,right-left+1);
            }else{
                while(s[left]!=s[right] && left<=right){
                    ch[s[left]]--;
                    left++;                    
                }
                ch[s[left]]--;
                left++;  
                answer = max(answer,right-left+1);    
            }
        }
        return answer;
    }
};
int main(){
    string input = "abcabcbb";
    Solution s;
    int answer = s.lengthOfLongestSubstring(input);

    return 0;
}