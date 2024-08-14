#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int,int>>temp_vec;
        vector<vector<int>>answer;
        int flag = false;
        for(auto temp : intervals){
            if(!flag && temp[0]>=newInterval[0]){
                flag = true;
                temp_vec.push_back({newInterval[0],newInterval[1]});
                temp_vec.push_back({temp[0],temp[1]});
            }else{
                temp_vec.push_back({temp[0],temp[1]});
            }
            
        }
        if(!flag)temp_vec.push_back({newInterval[0],newInterval[1]});

        int start = -1;
        int end = 0;
        for(auto temp : temp_vec){
            if(start == -1){
                start = temp.first;
                end = temp.second;
            }else{
                if(temp.first<=end && temp.first>=start || temp.second<=end && temp.second>=start){
                    if(temp.first <= start)start = temp.first;
                    if(temp.second >= end) end = temp.second;
                }else{
                    answer.push_back({start,end});
                    start = temp.first;
                    end = temp.second;                    
                }

            }
        }answer.push_back({start,end});
        return answer;
    }
};

int main(){
    vector<vector<int>>inter = {{1,5}};
    vector<int>new_vec = {2,7};
    Solution s;
    vector<vector<int>>ret = s.insert(inter,new_vec);


    return 0;
}