#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    static bool comp(vector<int>a,vector<int>b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>answer;
        sort(intervals.begin(),intervals.end(),comp);
        int start = -1;
        int end = 0;
        for(auto temp : intervals){
            if(start == -1){
                start = temp[0];
                end = temp[1];
            }else{
                if(temp[0] > end ){
                    answer.push_back({start,end});
                    start = temp[0];
                    end = temp[1];                    
                }else{
                    if(temp[0]<=start)start = temp[0];
                    if(temp[1]>=end) end = temp[1];
                }
            }
            
        }
        answer.push_back({start,end});
        return answer;
    }
};