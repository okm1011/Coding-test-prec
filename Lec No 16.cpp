#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int t_max = 0;
    int maxProfit(vector<int>& prices) {
        for(int i = 0 ; i<prices.size();i++){
            int buy = prices[i];
            int sell = max_element(prices.begin() + i, prices.end());
            if(sell - buy > t_max){
                t_max = sell - buy;
            }
        }        
        return t_max;
    }
};