#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int Max = -1000;
        int start = 0 ;
        int end = height.size()-1;
        while(start < end){
            int water = (end - start) * min(height[end],height[start]);
            if(Max < water){
                Max = water;
            }
            if(height[start]>=height[end]){
                end--;
            }else{
                start++;
            }
        }
        return Max;
    }
};

int main(){
    vector<int>in = {1,2,1};
    Solution s;
    int answer = s.maxArea(in);
    cout << answer;

    return 0;
}