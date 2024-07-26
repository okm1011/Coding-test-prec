#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());      
        nums.erase(unique(nums.begin(),nums.end()),nums.end());  
    }
};

int main(){
    vector<int>nums = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>>anwer = s.threeSum(nums);

    return 0;
}