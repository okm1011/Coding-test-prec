#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l_max = height[0];
        int r_max = height[n-1];
        int l_pos = 1 , r_pos = n-2;
        int water_cnt = 0;
        while(l_pos<=r_pos){
            if(height[l_pos]>=l_max){
                l_max = height[l_pos];
                l_pos++;
            }else if(height[r_pos] >= r_max){
                r_max = height[r_pos];
                r_pos--;                
            }else if(l_max <= r_max ){
                water_cnt += l_max - height[l_pos];
                l_pos++;
            }else{
                water_cnt += r_max - height[r_pos];
                r_pos--;
            }
        }

        return water_cnt;
    }
};

int main(){
    Solution S;
    vector<int> input = {4,2,0,3,2,5};
    int answer = S.trap(input);

    return 0;
}