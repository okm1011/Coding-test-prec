#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer=0;
        sort(nums.begin(),nums.end());
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i]>=target){
                answer++;
                return answer;
            }else{
                target-=nums[i];
                answer++;
            }
        }
        return 0;
    }
};
int main(){

    vector<int> input = {12,28,83,4,25,26,25,2,25,25,25,12};
    Solution s;
    int answer = s.minSubArrayLen(213,input);
}