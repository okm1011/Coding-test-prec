#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    vector<pair<int,int>>temp;
    // 순서를 rank[i],i 순으로 해야할 것 같음
    for(int i = 0; i <rank.size();i++){
        if(attendance[i]==true){
            temp.push_back(make_pair(rank[i],i));
        }
    }
    sort(temp.begin(),temp.end());
    int answer = 10000*temp[0].second + 100*temp[1].second + temp[2].second;
    return answer;
} 
int main(){
    vector<int> rank = {1,2,3,4};
    vector<bool> attendance = {true,true,true,false};
    int res = solution(rank,attendance);
    cout << res;
    return 0;
}