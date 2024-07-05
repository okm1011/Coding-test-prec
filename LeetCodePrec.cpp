#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool>dp(nums.size(),false);
        dp[0] = true;
        int step_left = 0;
        for(int i = 0; i<nums.size()-1;i++){
            step_left = max(nums[i],step_left);
            if( step_left > 0){
                dp[i+1]=true;
                step_left--;
            }
            else{break;}
            
        }
        return dp[nums.size()-1];
    }
};


int main(){

    vector<int>in = {2,0,0};
    Solution s;
    bool answer = s.canJump(in);
}