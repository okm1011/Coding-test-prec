#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 방법 3가지 
        // 2번으로 생각난거 링크드 리스트 느낌?
\       
        int start = 0;
        for(int i = 0 ; i < k ; i++){
            start--;
            if(start <0)start = nums.size()-1;
        }
        vector<int>answer;
        int cnt = 0;
        for(int i = 0 ; i < nums.size();i++){
            answer.push_back(nums[start]);
            start++;
            if(start >= nums.size())start = 0;
        }
        nums = answer;


    }
    
};