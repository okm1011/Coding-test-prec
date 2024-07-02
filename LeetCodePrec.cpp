#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();
        vector<int> answer;
        answer.push_back(nums[0]);
        for(int i =1 ; i < nums.size() ; i++){
            if(nums[i] == answer[answer.size()-1]){
                k--;
            }else{
                answer.push_back(nums[i]);
            }
        }        
        nums = answer;
        return k;
    }
};