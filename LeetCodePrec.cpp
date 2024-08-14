#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int answer = 0;
        sort(points.begin(),points.end());
        int target;
        for(auto temp : points){
            if(temp == points[0]){
                target = temp[1];
                answer++;
            }else{ 
                // 안에 포함되는 경우 겹치는 경우 아예 떨어지는 경우.
                if(target>temp[0]){
                    target = temp[1];
                    answer++;
                }else{
                    if(target>=temp[1])target = temp[1];
                }

            }
        }
        return answer;
    }
};

int main(){
    vector<vector<int>>in = {{10,16},{2,8},{1,6},{7,12}};
    Solution s;
    int answer = s.findMinArrowShots(in);

    return 0;
}