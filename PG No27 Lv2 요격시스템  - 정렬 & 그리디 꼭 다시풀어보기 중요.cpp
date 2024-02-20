#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(vector<int>a , vector<int>b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> targets) {
   
    int answer = 0;
    sort(targets.begin(),targets.end(),cmp);
    
    int end_point = -1;
    for(auto target : targets){
        if(target[0] >= end_point){
            end_point = target[1];
            answer++;
        }
    }



    return answer;
}

// 와 실수가 들어가네..... 양쪽 끝점에서는 요격이 안되는점이 포인트네
// 그냥 vector[n] 을 vector[n.5] 로 생각하면 풀 수 있을 것 같음.
// max 값 갱신 후 거기 쐇을때 어떻게 적용할지를 생각해야할거같은데 
// 정렬을 하는게 Point임.
// 이거를 끝점을 기준으로 오름차순 정리해놓고 제일 앞에 미사일 끝점을 End라고 한다면
// 그거 넘는 시작점 가지고 있는애는 추가로 한발 싸줘야 하는거네
// 그니까 end를 기준으로 오름차순 정렬후 요격미사일을 해당 미사일(일단 제일 짧은 놈이지.) 기준 범위로 잡아버리고 다음미사일 시작점이 이거 끝점 넘는지 보는거임.


int main(){
    vector<vector<int>> targets = {{4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4}};
    int answer = solution(targets);
    cout << answer;
    return 0;
}