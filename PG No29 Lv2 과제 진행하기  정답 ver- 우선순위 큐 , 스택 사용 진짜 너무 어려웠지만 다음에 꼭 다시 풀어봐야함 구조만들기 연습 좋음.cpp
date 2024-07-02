#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Sub{
public:
    string sub;
    int start;
    int time;
    Sub(string a, string b , string c){
        sub = a;
        b.erase(find(b.begin(),b.end(),':'));
        string tp_h;
        string tp_m;
        for(int i =0;i<4;i++){
            if(i<2){
                tp_h.push_back(b[i]);
            }else{
                tp_m.push_back(b[i]);
            }
        }
        start = 60*stoi(tp_h) + stoi(tp_m);
        // 시간 계산 편하게 분으로 통일시켜줌.
        time = stoi(c);
    }
    // 시간을 int 로 바꿔서 pQ에 시간순으로 정렬 저 erase find 구문 외울 것
    bool operator<(const Sub& b)const{
        return start>b.start;
    }
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<Sub>pQ;
    stack<Sub>st;
    for(int i = 0 ; i<plans.size();i++){
        pQ.push(Sub(plans[i][0],plans[i][1],plans[i][2]));
    }
    // 시작 시간순으로 정렬
    
    /*
    
    기본적인 알고리즘 . pQ에서 두개[1,2] 뽑아서 시간 비교 = diff 
    만약 diff가 1의 time보다 크거나 같다면 1을 answer에 넣고 stack이 차있으면 스택 작업 1time - diff만큼 진행.

    아니라면 1 time - diff 해서 1 time에 넣고 stack에 넣어놓음.
    
    pQ에 뽑을거 없다면 st 순서대로 answer에 추가
    */ 
    
    while(answer.size() != plans.size()){
        Sub temp1 = pQ.top();
        pQ.pop();
        // 마지막 작업은 그냥 바로 추가
        if(pQ.empty()){
            answer.push_back(temp1.sub);
            break;
        }
        Sub temp2 = pQ.top();

        int diff = temp2.start - temp1.start;
        //첫번째 diff >= temp1.time 크거나 같다 여야함 시간 딱 맞으면 바로 다음꺼 갈아버릴 수 있으니까
        if(diff >= temp1.time){
            answer.push_back(temp1.sub);
            int time_last = diff - temp1.time;  
            //남은 시간 동안 stack 털어줌 -- 남은시간 = 다음 start 이전까지 여유 시간.
            while(time_last > 0 && !st.empty()){
                st.top().time--;
                time_last--;
                if(st.top().time==0){
                    answer.push_back(st.top().sub);
                    st.pop();
                }
            }
        }else{ // diff < temp1.time
            temp1.time -= diff;
            st.push(temp1);
        }
    }
    //stack 남은거 털어줘야함
    while(!st.empty()){
        answer.push_back(st.top().sub);
        st.pop();
    }

    return answer;
}
int main(){
    vector<vector<string>>plans = 	{{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}};
    vector<string>answer = solution(plans);
    for(int i = 0 ; i < answer.size() ; i++){
        cout << answer[i] << " ";
    }
    return 0;
}