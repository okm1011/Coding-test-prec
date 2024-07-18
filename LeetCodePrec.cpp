#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<int>nums;
        vector<string> answer_tmp;
        map<int,vector<string>>m;
        
        vector<string>one = {"I","X","C","M"};
        vector<string>five = {"V","L","D"};
        vector<string>four = {"IV","XL","CD"};
        vector<string>nine = {"IX","XC","CM"};
        m.insert(make_pair(1,one));
        m.insert(make_pair(5,five));
        m.insert(make_pair(4,four));
        m.insert(make_pair(9,nine));
        while(num != 0){
            //cout << num%10 << "\n";
            nums.push_back(num%10);
            num /= 10;
        }

        for(int i = 0; i<nums.size();i++){
            if(nums[i] == 1 || nums[i] == 4 || nums[i] == 5 || nums[i] == 9){
                answer_tmp.push_back(m[nums[i]][i]);
            }else{
                if(nums[i]>5){
                    for(int j = 0 ; j<nums[i]-5 ; j++){
                        answer_tmp.push_back(m[1][i]);
                    }
                    answer_tmp.push_back(m[5][i]);
                }else{
                    if(nums[i]==0)continue;
                    for(int j = 0 ; j<nums[i] ; j++){
                        answer_tmp.push_back(m[1][i]);
                    }
                }
            }
            
        }
        string answer = "";
        for(int i = answer_tmp.size()-1; i>=0 ; i--){
            answer += answer_tmp[i];
        }
        return answer;

    }
};

int main(){
    Solution s;
    string answer = s.intToRoman(1994);
    cout <<answer;

    return 0;
}