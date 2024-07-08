#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h_index = 1;
        while(1){
            int cnt = 0;
            bool index_done = false;
            for(int i = 0 ; i<citations.size();i++){
                if(citations[i]>=h_index){
                    cnt ++;
                    if(cnt >= h_index){
                        h_index++;
                        index_done = true;
                        break;
                    }
                }
            }
            if(!index_done)break;

        }
        return h_index-1;
    }
};