#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    //큐 두개해서 DFS하면 될 것 같은데 그렇게 전체 탐색 하면 시간초과 분명히 날꺼임..
    //일단 큐 넣어야 하는건 맞는거같은데.
    //잘 이해는 안가지만 처음 생각했던 두큐중 큰놈이 작은놈 한테 주는 방식으로 푸는게 맞다고한다.. 안되는 반례가 분명히 있을텐데 이상하네..

    queue<int>q1;
    queue<int>q2;
    long long sum1 = 0 , sum2 = 0;
    for(int i = 0 ; i<queue1.size();i++){
        q1.push(queue1[i]);
        sum1 += queue1[i];
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    int cnt = 0 ;
    if((sum1+sum2)%2 != 0) return -1;
    // cnt -> 교환 횟수.
    while(cnt<4*(queue1.size())){
        //아래대로 적은놈 큐주고 큰놈 pop하다보면 무한루프가 발생하는데 cnt의 최대값(이상이면 아무리해도 합의 절반이 안나오는 경우)를 3n-3이라 하는데 그림을 봐도 사실 이해를 잘 못하겠음
        // 와 근데 이거 4로 해야 test pass함...
        if(sum1>sum2){
            q2.push(q1.front());
            sum1 -= q1.front();
            sum2 += q1.front();
            q1.pop();
            cnt++;

        }else if(sum1<sum2){
            q1.push(q2.front());
            sum2 -= q2.front();
            sum1 += q2.front();
            q2.pop();
            cnt++;
        }else{
            return cnt;
        }
    }

    return -1;
}

int main(){
    vector<int>queue1 = {3, 2, 7, 2};
    vector<int>queue2 = {4, 6, 5, 1};
    int answer = solution(queue1,queue2);
    cout << answer;
    return 0;
}