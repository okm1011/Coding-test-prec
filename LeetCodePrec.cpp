#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>answer;
        map<string,int>m;
        int cnt = 0;
        for(int i = 0 ; i < strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            auto ret = m.insert({temp,cnt});
            if(ret.second){
                vector<string>temp_vec = {strs[i]};
                answer.push_back(temp_vec);
                cnt++;
            }else{
                answer[m[temp]].push_back(strs[i]);
            }
        }
        return answer;
    }
};

int main(){
    vector<string>in = {"eat","tea","tan","ate","nat","bat"};
    Solution s;
    vector<vector<string>>answer = s.groupAnagrams(in);

    return 0;
}