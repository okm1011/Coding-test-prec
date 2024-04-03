#include<iostream>
#include<string>
#include<vector>

using namespace std;
int res = 0;

void dfs(vector<int> numbers, int target ,int level){
    if(level == numbers.size()){
        int sum = 0;
        for(int i = 0 ; i<numbers.size();i++){
            sum+=numbers[i];
        }
        if(sum == target)res++;
    }else{
        vector<int>temp = numbers;
        temp[level] = abs(temp[level]);
        dfs(temp,target,level+1);
        temp[level] = -abs(temp[level]);
        dfs(temp,target,level+1);
    }


}


int solution(vector<int> numbers, int target) {
    // 딱 둘중 하나임. 모든자리에 +인가 -인가.
    dfs(numbers,target,0);
    return res;
}

int main(){
    vector<int> numbers = {4, 1, 2, 1};
    int target = 4;
    int answer = solution(numbers,target);
    cout << answer;
    return 0;
}