#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Min;


class Solution {
public:
    void dfs(vector<int>& num,int start , int step_left ,int cnt ){
        if(cnt >= Min)return;
        for(int i = 1 ; i<=step_left ; i++){
            if(start+i >= num.size()-1){
                if(cnt+1<Min)Min=cnt+1;
                return;
            }else{
                dfs(num, start + i , max(step_left - i , num[start + i]) ,cnt + 1 );
            }
            
        }
    }
    int jump(vector<int>& nums) {
        int answer = 0;
        // this should be dfs..
        Min = 100001; // Reset Min for each test case
        if(nums.size() <= 1) return 0;
        dfs(nums,0,nums[0],0);
        return Min;
    }
};



int main(){
    vector<int>num = {2,1};
    Solution s;
    int answer = s.jump(num);
    cout << answer;
    
    
}