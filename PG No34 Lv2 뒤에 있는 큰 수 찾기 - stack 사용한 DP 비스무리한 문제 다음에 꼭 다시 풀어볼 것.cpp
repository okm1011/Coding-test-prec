#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    // 딱 생각해보면 2중 포문 돌리면 될거같은데 시간 복잡도 때문에 fail날꺼임
    /* 
    맨뒤에서 부터 시작 하고 Stack을 사용하면서 numbers에 있는 애들을 stack에 쌓아주면서 비교하면 됨.
    while
    스택에 numbers 맨뒤에것 삽입.
    for문 돌리면서 stack top과 numbers 비교 stack top이 크면 answer[i] = stack top
    아니면 stack pop

    매 스텝에 numbers stack에 삽입. 
    
    여기서 포인트는 어차피 다음 비교할게 stack top 보다 크면 그이전에 pop한애들은 중복으로 할 필요가 없음 어차피 stack top보다 작을테니까...
    이런생각은 대체 어떻게 하는거지


    */

    vector<int> answer(numbers.size());
    stack<int>st;
    st.push(numbers[numbers.size()-1]);
    //맨 마지막꺼 고정 -1 삽입.
    for(int i = numbers.size()-1;i>=0;i--){
        while(1){
            if(st.empty()){
                answer[i] = -1;
                break;
            }
            if(st.top() > numbers[i]){
                answer[i] = st.top();
                break;
            }
            st.pop();
        }
        st.push(numbers[i]);

    }

    return answer;
}

int main(){
    vector<int> numbers = {9, 1, 5, 3, 6, 2};
    vector<int> answer = solution(numbers);
    for(int i = 0; i<answer.size();i++){
        cout << answer[i] << " ";
    }
    return 0;
}