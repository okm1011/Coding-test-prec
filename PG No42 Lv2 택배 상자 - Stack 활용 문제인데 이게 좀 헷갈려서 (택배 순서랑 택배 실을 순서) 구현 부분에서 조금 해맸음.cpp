#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<int>order){
    int answer = 0;
    stack<int>st;
    // max count 갱신하면서 스택에 넣고 stack top 또는 order다음에 순서에 맞는 cnt면 answer++ 아니면 break;
    int cnt = 1;
    for(int i = 0 ; i<order.size();i++){
        // cnt , order[i]는 택배원이 받는 순서.
        // i는 택배 실을 순서
        if(cnt == order[i]){
            answer++;
            cnt++;
        }else if(cnt < order[i]){
            while(cnt < order[i]){
                st.push(cnt);
                cnt++;
            }
            cnt++;
            answer++;
        }else{
            //cnt > order[i]
            if(st.top()==order[i]){
                answer++;
                st.pop();
                
            }else{
                return answer;
            }
        }
           
    }
    

    return answer;
}

int main(){
    vector<int>order = {2, 1, 6, 7, 5, 8, 4, 9, 3, 10};
    int answer = solution(order);
    cout << answer;

    return 0;
}