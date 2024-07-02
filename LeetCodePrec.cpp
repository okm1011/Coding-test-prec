#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        vector<int> answer;
        for(int i=0; i<nums.size();i++){
            if(nums[i] == val){
                k--;
            }else{
                answer.push_back(nums[i]);
            }
        }
        sort(answer.begin(),answer.end());
        nums = answer;
        return k;
    }
};