#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int solution(string s) {
    int min_result = s.length();
    for(int i = 1 ; i<=(s.size()/2) ; i++){
        
        int slice = i;
        queue<string>q;
        int cnt = 0;
        string temp = "";
        for(int j = 0 ; j<s.size();j++){
            if(cnt==slice){
                q.push(temp);
                temp =s[j];
                cnt = 1;
            }else{
                temp += s[j];
                cnt++  ;                 
            }
        }
        q.push(temp);

        string res = "";
        
        int q_cnt = 1;
        int sum = 0;
        while(1){
            
            if(q.size() == 1){
                if(q_cnt>1){
                    res += to_string(q_cnt) + q.front();
                }else{
                    res += q.front();
                }
                break;
            }            
            

            string prev = q.front();
            q.pop();
            if(prev == q.front()){
                q_cnt++;
            }else{
                if(q_cnt>1){
                    sum += sum; 
                    res += to_string(q_cnt) + prev;
                    q_cnt = 1;
                }else{
                    res += prev;
                }
            }
        }
        int len_res = res.length();
        if(len_res < min_result){
            min_result = len_res;
        }
    }
    return min_result;
}

int main(){

    string s = "aabbaccc";
    int answer = solution(s);
    cout << answer;


    return 0;
}