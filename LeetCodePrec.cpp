#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    static bool compare(vector<int>a , vector<int>b){
        return a[0] > b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>answer;
        int start = -1;
        int end = 0;
        sort(intervals.begin(),intervals.end(),compare);
        for(auto temp : intervals){
            if(start == -1){
                start = temp[0];
                end = temp[1];
            }else{
                if(end >= temp[0] && end<=temp[1]){
                    end = temp[1];
                }else{
                    vector<int>in = {start,end};
                    answer.push_back(in);
                    start = temp[0];
                    end = temp[1];
                }
            }
        }
        vector<int>in = {start,end};
        answer.push_back(in);
        return answer;
    }
};