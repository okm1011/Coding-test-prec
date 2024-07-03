#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 시간복잡도 O(1)은 N과 상관없이 일정하게 풀 수 있냐는건데 음...
        // n/2보다 많기 떄문에 걍 정렬해서 제일 가운데 값 뽑으면 되긴함 근데 이것도 O(N)일텐데... 아 O(1)의 공간 이러면 걍 정렬     

        int center = nums.size()/2; 
        sort(nums.begin() , nums.end());
        return nums[center];
    }
};