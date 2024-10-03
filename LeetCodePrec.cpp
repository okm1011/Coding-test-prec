#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
int cnt= 0;
vector<int>ch_num(10000000,0);

bool is_prime(int n){
    if(n==1)return false;
    cout << n <<"\n";
    for(int i = 2; i<=sqrt(n);i++){
        if(n%i == 0)return false;
    }return true;
}
void find_dfs(vector<int>nums,vector<int>ch,int target){
    if(target!=0 && ch_num[target] == 0){
        ch_num[target] = 1;
        bool flag = is_prime(target);
        if(flag)cnt++;
    }
    for(int i = 0 ; i<nums.size();i++){
        if(nums[i]==0 && target == 0)continue;
        if(ch[i] == 0){
            ch[i]=1;
            find_dfs(nums,ch,target*10+nums[i]);
            ch[i] = 0;
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    vector<int>nums;
    for(int i = 0 ; i<numbers.size();i++){
        int temp = numbers[i] - '0';
        nums.push_back(temp);
    }
    vector<int>ch(nums.size(),0);

    find_dfs(nums,ch,0);
    answer = cnt;
    return answer;
}