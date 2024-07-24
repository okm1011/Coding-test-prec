#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>answer;
        int f_p = 0;
        int l_p = numbers.size()-1;
        while(1){
            int result = numbers[f_p] + numbers[l_p];
            if(result > target){
                l_p--;
            }else if(result < target){
                f_p++;
            }else{
                break;
            }
        }
        answer.push_back(f_p+1);
        answer.push_back(l_p+1);
        return answer;
    }
};