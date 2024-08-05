#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>answer;
        // 정렬해놓고 
        sort(nums.begin(),nums.end());
        return answer;
    }
};

int main(){

    vector<int>input = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>>answer = s.threeSum(input);
}