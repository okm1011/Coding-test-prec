#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         // second method -> since it is already sorted , i can use two pointer
         vector<int> answer;
         int num1_ptr = 0 , num2_ptr = 0;
         while(num1_ptr < m || num2_ptr < n ){
            if(num1_ptr >= m && num2_ptr < n){
                answer.push_back(nums2[num2_ptr]);
                num2_ptr++;     
                continue;           
            }else if(num2_ptr >= n && num1_ptr < m){
                answer.push_back(nums1[num1_ptr]);
                num1_ptr++;     
                continue;      
            }else{
                if(nums1[num1_ptr]>nums2[num2_ptr]){
                    answer.push_back(nums2[num2_ptr]);
                    num2_ptr++;
                }else if(nums1[num1_ptr]<nums2[num2_ptr]){
                    answer.push_back(nums1[num1_ptr]);
                    num1_ptr++;
                }else{
                    answer.push_back(nums1[num1_ptr]);
                    answer.push_back(nums1[num1_ptr]);
                    num1_ptr++;
                    num2_ptr++;
                }
            }

         }
         nums1 = answer;
    }
};