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
    
    // 기본적으로 pQ의 최상단에서 연산을하고 , 작업 switching 때만 stack을써보자. >> 와 이거 pQ.top()은 read only라서 그게 안되는데?
    // time past를쓰자.
    
    int first_time = pQ.top().start;
    
    Sub working_on = pQ.top();
    pQ.pop();
    //최상단 기본거 하나 처리 to working on
    for(int i = first_time + 1 ; i <= 1440 ; i++){ 
        
        if(pQ.empty() && st.empty()&&working_on.time <0 )break;
        working_on.time --;
        if(working_on.time == 0){
            answer.push_back(working_on.sub);
            if(pQ.empty() || pQ.top().start > i){
                // pQ가 비었거나 pQ top의 시간이 아직일때 stack 처리해야함.
                if(!st.empty()){
                    working_on = st.top();
                    st.pop();
                }

            }else{
                if(!pQ.empty()){
                    working_on = pQ.top();
                    pQ.pop();
                }
            }
        }else{
            if(pQ.top().start == i){
                    // working on time 아직 안끝났을때는 pQ상단 time 확인해 봐야함. 시간 겹치면 현재 working on stack으로 넘기고. pQ.top to working on
                    st.push(working_on);
                    working_on = pQ.top();
                    pQ.pop();
            }
        }

            


            
    }

        

    

    return answer;
}
int main(){
    vector<vector<string>>plans = 	{{"aaa", "12:00", "20"}, {"bbb", "12:10", "30"}, {"ccc", "12:40", "10"}};
    vector<string>answer = solution(plans);
    for(int i = 0 ; i < answer.size() ; i++){
        cout << answer[i] << " ";
    }
    return 0;
}