#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int answer = INT_MAX;
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        for(int right = 0 ; right<nums.size() ; right++){
            sum+=nums[right];
            if(sum >= target){             
                while(sum>=target){
                    if(answer > right-left + 1)answer = right-left + 1;
                    sum-=nums[left];
                    left++;
                }
            }
        }
        if(answer == INT_MAX)return 0;
        return answer;
    }
};