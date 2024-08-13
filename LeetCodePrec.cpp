#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        else if(nums.size() == 1)return 1;
        int answer = 0;
        set<int>s;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i<nums.size();i++){
            s.insert(nums[i]);
        }
        int before = INT_MAX;
        int cnt = 1;
        for(auto temp : s){
            if(before == INT_MAX)before = temp;
            else{
                if(before + 1 == temp){
                    cnt++;
                    before = temp;
                }else{
                    if(cnt > answer) answer = cnt;
                    cnt = 1;
                    before = temp;
                }
            }
        }
        return answer;
    }
};

int main(){
    vector<int> in = {0,3,7,2,5,8,4,6,0,1};
    Solution s;
    int answer= s.longestConsecutive(in);


}