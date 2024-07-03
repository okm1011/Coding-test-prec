#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> answer;
        answer.push_back(nums[0]);
        int k = nums.size();
        int cnt = 0;
        for(int i = 1 ; i < nums.size();i++){
            if(nums[i] == answer[answer.size()-1]){
                if(cnt == 0){
                    answer.push_back(nums[i]);
                    cnt++;
                }else if(cnt == 1){
   
                    k--;
                }
            }else{
                answer.push_back(nums[i]);
                cnt = 0;
            }
        }
        nums = answer;
        return k;

    }
};