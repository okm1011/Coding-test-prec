#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>cnt(n+1,1);
    cnt[0] = 0;
    for(int i=0 ; i<reserve.size();i++){
        cnt[reserve[i]] = 2;
        //여벌 체육복 계산
    }
    for(int i=0 ; i<lost.size();i++){
        cnt[lost[i]]--;
        //도난 체육복 계산
    }
    for(int i =1;i<=n;i++){
        // 없는애 앞에부터 봐서 빌려주면 끝인데?
        if(cnt[i] ==0){
            if(cnt[i-1]==2){
                cnt[i-1] = 1;
                cnt[i]=1;
            }else if(cnt[i+1]==2){
                cnt[i+1] = 1;
                cnt[i]=1;
            }
        }
    }
    for(int i = 1; i<=n;i++){
        if(cnt[i]>0){
            answer++;
        }
    }
    //5, [4, 2], [3, 5]
    
    return answer;
}
int main(){

    int n = 5;
    vector<int> lost = {4,2};
    vector<int> reserve = {3,5};
    int answer = solution(n,lost,reserve);
    cout << answer;
}